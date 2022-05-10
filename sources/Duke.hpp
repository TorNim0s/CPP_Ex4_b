#pragma once
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    class Duke : public Player{
        public:
            Duke(Game &game, const std::string &name) : Player(game, name){};
            void tax();
            void block(Player& player);
            virtual string role();
    };
}