#pragma once

#include "al/area/AreaObjDirector.h"
#include "al/camera/CameraDirector.h"
#include "al/collision/CollisionDirector.h"
#include "al/scene/SceneObjHolder.h"

namespace al
{
    class ActorSceneInfo
    {
    public:
        al::AreaObjDirector *mAreaObjDirector;     // 0x0
        al::CameraDirector *mCameraDirector;       // 0x8
        void *unk1;                                // 0x10
        al::CollisionDirector *mCollisionDirector; // 0x18
        unsigned char padding[0x40];               // 0x20-0x58
        al::SceneObjHolder *mSceneObjHolder;       // 0x60
    };
} // namespace al
