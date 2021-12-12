#pragma once

#include "Packet.h"

struct TagInf : Packet {
    TagInf() : Packet() {this->type == PacketType::TAGINF;};
    bool isIt = false;
    // server time stuff
    // remaining seekers
};