#pragma once
/**
 * @file HackCap.h
 * @brief Main Class for HackCap (Cappy)
* Vtable loc: 1D75520
*/

#include "al/LiveActor/LiveActor.h"
#include "HackCapThrowParam.h"

#define HACKSIZE sizeof(al::LiveActor)

class HackCap : public al::LiveActor {
    public: 

        void calcReturnTargetPos(sead::Vector3f *);

        void hide(bool);
        void forcePutOn(void);

        bool isFlying(void) const;

        unsigned char padding_118[0x118 - HACKSIZE];
        al::LiveActor *mActorA; // 0x118
        unsigned char padding_8[0x8];
        al::LiveActor *mPlayerActor; // 0x128
        unsigned char padding_220[0x220-0x130];
        HackCapThrowParam throwParam; // 0x220
};