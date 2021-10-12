/**
 * @file context.h
 * @brief Basic draw context implementation.
 */

#pragma once

#include <sead/thread/seadCriticalSection.h>
#include <sead/heap/seadHeap.h>
#include <sead/hostio/seadHostIONode.h>
#include "types.h"

namespace sead
{
    class DrawContext
    {
    public:
        DrawContext();
        virtual ~DrawContext();

        u32 _8;
        u32 DrawContext_xC;
        u64 _10;
        u8 _18[0xC0-0x18];
        u64 _C0;
        u64 _C8;
        u64 _D0;
        u64 _D8;
        u64 _E0;
        u64 _E8;
    };

    class DrawLockContext : public sead::hostio::Node
    {
    public:
        DrawLockContext();

        void initialize(sead::Heap *);
        void lock();
        void unlock();
        void genMessage(sead::hostio::Context *);

        u32 _8;
        u32 DrawLockContext_xC;
        sead::CriticalSection mContextSection; // _10
    };
};