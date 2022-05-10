#pragma once
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain : public Player{
        public:
            Captain(Game &game, const std::string &name) : Player(game, name){};
            static void block(Player& player); 
            void steal(Player& player); 
            virtual string role();
    };
}