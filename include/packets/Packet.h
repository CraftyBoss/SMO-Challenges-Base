#pragma once

#include "sead/math/seadVector.h"
#include "sead/math/seadQuat.h"

#include "nn/account.h"

#define PACKBUFSIZE      0x30
#define COSTUMEBUFSIZE   0x20

#define MAXPACKSIZE      0x100

enum PacketType {
    UNKNOWN,
    PLAYERINF,
    GAMEINF,
    TAGINF,
    PLAYERCON,
    PLAYERDC,
    COSTUMEINF,
    SHINECOLL,
    CMD
};

static const char *packetNames[] = {
    "Unknown",
    "Player Info",
    "Game Info",
    "Tag Info",
    "Player Connect",
    "Player Disconnect",
    "Costume Info",
    "Moon Collection",
    "Server Command"
};

enum SenderType {
    SERVER,
    CLIENT
};

enum ConnectionTypes {
    INIT,
    RECONNECT
};

static const char *senderNames[] = {
    "Server",
    "Client"
};

struct Packet {
    nn::account::Uid playerId; 
    PacketType type = PacketType::UNKNOWN; 
};