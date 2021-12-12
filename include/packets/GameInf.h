#pragma once

#include "Packet.h"

struct GameInf : Packet {
    GameInf() : Packet() {this->type = PacketType::GAMEINF;};
    bool is2D = false;
    bool isCapThrow = false;
    bool isIt = false; // TEMP
    int scenarioNo = -1;
    char stageName[PACKBUFSIZE] = {};
    char actName[PACKBUFSIZE] = {};
    char subActName[PACKBUFSIZE] = {};

    constexpr bool operator==(const GameInf &rhs) const {
        return (
            is2D == rhs.is2D &&
            isCapThrow == rhs.isCapThrow &&
            scenarioNo == rhs.scenarioNo &&
            al::isEqualString(stageName, rhs.stageName) &&
            al::isEqualString(actName, rhs.actName) &&
            al::isEqualString(subActName, rhs.subActName)
        );
    };

    constexpr bool operator!=(const GameInf& rhs) const { return !operator==(rhs); }
};