#pragma once

#include "SocketBase.hpp"
#include "privateIps.hpp"

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