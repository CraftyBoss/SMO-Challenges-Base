#pragma once

#include "Packet.h"

struct ServerCommand : Packet {
    ServerCommand(const char *command) : Packet() {this->type = PacketType::CMD; strcpy(srvCmd, command);};
    char srvCmd[PACKBUFSIZE] = {};
};