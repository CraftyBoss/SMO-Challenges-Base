#pragma once

namespace al
{
    class LiveActor;

    class AreaObj {

    };

}

#include "sead/math/seadVector.h"
#include "sead/prim/seadSafeString.h"
#include "sead/heap/seadHeap.h"
#include "al/scene/Scene.h"
#include "al/PlayerHolder/PlayerHolder.h"
#include "al/audio/AudioKeeper.h"
#include "al/camera/Projection.h"
#include "al/layout/IUseLayout.h"
#include "al/sensor/SensorMsg.h"
#include "game/Player/PlayerActorHakoniwa.h"

#include "nn/ui2d/Texture.h"

#include "types.h"

namespace al
{

    // General Input functions

    bool isPadTriggerUp(int port);
    bool isPadTriggerDown(int port);
    bool isPadTriggerLeft(int port);
    bool isPadTriggerRight(int port);

    bool isPadTriggerA(int port);
    bool isPadTriggerB(int port);
    bool isPadTriggerX(int port);
    bool isPadTriggerY(int port);

    bool isPadTriggerZL(int port);
    bool isPadTriggerZR(int port);

    bool isPadTriggerL(int port);
    bool isPadTriggerR(int port);

    bool isPadHoldUp(int port);
    bool isPadHoldDown(int port);
    bool isPadHoldLeft(int port);
    bool isPadHoldRight(int port);

    bool isPadHoldA(int port);
    bool isPadHoldB(int port);
    bool isPadHoldX(int port);
    bool isPadHoldY(int port);

    bool isPadHoldL(int port);
    bool isPadHoldR(int port);

    bool isPadHoldZL(int port);
    bool isPadHoldZR(int port);

    sead::Vector2f *getLeftStick(int);
    sead::Vector2f *getRightStick(int);

    // getters
    
    sead::Vector3f *getTrans(al::LiveActor const *);

    sead::Vector3f *getTransPtr(al::LiveActor *);

    sead::Vector3f *getGravity(al::LiveActor const *);

    sead::Vector3f *getUp(al::LiveActor const *);

    sead::Vector3f *getUpPtr(al::LiveActor *);

    sead::Vector3f *getFront(al::LiveActor const *);

    sead::Vector3f *getCameraUp(al::IUseCamera const *, int);

    sead::Vector3f *getScale(al::LiveActor const *);

    float *getScaleX(al::LiveActor const *);

    float *getScaleY(al::LiveActor const *);

    float *getScaleZ(al::LiveActor const *);

    al::PlayerHolder *getScenePlayerHolder(al::Scene const *);

    PlayerActorHakoniwa *getPlayerActor(al::LiveActor const *, int);

    PlayerActorHakoniwa *tryGetPlayerActor(al::PlayerHolder const *, int);

    sead::Heap *getCurrentHeap(void);

    al::Projection *getProjection(al::IUseCamera const *, int);

    int getSubActorNum(al::LiveActor const *);

    al::LiveActor *getSubActor(al::LiveActor const *, int);

    sead::Vector3f *getVelocity(al::LiveActor const *);

    sead::Quatf *getQuat(al::LiveActor const *);

    int getPlayerControllerPort(int);

    char const *getActionName(al::LiveActor const *);

    char const *getActionFrame(al::LiveActor const *);

    sead::Vector2f getPaneLocalSize(al::IUseLayout *layout, const char *paneName);
    sead::Vector2f getPaneLocalScale(al::IUseLayout *layout, const char *paneName);
    sead::Vector2f getPaneLocalRotate(al::IUseLayout *layout, const char *paneName);

    // setters

    void setTransY(al::LiveActor *, float);

    void setTrans(al::LiveActor *, sead::Vector3f const &);

    void setScaleAll(al::LiveActor *, float);

    void setGravity(al::LiveActor const *, sead::Vector3f const &);

    void setFront(al::LiveActor *, sead::Vector3f const &);

    void setQuat(al::LiveActor *, const sead::Quatf &);

    void setPaneTexture(al::IUseLayout *, char const *, nn::ui2d::TextureInfo const *);

    //void setPaneString(al::IUseLayout *layout, char const *paneName, char16_t const *, ushort);

    void setPaneStringFormat(al::IUseLayout *layout, char const *paneName, char const *format,...);

    void setPaneLocalTrans(al::IUseLayout *layout, const char *paneName, sead::Vector3f const &);
    void setPaneLocalTrans(al::IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalSize(al::IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalScale(al::IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalRotate(al::IUseLayout *layout, const char *paneName, sead::Vector3f const &);

    void setVelocityZero(al::LiveActor *);

    void setEffectParticleScale(al::IUseEffectKeeper *actor, char const *effectName, float scale);

    // calc functions

    f32 calcDistance(al::LiveActor const *, al::LiveActor const*); // calculates distance between two actors

    f32 calcDistance(al::LiveActor const *, sead::Vector3f const&); // calculates distance between an actor and a position in the world

    // velocity stuff

    void addVelocity(al::LiveActor *,sead::Vector3f const&);

    void setVelocity(al::LiveActor *,sead::Vector3f const&);

    void scaleVelocityExceptDirection(al::LiveActor *,sead::Vector3f const&, float);

    void addVelocityToGravity(al::LiveActor *, float);

    // byml stuff

    bool tryGetByamlF32(float *, al::ByamlIter const&, char const*);

    f32 findActorParamF32(al::LiveActor const*,char const*);
    s32 findActorParamS32(al::LiveActor const*,char const*);

    // nerve stuff

    bool isLessStep(al::IUseNerve const*,int); // checks if the current nerve has been activated for a certain amount of time(?)

    // effect stuff

    void emitEffect(al::IUseEffectKeeper *effectKeeper, char const *effectName, sead::Vector3f const *effectPosition);
    
    bool tryEmitEffect(al::IUseEffectKeeper *effectKeeper, char const *effectName, sead::Vector3f const *effectPosition);

    void tryDeleteEffect(al::IUseEffectKeeper *effectKeeper, char const *effectName);

    // sensor stuff

    // enum SensorType {
    //     Unknown, // 0
    //     Player, // 1
    //     PlayerAttack, // 2
    //     PlayerFoot // 3
    // };
    
    void addHitSensor(al::LiveActor *actor, al::ActorInitInfo const &initInfo, char const *sensorName, uint typeEnum, float radius, ushort maxCount, sead::Vector3f const& position);

    bool isMsgPlayerTrampleReflect(al::SensorMsg const *);

    bool isSensorPlayerAttack(al::HitSensor const *targetSensor);

    bool sendMsgPlayerHipDropKnockDown(al::HitSensor *target, al::HitSensor *source);

    // misc
    void tryGetObjectName(const char **, al::ActorInitInfo const &);


    bool isInAreaObj(al::LiveActor const *, const char *);

    al::AreaObj *tryFindAreaObj(al::LiveActor const *, const char *);

    void tryGetAreaObjArg(int *, al::AreaObj const *, const char *);
    void tryGetAreaObjArg(float *, al::AreaObj const *, const char *);
    void tryGetAreaObjArg(bool *, al::AreaObj const *, const char *);

    void tryGetAreaObjStringArg(const char **, al::AreaObj const *, const char *);

    void offCollide(al::LiveActor *);
    void onCollide(al::LiveActor *);

    void startAction(al::LiveActor *, char const *);

    bool tryStartSe(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);

    void startSe(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);

    void startHitReaction(al::LiveActor const *, char const*);

    bool isInDeathArea(al::LiveActor const *);

    void calcCameraUpDir(sead::Vector3f *, al::IUseCamera const*, int);

    const unsigned char *tryGetBymlFromArcName(sead::SafeStringBase<char> const &, sead::SafeStringBase<char> const &);

    class ActorInitInfo;

    bool getArg(int *, const al::ActorInitInfo &, const char *);

    bool isActiveDemo(const al::Scene *);

    bool isEqualString(char const *, char const *);

    bool isOnGround(al::LiveActor const*, uint);

    // dither anim stuff

    bool isExistDitherAnimator(al::LiveActor const *);

    void stopDitherAnimAutoCtrl(al::LiveActor *);
    void restartDitherAnimAutoCtrl(al::LiveActor *);

    void validateDitherAnim(al::LiveActor *);
    void invalidateDitherAnim(al::LiveActor *);

    float getDitherAnimNearClipStartDistance(al::LiveActor const *);
    float getDitherAnimNearClipEndDistance(al::LiveActor const *);

    void setDitherAnimSphereRadius(al::LiveActor *, float);
    void setDitherAnimBoundingBox(al::LiveActor *, sead::Vector3f const&);
    void setDitherAnimMaxAlpha(al::LiveActor *, float);
    void setDitherAnimClippingJudgeLocalOffset(al::LiveActor *, sead::Vector3f const&);
    void setDitherAnimClippingJudgeParam(al::LiveActor *, const char *);

}
