/**
 * @file account.h
 * @brief Account service implementation.
 */

#pragma once

#include "os.h"
#include "types.h"

#include "logger.hpp"

namespace nn
{
    namespace account
    {
        // typedef char Nickname[0x21];
        // typedef u64 Uid[0x2];

        struct Nickname {
            char name[0x21] = {};
        };
        struct Uid {
            char data[0x10] = {};

            constexpr bool operator==(const Uid &rhs) const {
                return memcmp(data, rhs.data, 0x10) == 0;
            }

            constexpr Uid& operator=(const Uid& other)
            {
                memcpy(this->data, other.data, 0x10);
                return *this;
            }

            inline void print() {
                gLogger->LOG("Player ID: 0x");
                gLogger->isDisableName = true;
                for (size_t i = 0; i < 0x10; i++) { gLogger->LOG("%02X", data[i]); }
                gLogger->LOG("\n");
                gLogger->isDisableName = false;
            }
        };

        typedef u64 NetworkServiceAccountId;
        
        class AsyncContext;
        struct UserHandle;

        void Initialize();
        Result ListAllUsers(s32 *, nn::account::Uid *, s32 numUsers);
        Result OpenUser(nn::account::UserHandle *, nn::account::Uid const &);
        Result IsNetworkServiceAccountAvailable(bool *out, nn::account::UserHandle const &);
        void CloseUser(nn::account::UserHandle const &);

        Result EnsureNetworkServiceAccountAvailable(nn::account::UserHandle const &userHandle);
        Result EnsureNetworkServiceAccountIdTokenCacheAsync(nn::account::AsyncContext *, nn::account::UserHandle const &);
        Result LoadNetworkServiceAccountIdTokenCache(u64 *, char *, u64, nn::account::UserHandle const &);

        Result GetLastOpenedUser(nn::account::Uid *);
        Result GetNickname(nn::account::Nickname *nickname, nn::account::Uid const &userID);

        class AsyncContext
        {
        public:
            AsyncContext();

            Result HasDone(bool *);
            Result GetResult();
            Result Cancel();
            Result GetSystemEvent(nn::os::SystemEvent *);
        };
    };
};