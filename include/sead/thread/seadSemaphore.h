#pragma once

#include <nn/os.h>

#include "sead/heap/seadDisposer.h"

namespace sead
{
class Heap;

class Semaphore : public IDisposer
{
public:
    Semaphore();
    explicit Semaphore(s32 initial_count);
    Semaphore(s32 initial_count, s32 max_count);

    explicit Semaphore(Heap* heap);
    Semaphore(Heap* heap, s32 initial_count);
    Semaphore(Heap* heap, s32 initial_count, s32 max_count);

    Semaphore(Heap* heap, HeapNullOption heap_null_option);
    Semaphore(Heap* heap, HeapNullOption heap_null_option, s32 initial_count);
    Semaphore(Heap* heap, HeapNullOption heap_null_option, s32 initial_count, s32 max_count);

    ~Semaphore() override;

    Semaphore(const Semaphore&) = delete;
    Semaphore& operator=(const Semaphore&) = delete;

    void initialize(s32 initial_count) { initialize(initial_count, initial_count); }
    void initialize(s32 initial_count, s32 max_count);
    void lock();
    bool tryLock();
    void unlock();

    bool try_lock() { return tryLock(); }

private:
    void setInitialized([[maybe_unused]] bool initialized)
    {
#ifdef SEAD_DEBUG
        mInitialized = initialized;
#endif
    }
    
    nn::os::SemaphoreType mSemaphoreInner;

#ifdef SEAD_DEBUG
    bool mInitialized = false;
#endif
};
}  // namespace sead
