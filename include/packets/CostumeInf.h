#pragma once

#include "Packet.h"

struct CostumeInf : Packet {
    CostumeInf() : Packet() {this->type = PacketType::COSTUMEINF;};
    CostumeInf(const char *body, const char *cap) : Packet() {this->type = PacketType::COSTUMEINF; strcpy(bodyModel, body); strcpy(capModel, cap);};
    char bodyModel[COSTUMEBUFSIZE] = {};
    char capModel[COSTUMEBUFSIZE] = {};
};