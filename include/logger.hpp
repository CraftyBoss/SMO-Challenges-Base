#pragma once

#include "SocketBase.hpp"

// used to convert server IP macro to string
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

class Logger;
extern Logger *gLogger;

class Logger : public SocketBase
{
public:
    Logger(const char *ip, u16 port, const char *name) : SocketBase(ip, port, name) { this->init(); };
    void init() override;
    void LOG(const char *fmt, ...);
    void LOG(const char *fmt, va_list args);
    int READ(char *out);
    bool pingSocket();
    bool isDisableName;

private:
};