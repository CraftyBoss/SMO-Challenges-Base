#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nnosMutexType {
    u8 curState;            // _0
    bool isRecursiveMutex;  // _1
    s32 lockLevel;          // _2
    u8 _6[0x20 - 0xE];
} nnosMutexType;

namespace nn { namespace os { 
    namespace detail {
        class InternalCriticalSection {
            u32 Image;
        };

        class InternalConditionVariable {
            u32 Image;
        };
    }  // namespace detail
    struct TlsSlot {
        u32 slot;
    };
    struct MessageQueueType {
        u64 _x0;
        u64 _x8;
        u64 _x10;
        u64 _x18;
        void* Buffer;
        u32 MaxCount;
        u32 Count;
        u32 Offset;
        bool Initialized;
        detail::InternalCriticalSection _x38;
        detail::InternalConditionVariable _x3C;
        detail::InternalConditionVariable _x40;
    };
    Result AllocateTlsSlot(TlsSlot* slot_out, void (*)(u64));
    void FreeTlsSlot(TlsSlot slot);
    u64 GetTlsValue(TlsSlot slot);
    void SetTlsValue(TlsSlot slot, u64 value);
    u32 GetCurrentCoreNumber();
}}

void nnosInitializeMutex(nnosMutexType*, bool, s32);
void nnosFinalizeMutex(nnosMutexType*);
void nnosLockMutex(nnosMutexType*);
bool nnosTryLockMutex(nnosMutexType*);
void nnosUnlockMutex(nnosMutexType*);

long long int llabs(long long int n);

#ifdef __cplusplus
}
#endif