#pragma once
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    class Contessa : public Player{
        public:
            Contessa(Game &game, const std::string &name) : Player(game, name){};
            static void block(Player& player); 
            virtual string role();
    };
}