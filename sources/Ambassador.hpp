#pragma once
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Ambassador : public Player{
        public:
            Ambassador(Game &game, const std::string &name) : Player(game, name){}; // super
            void transfer(Player& srcPlayer, Player & dstPlayer);
            static void block(Player& player);
            virtual std::string role();
    };
}