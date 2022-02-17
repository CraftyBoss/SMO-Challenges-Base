#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/async/FunctorV0M.hpp"
#include "al/physics/ExternalForceKeeper.h"
#include "al/states/EnemyStateWander.h"
#include "al/util/LiveActorUtil.h"
#include "al/util/NerveUtil.h"
#include "al/util/SensorUtil.h"
#include "rs/util/SensorUtil.h"
#include "al/util/MathUtil.h"
#include "game/Player/PlayerActorHakoniwa.h"

#include <sead/basis/seadTypes.h>
#include <sead/container/seadPtrArray.h>
#include <sead/heap/seadHeap.h>
#include <sead/math/seadVector.h>

#include "logger.hpp"

namespace ca {

    class BombHei;
    extern BombHei *bombInstance;

    class BombHei : public al::LiveActor {
    public:
        BombHei(char const* name);
        virtual void init(al::ActorInitInfo const& info);
        void listenAppear();
        virtual bool receiveMsg(const al::SensorMsg* message, al::HitSensor* source, al::HitSensor* target);
        virtual void attackSensor(al::HitSensor* source, al::HitSensor* target);
        virtual void control();
        virtual void updateCollider();

        void updateVelocity();

        void exeWait(void);
        void exeWander(void);
        void exeTurn(void);
        void exeFind(void);
        void exeChase(void);
        void exeFall(void);
        void exeLand(void);
        void exeAttack(void);
        void exeCapHit(void);
        void exeBlowDown(void);
        void exeExplode(void);

        ExternalForceKeeper* forceKeeper = nullptr;          // 0x108
        EnemyStateWander* state = nullptr;                   // 0x110
        sead::Vector3f capPos = sead::Vector3f::zero;        // 0x118
        int capHitCooldown = 0;                              // 0x124
        int airTime = 0;                                     // 0x128
        sead::Vector3f futurePos = sead::Vector3f::zero;     // 0x12C
        sead::Vector3f groundNormal = sead::Vector3f::zero;  // 0x138
        unsigned int unkInt = 0;                             // 0x144
        int explodeTimer = 0;                                // 0x148
    };

    namespace {
    NERVE_HEADER(BombHei, Wait)
    NERVE_HEADER(BombHei, Wander)
    NERVE_HEADER(BombHei, Turn)
    NERVE_HEADER(BombHei, Find)
    NERVE_HEADER(BombHei, Chase)
    NERVE_HEADER(BombHei, Fall)
    NERVE_HEADER(BombHei, Land)
    NERVE_HEADER(BombHei, Attack)
    NERVE_HEADER(BombHei, CapHit)
    NERVE_HEADER(BombHei, BlowDown)
    NERVE_HEADER(BombHei, Explode)
    }  // namespace
}


