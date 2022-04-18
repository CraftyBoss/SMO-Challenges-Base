#pragma once

#include "game/Input/InputSeparator.h"
#include "game/Layouts/CommonVerticalList.h"
#include "game/Layouts/SimpleLayoutMenu.h"
#include "al/message/MessageSystem.h"
#include "al/nerve/HostStateBase.h"
#include "al/message/IUseMessageSystem.h"
#include "al/layout/LayoutInitInfo.h"
#include "al/scene/Scene.h"
#include "al/util/NerveUtil.h"
#include "rs/util/InputUtil.h"

#include "al/util.hpp"

#include "game/GameData/GameDataHolder.h"

#include "logger.hpp"

class FooterParts;

class StageSceneStateServerConfig : public al::HostStateBase<al::Scene>, public al::IUseMessageSystem {
    public:
        StageSceneStateServerConfig(const char*, al::Scene*, const al::LayoutInitInfo &,
                                    FooterParts *, GameDataHolder *, bool);

        virtual al::MessageSystem* getMessageSystem(void) const override;
        virtual void init(void) override;
        virtual void appear(void) override;
        virtual void kill(void) override;

        void exeWait();
        void exeOpenKeyboard();
        void exeRestartServer();

        al::MessageSystem* mMsgSystem;
        FooterParts* mFooterParts;
        GameDataHolder* mGameDataHolder;

        InputSeparator *mInput;

        SimpleLayoutMenu* mMainOptions;
        CommonVerticalList* mVerticalList;

        bool mIsDecideConfig = false;
};

namespace {
    NERVE_HEADER(StageSceneStateServerConfig, Wait)
    NERVE_HEADER(StageSceneStateServerConfig, OpenKeyboard)
    NERVE_HEADER(StageSceneStateServerConfig, RestartServer)
}

extern StageSceneStateServerConfig *sceneStateServerConfig;