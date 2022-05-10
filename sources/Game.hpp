#pragma once

#include "Player.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>


#define MAX_PLAYERS 6
#define MIN_PLAYERS 2

namespace coup{
    class Game{
        private: 
            // std::vector<std::string> playersList;
            std::vector<Player*> playersList;
        public:
            void addPlayer(Player* player);
            bool checkTurn(Player* player);
            size_t gameTurn;
            Game();
            void finishTurn();
            std::string turn() const;
            std::vector<std::string> players();
            std::string winner();
    };
}