#include "TCPThread.hpp"

TCPThread::TCPThread() {
    this->thread = new al::AsyncFunctorThread("TCPThread", al::FunctorV0M<typeof(this), typeof(&TCPThread::threadFunc)>(this, &TCPThread::threadFunc), 0, 0x10000, {0});
    this->tLogger = new Logger("192.168.1.75", 1337, "TCPThread");
}

bool TCPThread::StartThread() {
    if(this->thread->isDone()) {
        this->thread->start();
        this->tLogger->LOG("Thread Sucessfully Started.\n");
        return true;
    }else {
        this->tLogger->LOG("Thread has already started! Or other unknown reason.\n");
        return false;
    }
}

void TCPThread::threadFunc() {
    while(true) {
        nn::os::YieldThread(); // allow other threads to run
        nn::os::SleepThread(nn::TimeSpan::FromNanoSeconds(100000000)); // might have to make this less time if too slow
    }
}