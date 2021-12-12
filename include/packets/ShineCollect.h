#pragma once

#include "Packet.h"

struct ShineCollect : Packet {
    ShineCollect() : Packet() {this->type = PacketType::SHINECOLL;};
    int shineId = -1;
};