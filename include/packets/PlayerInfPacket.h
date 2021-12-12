#pragma once

#include "Packet.h"

struct PlayerInf : Packet {
    PlayerInf() : Packet() {this->type = PacketType::PLAYERINF;};
    sead::Vector3f playerPos; 
    sead::Quatf playerRot;
    float animBlendWeights[6];
    float animRate = 0.f;

    constexpr bool operator==(const PlayerInf &rhs) const {
        bool isWeightsEqual = true;
        for (size_t i = 0; i < 6; i++)
        {
            if(animBlendWeights[i] != rhs.animBlendWeights[i]) {
                isWeightsEqual = false;
                break;
            }
        }
        return (
            playerPos == rhs.playerPos &&
            playerRot == rhs.playerRot &&
            isWeightsEqual &&
            animRate == rhs.animRate
        );
    }

    constexpr bool operator!=(const PlayerInf& rhs) const { return !operator==(rhs); }

};