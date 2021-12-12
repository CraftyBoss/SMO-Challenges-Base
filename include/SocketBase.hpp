#pragma once

#include <string>
#include <cstring>
#include "types.h"
#include "nn.h"
#include "sead/basis/seadNew.hpp"

class SocketBase
{

public:
        SocketBase(const char *ip, u16 port, const char *name);

        virtual void init() = 0;

        const char *getStateChar();
        u8 getLogState();
        s32 getSocket();

        void set_sock_flags(int flags);

        void closeSocket();

protected:
        s32 socket_log(const char *str);
        s32 socket_read_char(char *out);

        const char *sockName;
        const char *sock_ip;

        u16 port;
        u8 socket_log_state;
        s32 socket_log_socket;

        int sock_flags;
};
