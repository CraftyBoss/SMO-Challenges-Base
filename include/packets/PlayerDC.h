#pragma once

#include "Packet.h"

struct PlayerDC : Packet {
    PlayerDC() : Packet() {this->type = PacketType::PLAYERDC;};
};