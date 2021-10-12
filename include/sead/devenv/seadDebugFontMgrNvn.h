#pragma once

#include <sead/heap/seadHeap.h>

namespace sead {
    class DebugFontMgrNvn {
        public:
            DebugFontMgrNvn(void);
            struct sInstance {};

            void initialize(sead::Heap *, const char *, const char*, bool);
            sead::DebugFontMgrNvn::sInstance createInstance(sead::Heap *);
            
    };
}