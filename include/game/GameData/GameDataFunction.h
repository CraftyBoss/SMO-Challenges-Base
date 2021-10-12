/**
 * @file GameDataFunction.h
 * @brief Holds static functions for getting / storage save data.
 */

#pragma once

#include <al/LiveActor/LiveActor.h>
#include "GameDataHolderAccessor.h"
#include "GameDataHolderWriter.h"

class GameDataFunction
{
public:
    // gets current save file's current world id
    static s32 getCurrentWorldId(GameDataHolderAccessor);

    static char* getCurrentStageName(GameDataHolderAccessor);

    static s32 getCurrentShineNum(GameDataHolderAccessor);

    // gets total moons collected on a specified save file (-1 for current save)
    static s32 getTotalShineNum(GameDataHolderAccessor, int);

    // gets the total amount of moons available in a kingdom
    static s32 getWorldTotalShineNum(GameDataHolderAccessor, int); 

    // checks save file if shine is collected in kingdom index
    static bool isGotShine(GameDataHolderAccessor, int, int);

    // checks save file if shine is collected by shine index only (0 through 725)
    static bool isGotShine(GameDataHolderAccessor, int);

    // Gets Index for X Kingdom
    static s32 getWorldIndexWaterfall(void);
    static s32 getWorldIndexMoon(void);

    // gets the current level of the Odyssey
    static int getHomeLevel(GameDataHolderAccessor);
    
    // checks if cappy is enabled
    static bool isEnableCap(GameDataHolderAccessor);
    // enables cappy if not enabled already
    static void enableCap(GameDataHolderWriter);

    // kills the player
    static void killPlayer(GameDataHolderWriter);

    // damages the player
    static void damagePlayer(GameDataHolderWriter);

    // upgrades the odyssey
    static void upHomeLevel(GameDataHolderWriter);

    //unlocks a kingdom based off index
    static void unlockWorld(GameDataHolderWriter, int);

    // checks if odyssey is/needs a repair
    static bool isRepairHome(GameDataHolderAccessor);
    static void repairHome(GameDataHolderWriter);

    // checks if odyssey is crashed
    static bool isCrashHome(GameDataHolderAccessor);
    static void crashHome(GameDataHolderWriter);

    // checks if odyssey is activated 
    static bool isActivateHome(GameDataHolderAccessor);
    static void activateHome(GameDataHolderWriter);

    // checks if the odyssey has launched for the first time.
    static bool isLaunchHome(GameDataHolderAccessor);
    static void launchHome(GameDataHolderWriter);

    static bool isHomeShipStage(GameDataHolder const *);

    // used during the event that enables the odyssey to be used (enables the globe for the odyssey)
    static void talkCapNearHomeInWaterfall(al::LiveActor const*);

    // gives the player a life up heart
    static void getLifeMaxUpItem(al::LiveActor const *);

};