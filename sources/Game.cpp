#include "Game.hpp"

using namespace std;
namespace coup{
    Game::Game(){
        this->gameTurn = 0;
    }
    string Game::turn() const{
        return this->playersList.at(this->gameTurn % this->playersList.size())->getName();
    }

    void Game::addPlayer(Player* player){
        if(this->gameTurn > 0){
            throw runtime_error("Game already started!");
        }
        if(this->playersList.size() >= MAX_PLAYERS){
            throw runtime_error("MAX PLAYERS!");
        }
        this->playersList.push_back(player);
    }

    bool Game::checkTurn(Player* player){
        if(this->playersList.size() < MIN_PLAYERS){
            throw runtime_error("Not enough players!");
        }

        return player->getName() == this->turn();
    }

    vector<string> Game::players(){
        vector<string> res; 
        for (size_t i = 0; i < playersList.size(); i++)
        {
            if (playersList.at(i)->alive)
            {
                res.push_back(playersList.at(i)->getName());
            }
        }
        return res;
    }
    void Game::finishTurn(){
        this->gameTurn = this->gameTurn + 1;
        int counter = 0;
        while(!this->playersList[this->gameTurn%this->playersList.size()]->alive){
            this->gameTurn = this->gameTurn + 1;
            counter++;
            if(counter == this->playersList.size()){
                throw runtime_error("Error! everyone is dead!");
            }
        }
    }
    string Game::winner(){
        if(gameTurn == 0){
            throw runtime_error("Game not started!");
        }
        int counter = 0;
        string winName;
        for(size_t i = 0; i<playersList.size(); i++){
            if(playersList.at(i)->alive){
                counter++;
                winName = playersList.at(i)->getName();
            }
        }

        if(counter == 1){
            return winName;
        }

        throw runtime_error("Error! canno't be less or more than 1 winner");
    }
}