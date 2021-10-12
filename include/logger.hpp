#pragma once

#include <string>
#include <cstring>
#include "types.h"
#include "nn.h"
#include "log.h"

enum SocketLogState
{
    SOCKET_LOG_UNINITIALIZED    = 0,
    SOCKET_LOG_CONNECTED        = 1,
    SOCKET_LOG_UNAVAILABLE      = 2
};

int getLogState();

void socket_log(const char* str);

s32 socket_read_char(char *out);

void socket_log_initialize();

void tryInitSocket();