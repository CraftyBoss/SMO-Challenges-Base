#pragma once

#include <string>
#include <cstring>
#include "types.h"
#include "nn.h"
<<<<<<< HEAD
#include "sead/basis/seadNew.hpp"
=======
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2

class SocketBase {

    public:
        SocketBase(const char * ip, u16 port, const char *name);

        virtual void init() = 0;

        const char *getStateChar();
        u8 getLogState();
        s32 getSocket();

        void set_sock_flags(int flags);

        void closeSocket();

    protected:
<<<<<<< HEAD
        s32 socket_log(const char* str);
        s32 socket_read_char(char *out);

        const char *sockName;
        const char *sock_ip;

        u16 port;
        u8 socket_log_state;
        s32 socket_log_socket;
        
=======
        void socket_log(const char* str);
        s32 socket_read_char(char *out);
        const char *sockName;
        const char *sock_ip;
        u16 port;
        u8 socket_log_state;
        s32 socket_log_socket;
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2
        int sock_flags;
};



