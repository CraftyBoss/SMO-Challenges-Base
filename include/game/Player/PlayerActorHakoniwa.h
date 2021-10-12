#pragma once
/**
 * @file PlayerActorBase.h
 * @brief Main Class for the PlayerActor (Mario)
 * Player Pose: TQGMSV
*  Vtable loc: 1D780C0
*/

#include "PlayerActorBase.h"
#include "game/Interfaces/IUseDimension.h"
#include "PlayerInput.h"
#include "PlayerAnimator.h"
#include "HackCap.h"
#include "PlayerModelKeeper.h"
#include "PlayerColliderHakoniwa.h"
#include "PlayerConst.h"
#include "PlayerHackKeeper.h"

#define PACTORSIZE 0xC8

class PlayerActorHakoniwa : public PlayerActorBase , public IUseDimension {
    public: 
        int *getPortNo(void) const;
        PlayerHackKeeper *getPlayerHackKeeper() const;
        void attackSensor(al::HitSensor *target, al::HitSensor *source);
        unsigned char padding_E8[0xE8 - PACTORSIZE];
        int portNo; // 0xE8
        unsigned char padding_130[0x40];
        // 0x128 PlayerInfo
        PlayerConst *mPlayerConst; // 0x130
        PlayerInput *mPlayerInput; //0x138 
        unsigned char padding_148[0x8];
        HackCap *mHackCap; // 0x148
        unsigned char padding_158[0x6];
        PlayerModelKeeper *mPlayerModelKeeper; // 0x158
        unsigned char padding_168[0x8];
        PlayerAnimator *mPlayerAnimator; // 0x168 
        PlayerColliderHakoniwa *mPlayerCollider; // 0x170
        unsigned char padding_208[0x208 - 0x178];
        PlayerHackKeeper *mHackKeeper; // 0x208
};