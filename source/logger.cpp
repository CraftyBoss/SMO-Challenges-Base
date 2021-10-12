#include "logger.hpp"

#define HOST_IP          "10.0.0.224" // My IP:  //Smant IP: "192.168.0.62"
#define PORT             (u16)1337

#define	MSG_DONTWAIT	 0x00000080

// ---------------------------- Socket Setup

u8 socket_log_state = SOCKET_LOG_UNINITIALIZED;
s32 socket_log_socket = -1;
u8 socket_data_pool[0x600000+0x20000] __attribute__((aligned(0x1000)));

void socket_log(const char* str)
{
    if (socket_log_state != SOCKET_LOG_CONNECTED)
        return;

    nn::socket::Send(socket_log_socket, str, strlen(str), 0);
}

s32 socket_read_char(char *out) {

    int totalLength = 0;

    if (socket_log_state != SOCKET_LOG_CONNECTED)
        return totalLength;

    char buf[1024];

    int valread;
    while (true)
    {
        valread = nn::socket::Recv(socket_log_socket, buf, strlen(buf), MSG_DONTWAIT);

        if(valread <= 0) {
            break;
        }else {

            strncat(out, buf, valread);

            totalLength += valread;
        }
    }

    return totalLength;
    
}

void socket_log_initialize()
{
    in_addr hostAddress = { 0 };
    sockaddr serverAddress = { 0 };

    if (socket_log_state != SOCKET_LOG_UNINITIALIZED)
        return;

    nn::nifm::Initialize();
    nn::nifm::SubmitNetworkRequest();

    while (nn::nifm::IsNetworkRequestOnHold()) { }

    if (!nn::nifm::IsNetworkAvailable()) {
        socket_log_state = SOCKET_LOG_UNAVAILABLE;
        return;
    }
    
    //nn::socket::Initialize(socket_data_pool, 0x600000, 0x20000, 14);

    if ((socket_log_socket = nn::socket::Socket(2, 1, 0)) < 0) {
        socket_log_state = SOCKET_LOG_UNAVAILABLE;
        return;
    }
    
    nn::socket::InetAton(HOST_IP, &hostAddress);

    serverAddress.address = hostAddress;
    serverAddress.port = nn::socket::InetHtons(PORT);
    serverAddress.family = 2;

    if (nn::socket::Connect(socket_log_socket, &serverAddress, sizeof(serverAddress)) != 0) {
        socket_log_state = SOCKET_LOG_UNAVAILABLE;
        return;
    }
    
    socket_log_state = SOCKET_LOG_CONNECTED;

    LOG("Connected!\n");

    return;
}

void tryInitSocket() {
    __asm("MOV X20, X0");
    socket_log_initialize();
}
