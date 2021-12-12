#pragma once

#include "al/async/AsyncFunctorThread.h"
#include "al/async/FunctorV0M.hpp"
#include "logger.hpp"

class TCPThread {
    public:
        TCPThread();
        bool StartThread();
        void threadFunc();
        bool isDone() {return thread->isDone();};
    private:
        al::AsyncFunctorThread *thread;
        Logger *tLogger;
};