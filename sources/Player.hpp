#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

#define COUP_COST 7
#define MUST_COUP 10

namespace coup{
    class Game;
    class Player{
        protected:           
            std::string name;
            Player(Game &game,  const std::string &name); // absract class

        public:
            Game* game;
            
            std::string lastActionName;

            Player* playerActionOnMe;
            Player* playerActionFromMe;
            int balance;
            bool alive;
            std::string getName();

            virtual std::string role();
            int coins() const;
            
            void income();
            void foreign_aid();
            virtual void coup(Player &player);
    };
}
