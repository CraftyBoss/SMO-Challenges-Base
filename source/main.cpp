#include <cmath>
#include <stdio.h>

#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"
#include "al/action/ActionEffectCtrl.h"
#include "al/sensor/SensorMsg.h"
#include "game/StageScene/StageScene.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "game/Player/PlayerFunction.h"
#include "game/Player/CapFunction.h"
#include "game/GameData/GameDataFunction.h"
#include "rs/util.hpp"

#include "sead/math/seadVector.h"
#include "sead/math/seadMatrix.h"
#include "sead/prim/seadSafeString.h"
#include "sead/resource/seadResourceMgr.h"
#include "sead/basis/seadNew.hpp"
#include "types.h"

#include "logger.hpp"
#include "TCPThread.hpp"

bool showMenu = false;
bool isInit = true;
static int deathCount = 0;

TCPThread *thread;

#define RAD(deg) (deg * (M_PI / 180))
#define DEG(rad) (rad * (180 / M_PI))
#define boolToChar(input) (input ? "True" : "False")

void stageInitHook(StageScene *stageScene, al::SceneInitInfo *sceneInitInfo) {
    __asm("MOV X19, X0");
    __asm("LDR X24, [X1, #0x18]");
    
    isInit = true;

    __asm("MOV X1, X24");
}

// this hook is VERY useful
sead::Resource *fileReadHook(sead::ResourceMgr *manager, sead::ResourceMgr::LoadArg const &loadArgs, sead::SafeStringBase<char> const &factoryName, sead::Decompressor *decompressor) {
    gLogger->LOG("Loading File at Path:\n%s\n", loadArgs.path.cstr());
    return manager->tryLoad(loadArgs, factoryName, decompressor);
}

ulong threadInit() { // hook for initializing any threads we need
    __asm("STR X21, [X19,#0x208]");

    thread = new TCPThread();

    thread->StartThread();

    return 0x20;
}

void stageSceneHook() {

    __asm ("MOV X19, X0");

    StageScene *stageScene;
    __asm ("MOV %[result], X0" : [result] "=r" (stageScene));

    al::PlayerHolder *pHolder = al::getScenePlayerHolder(stageScene);
    PlayerActorHakoniwa *player = al::tryGetPlayerActor(pHolder, 0); // rs::getPlayerActor(stageScene);
    al::LiveActor *curHack;

    if(player->mHackKeeper) {
        curHack = player->mHackKeeper->currentHackActor;
    }

    HackCap *pCap = player->mHackCap;
    sead::Vector3f *capScale = al::getScale(pCap);
    sead::Vector3f *playerTrans = al::getTrans(player);
    sead::Vector3f *pScale = al::getScale(player);
    al::CameraDirector *camDirector = player->getCameraDirector();
    al::Projection *curProjection = al::getProjection(player, 0);
    const char *pCurAct = player->mPlayerAnimator->mAnimFrameCtrl->getActionName();
    static bool isEnable = true;
    static bool hasCountedDeath = false;

    if(PlayerFunction::isPlayerDeadStatus(player)) {
        if(!hasCountedDeath) {
            deathCount++;
            hasCountedDeath = true;
        }
    }else {
        if(hasCountedDeath) {
            hasCountedDeath = false;
        }
    }

    if(al::isPadTriggerLeft(-1)  || (al::isPadHoldZL(-1) && al::isPadHoldLeft(-1))) {
        deathCount--;
        if(deathCount < 0) {
            deathCount = 9999;
        }
    }

    if(al::isPadTriggerRight(-1) || (al::isPadHoldZL(-1) && al::isPadHoldRight(-1))) {
        deathCount++;
        if(deathCount > 9999) {
            deathCount = 0;
        }
    }

    if(al::isPadTriggerUp(-1)) {
        
    }

    if(al::isPadTriggerUp(-1) && al::isPadHoldZL(-1)) {
        
    }

    if(isInit) {
        if((deathCount == 69 || deathCount == 420)) { 
            al::startSe(player, "AmiiboMario");
            PlayerFunction::tryActivateAmiiboPreventDamage(player);
            GameDataFunction::getLifeMaxUpItem(player);
            al::setPaneStringFormat(stageScene->stageSceneLayout->coinCounter, "TxtDebug", "Nice");
        }else {
            al::setPaneStringFormat(stageScene->stageSceneLayout->coinCounter, "TxtDebug", " ");
        }
        isInit = false;
    }

    al::setPaneStringFormat(stageScene->stageSceneLayout->coinCounter, "TxtDeath", "%04d", deathCount);

    __asm ("MOV X0, %[input]" : [input] "=r" (stageScene));
}

void seadPrintHook(const char *fmt, ...) 
{
    va_list args;
	va_start(args, fmt);

    gLogger->LOG(fmt, args);

    va_end(args);
}