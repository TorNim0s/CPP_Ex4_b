#pragma once
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    class Assassin : public Player{
        public:
            Assassin(Game &game, const std::string &name) : Player(game, name){};
            void coup(Player & player);
            virtual string role();
    };
}