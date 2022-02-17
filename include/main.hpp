#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"
#include "al/layout/LayoutActor.h"
#include "al/layout/LayoutKit.h"
#include "al/gamepad/util.h"
#include "al/camera/CameraPoser.h"
#include "al/camera/alCameraPoserFunction.h"
#include "al/factory/ProjectActorFactory.h"
#include "al/area/AreaObjGroup.h"

#include "game/StageScene/StageScene.h"
#include "game/Layouts/CoinCounter.h"
#include "game/Player/PlayerFunction.h"
#include "game/Player/PlayerCameraTarget.h"
#include "game/Player/PlayerAnimControlRun.h"
#include "game/Player/PlayerFactory.h"
#include "game/Player/PlayerCostumeInfo.h"
#include "game/Controller/ControllerAppletFunction.h"
#include "game/GameData/GameDataHolderWriter.h"
#include "game/GameData/GameDataFunction.h"
#include "game/Actors/Shine.h"
#include "game/HakoniwaSequence/HakoniwaSequence.h"

#include "actors/BombHei.hpp"

#include "rs/util.hpp"

#include "sead/math/seadVector.h"
#include "sead/math/seadMatrix.h"
#include "sead/prim/seadSafeString.h"
#include "sead/gfx/seadCamera.h"
#include "sead/basis/seadNew.hpp"
#include "sead/gfx/seadColor.h"
#include "types.h"

#include "agl/DrawContext.h"
#include "agl/RenderBuffer.h"
#include "agl/utl.h"

#include "helpers.hpp"
#include "logger.hpp"
#include "debugMenu.hpp"

#define RAD(deg) (deg * (M_PI / 180))        // converts Degrees to Radians
#define DEG(rad) (rad * (180 / M_PI))        // converts Radians to Degrees
#define BTOC(bool) (bool ? "True" : "False") // converts boolean to true/false char

#define TEMPPLAYERNAME "Crafty"

struct DebugWarpPoint
{
    char pointName[0x20] = {};
    sead::Vector3f warpPos = sead::Vector3f();
};