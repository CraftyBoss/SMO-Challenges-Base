#include "logger.hpp"

Logger *gLogger;

void Logger::init()
{
    in_addr hostAddress = {0};
    sockaddr serverAddress = {0};

    if (this->socket_log_state != SOCKET_LOG_UNINITIALIZED)
        return;

    nn::nifm::Initialize();
    nn::nifm::SubmitNetworkRequest();

    while (nn::nifm::IsNetworkRequestOnHold())
    {
    }

    if (!nn::nifm::IsNetworkAvailable())
    {
        this->socket_log_state = SOCKET_LOG_UNAVAILABLE;
        return;
    }

    if ((this->socket_log_socket = nn::socket::Socket(2, 1, 0)) < 0)
    {
        this->socket_log_state = SOCKET_LOG_UNAVAILABLE;
        return;
    }

    nn::socket::InetAton(this->sock_ip, &hostAddress);

    serverAddress.address = hostAddress;
    serverAddress.port = nn::socket::InetHtons(this->port);
    serverAddress.family = 2;

    if (nn::socket::Connect(this->socket_log_socket, &serverAddress, sizeof(serverAddress)) != 0)
    {
        this->socket_log_state = SOCKET_LOG_UNAVAILABLE;
        return;
    }

    this->socket_log_state = SOCKET_LOG_CONNECTED;

    this->isDisableName = false;
}

void Logger::LOG(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    char buf[0x500];

    if (nn::util::VSNPrintf(buf, sizeof(buf), fmt, args) > 0)
    {
        if (!isDisableName)
        {
            char prefix[0x510];
            nn::util::SNPrintf(prefix, sizeof(prefix), "[%s] %s", this->sockName, buf);
            socket_log(prefix);
        }
        else
        {
            socket_log(buf);
        }
    }

    va_end(args);
}

void Logger::LOG(const char *fmt, va_list args)
{ // impl for replacing seads system::print
    char buf[0x500];
    if (nn::util::VSNPrintf(buf, sizeof(buf), fmt, args) > 0)
    {
        socket_log(buf);
    }
}

s32 Logger::READ(char *out)
{
    return this->socket_read_char(out);
}

bool Logger::pingSocket()
{
    return socket_log("ping") > 0; // if value is greater than zero, than the socket recieved our message, otherwise the connection was lost.
}

void tryInitSocket()
{
    __asm("STR X20, [X8,#0x18]");
    #ifdef SERVERIP
    gLogger = new Logger(TOSTRING(SERVERIP), 3080, "MainLogger");
    #else
    gLogger = new Logger(0, 3080, "MainLogger");
    #endif
}