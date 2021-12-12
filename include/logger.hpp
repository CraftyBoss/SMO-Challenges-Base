#pragma once

#include "SocketBase.hpp"
<<<<<<< HEAD
#include "privateIps.hpp"
=======
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2

class Logger;
extern Logger *gLogger;

<<<<<<< HEAD
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
=======
class Logger : public SocketBase {
    public:
        Logger(const char * ip, u16 port, const char *name) : SocketBase(ip, port, name) {this->init();};
        void init() override;
        void LOG(const char *fmt, ...);
        void LOG(const char *fmt, va_list args);
        int READ(char *out);
    private:
        
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2
};