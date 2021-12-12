#pragma once

#include "sead/devenv/seadDebugFontMgrNvn.h"
#include "sead/textwriter.h"
#include "sead/basis/seadNew.hpp"
#include "sead/gfx/seadViewport.h"

#include "agl/DrawContext.h"

#include "game/System/GameSystem.h"

#include "al/util.hpp"
#include "logger.hpp"

extern sead::TextWriter *gTextWriter;

bool setupDebugMenu(agl::DrawContext *context, sead::Viewport *viewport);