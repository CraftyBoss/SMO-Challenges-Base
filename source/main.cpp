<<<<<<< HEAD
#include "main.hpp"

static bool showMenu = false;

static bool isInGame = false;

DebugWarpPoint warpPoints[40];

int listCount = 0;

int curWarpPoint = 0;

void drawBackground(agl::DrawContext *context)
{

    sead::Vector3<float> p1; // top left
    p1.x = -1.0;
    p1.y = 0.3;
    p1.z = 0.0;
    sead::Vector3<float> p2; // top right
    p2.x = -0.2;
    p2.y = 0.3;
    p2.z = 0.0;
    sead::Vector3<float> p3; // bottom left
    p3.x = -1.0;
    p3.y = -1.0;
    p3.z = 0.0;
    sead::Vector3<float> p4; // bottom right
    p4.x = -0.2;
    p4.y = -1.0;
    p4.z = 0.0;

    sead::Color4f c;
    c.r = 0.1;
    c.g = 0.1;
    c.b = 0.1;
    c.a = 0.9;

    agl::utl::DevTools::beginDrawImm(context, sead::Matrix34<float>::ident, sead::Matrix44<float>::ident);
    agl::utl::DevTools::drawTriangleImm(context, p1, p2, p3, c);
    agl::utl::DevTools::drawTriangleImm(context, p3, p4, p2, c);
}

// ------------- Hooks -------------

al::StageInfo *initDebugListHook(const al::Scene *curScene)
{

    // hook that gets all objects put in DebugList and adds their coordinates to a warp point array

    al::StageInfo *info = al::getStageInfoMap(curScene, 0);

    al::PlacementInfo rootInfo = al::PlacementInfo();

    al::tryGetPlacementInfoAndCount(&rootInfo, &listCount, info, "DebugList");

    if (listCount > 0)
    {
        for (size_t i = 0; i < listCount; i++)
        {
            al::PlacementInfo objInfo = al::PlacementInfo();

            al::getPlacementInfoByIndex(&objInfo, rootInfo, i);

            const char *displayName = "";
            al::tryGetDisplayName(&displayName, objInfo);

            strcpy(warpPoints[i].pointName, displayName);

            al::tryGetTrans(&warpPoints[i].warpPos, objInfo);
        }
    }

    return info;
}

void drawMainHook(HakoniwaSequence *curSequence, sead::Viewport *viewport, sead::DrawContext *drawContext)
{
=======
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
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2

    if (!showMenu)
    {
        al::executeDraw(curSequence->mLytKit, "２Ｄバック（メイン画面）");
        return;
    }

    int dispWidth = al::getLayoutDisplayWidth();
    int dispHeight = al::getLayoutDisplayHeight();

<<<<<<< HEAD
    gTextWriter->mViewport = viewport;

    gTextWriter->mColor = sead::Color4f(
        1.f,
        1.f,
        1.f,
        0.8f);

    al::Scene *curScene = curSequence->curScene;

    if (curScene && isInGame)
    {

        drawBackground((agl::DrawContext *)drawContext);

        gTextWriter->beginDraw();

        gTextWriter->setCursorFromTopLeft(sead::Vector2f(10.f, (dispHeight / 3) + 30.f));

        gTextWriter->setScaleFromFontHeight(20.f);
=======
    al::PlayerHolder *pHolder = al::getScenePlayerHolder(stageScene);
    PlayerActorHakoniwa *player = al::tryGetPlayerActor(pHolder, 0); // rs::getPlayerActor(stageScene);
    al::LiveActor *curHack;
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2

        gTextWriter->printf("Total Warp Points: %d\n", listCount);
        gTextWriter->printf("Current Warp Index: %d\n", curWarpPoint);
        gTextWriter->printf("Current Warp Name: %s\n", warpPoints[curWarpPoint].pointName);
        gTextWriter->printf("Current Warp Position:\nX: %f\nY: %f\nZ: %f\n", warpPoints[curWarpPoint].warpPos.x, warpPoints[curWarpPoint].warpPos.y, warpPoints[curWarpPoint].warpPos.z);

        isInGame = false;
    }

<<<<<<< HEAD
    gTextWriter->endDraw();

    al::executeDraw(curSequence->mLytKit, "２Ｄバック（メイン画面）");
}

void stageInitHook(StageScene *initStageScene, al::SceneInitInfo *sceneInitInfo)
{
    __asm("MOV X19, X0");
    __asm("LDR X24, [X1, #0x18]");

    // place any code that needs to be ran during init here (creating actors for example)

    __asm("MOV X1, X24");
}

ulong threadInit()
{ // hook for initializing any threads we need
    __asm("STR X21, [X19,#0x208]");

    return 0x20;
}

void stageSceneHook()
{
=======
    HackCap *pCap = player->mHackCap;
    sead::Vector3f *capScale = al::getScale(pCap);
    sead::Vector3f *playerTrans = al::getTrans(player);
    sead::Vector3f *pScale = al::getScale(player);
    al::CameraDirector *camDirector = player->getCameraDirector();
    al::Projection *curProjection = al::getProjection(player, 0);
    const char *pCurAct = player->mPlayerAnimator->mAnimFrameCtrl->getActionName();
    static bool isEnable = true;
    static bool hasCountedDeath = false;
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2

    __asm("MOV X19, X0");

    StageScene *stageScene;
    __asm("MOV %[result], X0"
          : [result] "=r"(stageScene));

    al::PlayerHolder *pHolder = al::getScenePlayerHolder(stageScene);
    PlayerActorHakoniwa *p1 = al::tryGetPlayerActor(pHolder, 0);

    if (!isInGame)
    {
        isInGame = true;
    }

    if (al::isPadTriggerLeft(-1)) // teleport to stage example
    {
        ChangeStageInfo info = ChangeStageInfo(stageScene->mHolder, "Ex", "CapWorldHomeStage", false, 1, ChangeStageInfo::SubScenarioType::UNK);

        gLogger->LOG("Change Stage ID: %s\n", info.changeStageId.cstr());
        gLogger->LOG("Change Stage Name: %s\n", info.changeStageName.cstr());
        gLogger->LOG("Scenario No: %d\n", info.scenarioNo);
        gLogger->LOG("Wipe Type: %s\n", info.wipeType.cstr());

        stageScene->mHolder->changeNextStage(&info, 0);
    }

<<<<<<< HEAD
    if (al::isPadTriggerUp(-1)) // enables/disables debug menu
    {
        showMenu = !showMenu;
    }
=======
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
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2

    __asm("MOV X0, %[input]"
          : [input] "=r"(stageScene));
}

<<<<<<< HEAD
void seadPrintHook(const char *fmt, ...) // hook for replacing sead::system::print with our custom logger
{
    va_list args;
    va_start(args, fmt);
=======
void seadPrintHook(const char *fmt, ...) 
{
    va_list args;
	va_start(args, fmt);
>>>>>>> d9f97d1785079d0fc96363d314c2b13c6bd6c5f2

    gLogger->LOG(fmt, args);

    va_end(args);
}