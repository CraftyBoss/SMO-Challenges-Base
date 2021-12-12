#pragma once

#include "Packet.h"

struct PlayerConnect : Packet {
    PlayerConnect() : Packet() {this->type = PacketType::PLAYERCON;};
    ConnectionTypes conType;
};