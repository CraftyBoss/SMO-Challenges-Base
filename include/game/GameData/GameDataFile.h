/**
 * @file GameDataFile.h
 * @brief Holds data for an individual save file.
 */

#pragma once

#include "al/scene/SceneObjHolder.h"
#include "types.h"
#include "UniqueObjInfo.h"

#include "sead/math/seadVector.h"
#include "sead/stream/seadStream.h"

namespace al {
    class ActorInitInfo;
    class PlacementInfo;
    class PlacementId;
}

class GameDataHolder;
class ShineInfo;

class GameDataFile
{
    public:
        GameDataFile(GameDataHolder *);
        void initializeData(void);
        void tryReadByamlData(uchar const*);
        void tryFindCoinCollectInfo(char const*,char const*);
        void tryFindShineIndexByUniqueId(int);
        void tryFindCoinCollectIndexByUniqueId(int);
        void buyDefaultItem(void);
        void unlockAchievementShineName(void);
        void updateWorldMapIndex(void);
        void updateWorldWarpIndex(void);
        void initializeCheckpointTable(void);
        void generateSaveDataIdForPrepo(void);
        void resetMapIcon(void);
        void wearDefault(void);
        void initializeHintList(void);
        void initializeCoinCollectList(void);
        void resetTempData(void);
        void addPlayTime(int,al::IUseSceneObjHolder const*);
        void updateSaveTime(void);
        void updateSaveTimeForDisp(void);
        void updateSaveInfoForDisp(void);
        void generateSaveDataIdForPrepoForWrite(void);
        void resetSaveDataIdForPrepoForWrite(void);
        void startStage(char const*,int);
        void checkIsHomeStage(char const*);
        void setGameClear(void);
        void startDemoStage(char const*);
        void changeNextStage(struct ChangeStageInfo const*,int);
        void returnPrevStage(void);
        void changeNextStageWithDemoWorldWarp(char const*);
        void changeNextStageWithWorldWarpHole(char const*);
        void restartStage(void);
        void calcNextScenarioNo(void);
        void tryGetStageNameCurrent(void);
        void changeWipeType(char const*);
        void setRestartPointId(al::PlacementId const*);
        void clearStartId(void);
        void tryGetRestartPointIdString(void);
        void endStage(void);
        void missAndRestartStage(void);
        void checkGotShine(char const*);
        void tryGetNextMainScenarioLabel(sead::BufferedSafeString *,sead::BufferedSafeString *);
        void tryGetNextMainScenarioPos(sead::Vector3f *);
        void tryFindNextMainScenarioInfo(void);
        void addPayShine(int);
        void addPayShineCurrentAll(void);
        void addKey(int);
        void addOpenDoorLockNum(int);
        void tryFindSaveObjS32(al::PlacementId const*);
        void addSessionMember(struct SessionMusicianType const&);
        void addCoinCollect(al::PlacementId const*);
        void useCoinCollect(int);
        void tryFindExistCoinCollectStageName(int);
        void payCoinToSphinx(void);
        void answerCorrectSphinxQuiz(void);
        void answerCorrectSphinxQuizAll(void);
        void talkLocalLanguage(void);
        void saveWorldTravelingStatus(char const*);
        void startWorldTravelingPeach(void);
        void setGrowFlowerTime(al::PlacementId const*,ulong);
        void addGrowFlowerGrowLevel(al::PlacementId const*,uint);
        void findGrowFlowerPotIdFromSeedId(al::PlacementId const*);
        void addCoin(int);
        void addPlayerJumpCount(void);
        void addPlayerThrowCapCount(void);
        void readFromStream(sead::ReadStream *,uchar *);
        void tryReadByamlDataFromStream(sead::ReadStream *,uchar *,int);
        void writeToStream(sead::WriteStream *,sead::Heap *);
        void tryWriteByByaml(sead::WriteStream *,sead::Heap *);
        void calcCheckpointIndexInScenario(int);
        void changeNextSceneByGotCheckpoint(int);
        void changeNextSceneByWarp(void);
        void changeNextSceneByHome(void);
        void startYukimaruRace(void);
        void startYukimaruRaceTutorial(void);
        void startRaceManRace(void);
        void registerCheckpointTrans(al::PlacementId const*,sead::Vector3f const&);
        void calcGetCheckpointNum(void);
        void calcRestHintNum(void);
        void unlockHint(void);
        void unlockHintImpl(int);
        void unlockHintAmiibo(void);
        void unlockHintAddByMoonRock(void);
        void calcHintNum(void);
        void calcHintTrans(int);
        void findHint(int);
        void calcHintTransMostEasy(void);
        void findHintInfoMostEasy(void);
        void calcHintMoonRockNum(void);
        void calcHintMoonRockTrans(int);
        void findHintMoonRock(int);
        void tryUnlockShineName(int,int);
        void calcShineIndexTableNameAvailable(int *,int *,int);
        void calcShineIndexTableNameUnlockable(int *,int *,int);
        void unlockWorld(int);
        void noPlayDemoWorldWarp(void);
        void calcWorldWarpHoleThroughNum(void);
        void enteredStage(void);
        //void buyItem(ShopItem::ItemInfo const*,bool);
        //void tryFindItemList(ShopItem::ItemInfo const*);
        void calcHaveClothNum(void);
        void calcHaveCapNum(void);
        void calcHaveStickerNum(void);
        void calcHaveGiftNum(void);
        void buyItemAll(void);
        void wearCostume(char const*);
        void wearCap(char const*);
        void addHackDictionary(char const*);
        void findShine(int,int);
        void calcShineNumInOneShine(int,int);
        void checkAchievementShine(int,int);
        void winRace(void);
        void findRaceRecord(char const*);
        void incrementRaceLoseCount(int);
        void setUpdateJumpingRopeScoreFlag(void);
        void setVolleyballBestCount(int);
        void setUpdateVolleyballScoreFlag(void);
        void setAmiiboNpcTrans(sead::Vector3f const&);
        void setTimeBalloonNpcTrans(sead::Vector3f const&);
        void setPoetterTrans(sead::Vector3f const&);
        void setShopNpcTrans(sead::Vector3f const&,char const*,int);
        void setMoonRockTrans(sead::Vector3f const&);
        void setMiniGameInfo(sead::Vector3f const&,char const*);
        void calcMiniGameNum(void);
        void showExplainCheckpointFlag(void);
        void calcShopNum(void);
        void talkKakku(void);
        void talkWorldTravelingPeach(void);
        void talkCollectBgmNpc(void);
        void noFirstNetwork(void);
        void calcIsGetMainShineAll(al::IUseSceneObjHolder const*);
        void calcIsGetShineAllInWorld(int);
        void tryFindLinkedShineIndex(al::ActorInitInfo const&,al::IUseSceneObjHolder const*);
        void tryFindLinkedShineIndex(al::ActorInitInfo const&,int,al::IUseSceneObjHolder const*);
        void tryFindLinkedShineIndexByLinkName(al::IUseSceneObjHolder const*,al::ActorInitInfo const&,char const*);
        void calcLinkedShineNum(al::ActorInitInfo const&);
        void tryFindShineIndex(al::ActorInitInfo const&);
        void tryFindShineIndex(char const*,char const*);
        void disableHintById(int);
        void enableHintById(int);
        void setHintTrans(int,sead::Vector3f const&);
        void resetHintTrans(int);
        void registerShineInfo(ShineInfo const*,sead::Vector3f const&);
        void calcRestShineInStageWithWorldProgress(char const*);
        // void calcGetShineNumByObjectNameOrOptionalId(char const*, GameDataFile::CountType);
        void calcGetShineNumByObjectNameWithWorldId(char const*,int);
        void calcAllShineNumByObjectNameOrOptionalId(char const*);
        void calcGetShineNumByStageName(char const*);
        void tryFindAndInitShineInfoByOptionalId(ShineInfo *,char const*);
        void tryFindUniqueId(ShineInfo const*);
        void findUnlockShineNumCurrentWorld(bool *);
        void trySetCollectedBgm(char const*,char const*);
        // void setGotShine(GameDataFile::HintInfo const*);
        // void tryWriteByByaml(al::ByamlWriter *);
        
        int getTotalShineNum(void);
        void getCollectBgmByIndex(int);
        u8 getMainScenarioNoCurrent(void) const;
        int getStartShineNextIndex(void);
        void getTokimekiMayorNpcFavorabilityRating(void);
        void getShopNpcIconNumMax(void);
        void getShopNpcTrans(int);
        void getPoetterTrans(void);
        void getTimeBalloonNpcTrans(void);
        void getMiniGameNumMax(void);
        void getRaceLoseCount(int);
        int getWorldTotalShineNum(int);
        int getWorldWarpHoleThroughNumMax(void);
        void getCheckpointObjIdInWorld(int);
        void getCheckpointNumMaxInWorld(void);
        void getPlayerThrowCapCount(void);
        void getPlayerJumpCount(void);
        void getGrowFlowerGrowLevel(al::PlacementId const*);
        void getGrowFlowerTime(al::PlacementId const*);
        void getWorldTravelingStatus(void);
        void getCoinCollectNum(void);
        void getKeyNum(void);
        int getPayShineNum(int);
        int getShineNum(void);
        void getAchievement(char const*);
        void getPlayerStartId(void);
        void getStageNameNext(void);
        void getStageNameCurrent(void);
        void getPlayerHitPointData(void);
        void getLastUpdateTime(void);
        void getPlayTimeTotal(void);
        void getMainScenarioNo(int);
        void getCollectedBgmMaxNum(void);
        void getScenarioNo(void);
        void getMiniGameName(int);
        void getWorldTotalShineNumMax(int);
        void getCheckpointTransInWorld(char const*);
        void getCoinCollectGotNum(void);
        void getTotalPayShineNum(void);
        void getShineNum(int);
        void getScenarioNo(int);
        void getCollectedBgmNum(void);
        void getScenarioNoPlacement(void);
        void getMiniGameTrans(int);
        void getCoinCollectGotNum(int);
        void getTotalShopShineNum(void);

        void setGotShine(int);
        void setMainScenarioNo(int);
        void setStartShine(ShineInfo const*);
        void setKidsMode(bool);
        void setTokimekiMayorNpcFavorabilityRating(int);
        void setFlagOnTalkMessageInfo(int);
        void setJangoTrans(sead::Vector3f const&);
        void setJumpingRopeBestCount(int);
        void setGrowFlowerTime(al::PlacementId const*,al::PlacementId const*,ulong);
        void setSaveObjS32(al::PlacementId const*,int);
        void setStartedObj(al::PlacementId const*);
        void setGotShine(ShineInfo const*);
        void setMissRestartInfo(al::PlacementInfo const&);
        void setCheckpointId(al::PlacementId const*);
        void setActivateHome(void);
        void setOriginalHintTrans(int);

        bool isUnlockedWorld(int) const;
        bool isAlreadyGoWorld(int) const;
        bool isFirstTimeNextWorld(void) const;
        bool isGotShine(ShineInfo const*) const;
        bool isGotShine(int) const;
        bool isStartedObj(char const*,char const*) const;
        bool isAnswerCorrectSphinxQuizAll(int) const;
        bool isTalkAlreadyLocalLanguage(void) const;
        bool isBuyItem(char const*,sead::FixedSafeString<64> const*) const;
        bool isOpenShineName(int,int) const;
        bool isExistPoetter(void) const;
        bool isAlreadyShowExplainCheckpointFlag(void) const;
        bool isFlagOnTalkMessageInfo(int) const;
        bool isTalkKakku(void) const;
        bool isNextMainShine(struct QuestInfo const*) const;
        bool isNextMainShine(int) const;
        bool isMainShine(int) const;
        bool isLatestGetMainShine(ShineInfo const*) const;
        bool isEnableOpenMoonRock(int) const;
        bool isCollectedBgm(char const*,char const*) const;
        bool isPlayScenarioCamera(struct QuestInfo const*) const;
        bool isFirstNetwork(void) const;
        bool isTalkCollectBgmNpc(void) const;
        bool isTalkWorldTravelingPeach(void) const;
        bool isClearWorldMainScenario(int) const;
        bool isShopSellout(int) const;
        bool isExistTimeBalloonNpc(void) const;
        bool isExistJango(void) const;
        bool isGotShine(int,int) const;
        bool isExistInHackDictionary(char const*) const;
        // bool isBuyItem(ShopItem::ItemInfo const*) const;
        bool isUnlockAchievementShineName(void) const;
        bool isOpenMoonRock(int) const;
        bool isEnableUnlockHint(void) const;
        bool isGotCheckpoint(al::PlacementId *) const;
        bool isGotCheckpointInWorld(int) const;
        bool isPlayDemoPlayerDownForBattleKoopaAfter(void) const;
        bool isUsedGrowFlowerSeed(al::PlacementId const*) const;
        bool isStartWorldTravelingPeach(void) const;
        bool isFirstWorldTravelingStatus(void) const;
        bool isAnswerCorrectSphinxQuiz(int) const;
        bool isPayCoinToSphinx(void) const;
        bool isGotCoinCollect(al::PlacementId const*) const;
        bool isExistSessionMember(struct SessionMusicianType const&) const;
        bool isStartedObj(al::PlacementId const*,char const*) const;
        bool isPayShineAllInAllWorld(void) const;
        bool isUseMissRestartInfo(void) const;
        bool isGoToCeremonyFromInsideHomeShip(void) const;
        bool isRaceStart(void) const;
        bool isGameClear(void) const;
        bool isEmpty(void) const;
        bool isKidsMode(void) const;
        
        undefined padding[0x5C8];
        UniqObjInfo** mUniqueInfo;  // 0x5C8
        void *unkPtr1; // 0x5D0
        void *unkPtr2; // 0x5D8
        void *unkPtr3; // 0x5E0
        void* unkPtr4;  // 0x5E8
        void* unkPtr5;  // 0x5F0
        bool unkBool1; // 0x5F8
        bool unkBool2; // 0x5F9
        bool mIsCapEnable; // 0x5FA
};
        