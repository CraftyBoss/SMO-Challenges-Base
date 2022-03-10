#pragma once

#include "al/area/AreaObjGroup.h"
#include "al/camera/CameraTargetBase.h"
#include "al/layout/LayoutActor.h"
#include "al/layout/LayoutKit.h"

#include "sead/math/seadVector.h"
#include "sead/prim/seadSafeString.h"
#include "sead/heap/seadHeap.h"
#include "sead/basis/seadNew.hpp"
#include "sead/gfx/seadContext.h"
#include "sead/framework/seadFramework.h"

#include "agl/DrawContext.h"

#include "nn/ui2d/Texture.h"

#include "types.h"

// #include "util/ArchiveUtil.h"
#include "util/ByamlUtil.h"
#include "util/CameraUtil.h"
#include "util/InputUtil.h"
#include "util/LiveActorUtil.h"
#include "util/MathUtil.h"
#include "util/NerveUtil.h"
#include "util/OtherUtil.h"
#include "util/PlacementUtil.h"
#include "util/RandomUtil.h"
// #include "util/ResourceUtil.h"
#include "util/SceneUtil.h"
#include "util/SensorUtil.h"
#include "util/StringUtil.h"
#include "util/VectorUtil.h"

namespace al
{

    // getters

    int getActionFrameMax(LiveActor const *);

    // setters

    void setEffectParticleScale(IUseEffectKeeper *actor, char const *effectName, float scale);

    // layout stuff

    void setPaneTexture(IUseLayout *, char const *, nn::ui2d::TextureInfo const *);

    //void setPaneString(IUseLayout *layout, char const *paneName, char16_t const *, ushort);

    void setPaneStringFormat(IUseLayout *layout, char const *paneName, char const *format, ...);

    void setPaneLocalTrans(IUseLayout *layout, const char *paneName, sead::Vector3f const &);
    void setPaneLocalTrans(IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalSize(IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalScale(IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalRotate(IUseLayout *layout, const char *paneName, sead::Vector3f const &);

    sead::Vector2f getPaneLocalTrans(IUseLayout *layout, const char *paneName);
    sead::Vector2f getPaneLocalSize(IUseLayout *layout, const char *paneName);
    sead::Vector2f getPaneLocalScale(IUseLayout *layout, const char *paneName);
    sead::Vector2f getPaneLocalRotate(IUseLayout *layout, const char *paneName);

    bool killLayoutIfActive(LayoutActor *);

    void hidePane(IUseLayout *lyt, const char *paneName);

    bool isHidePane(IUseLayout const *lyt, const char *paneName);

    void showPane(IUseLayout *lyt, const char *paneName);

    // camera stuff

    void setCameraTarget(IUseCamera *, CameraTargetBase *);

    // calc functions

    f32 calcDistance(LiveActor const *, LiveActor const *); // calculates distance between two actors

    f32 calcDistance(LiveActor const *, sead::Vector3f const &); // calculates distance between an actor and a position in the world

    void calcFrontDir(sead::Vector3f *result, LiveActor const *actor);

    // animation stuff

    const char *getPlayingSklAnimName(const LiveActor *actor, int index);

    bool tryStartSklAnimIfNotPlaying(LiveActor *actor, const char *animName);

    bool tryStartSklAnimIfExist(LiveActor *actor, const char *animName);

    // byml stuff

    f32 findActorParamF32(LiveActor const *, char const *);
    s32 findActorParamS32(LiveActor const *, char const *);

    // effect stuff

    void emitEffect(IUseEffectKeeper *effectKeeper, char const *effectName, sead::Vector3f const *effectPosition);

    void tryDeleteEffect(IUseEffectKeeper *effectKeeper, char const *effectName);

    // sensor stuff

    enum SensorType : uint {
        Unknown, // 0
        Player, // 1
        PlayerAttack, // 2
        PlayerFoot // 3
    };

    void addHitSensor(LiveActor *actor, ActorInitInfo const &initInfo, char const *sensorName, uint typeEnum, float radius, ushort maxCount, sead::Vector3f const &position);

    // audio

    void tryPauseBgmIfLowPriority(IUseAudioKeeper const *keeper, const char *audioName, int unk);

    // player stuff

    void getClassName(const char **namePtr, const ActorInitInfo &info);

    void getDisplayName(const char **namePtr, const ActorInitInfo &info);

    // stage switch stuff

    // stage init stuff

    StageInfo *getStageInfoMap(Scene const *, int);

    // misc

    AreaObjGroup *tryFindAreaObjGroup(IUseAreaObj const *, const char *areaName);

    sead::DrawContext *getSceneDrawContext(Scene const *); // these two things are all thats needed to setup text writer in the right context

    sead::LogicalFrameBuffer *getSceneFrameBufferMain(Scene const *);

    int getLayoutDisplayWidth();
    int getLayoutDisplayHeight();

    void executeDraw(LayoutKit const *, char const *);

    bool isExistFile(sead::SafeString const &filePath);

    bool isVisAnimExist(const LiveActor *, const char *);

    bool isInWaterPos(LiveActor const *, sead::Vector3f const &);

    // interpolation functions

    void lerpVec(sead::Vector3f *result, sead::Vector3f const &from, sead::Vector3f const &to, float rate);

    void slerpQuat(sead::Quatf *result, sead::Quatf const &from, sead::Quatf const &to, float rate);

    // dither anim stuff

    bool isExistDitherAnimator(LiveActor const *);

    void stopDitherAnimAutoCtrl(LiveActor *);
    void restartDitherAnimAutoCtrl(LiveActor *);

    void validateDitherAnim(LiveActor *);
    void invalidateDitherAnim(LiveActor *);

    float getDitherAnimNearClipStartDistance(LiveActor const *);
    float getDitherAnimNearClipEndDistance(LiveActor const *);

    void setDitherAnimSphereRadius(LiveActor *, float);
    void setDitherAnimBoundingBox(LiveActor *, sead::Vector3f const &);
    void setDitherAnimMaxAlpha(LiveActor *, float);
    void setDitherAnimClippingJudgeLocalOffset(LiveActor *, sead::Vector3f const &);
    void setDitherAnimClippingJudgeParam(LiveActor *, const char *);

}
