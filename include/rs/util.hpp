#pragma once

#include "sead/math/seadVector.h"
#include "al/util.hpp"
#include "al/sensor/SensorMsg.h"
#include "game/Player/PlayerActorHakoniwa.h"

namespace rs
{
    al::LiveActor* getPlayerActor(const al::Scene *);

    void get2DAreaPos(sead::Vector3<f32> *, al::AreaObj const *);

    bool isInChangeStageArea(PlayerActorHakoniwa const*, sead::Vector3f const *);

    bool isPlayerOnGround(const al::LiveActor *);

    void faceToCamera(al::LiveActor *actor);

    bool isPlayerActiveMarioAmiiboInvincible(al::LiveActor *);

    bool isMsgPlayerAndCapObjHipDropAll(al::SensorMsg const *);

    bool isMsgPlayerDamage(al::SensorMsg const *);
}
