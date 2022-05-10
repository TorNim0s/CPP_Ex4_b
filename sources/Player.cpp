#include "Game.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    Player::Player(Game &game, const string &name){
        this->game = &game;

        this->name = name;
        this->balance = 0;
        this->alive = true;
        this->lastActionName = "";
        this->playerActionFromMe = NULL;
        this->playerActionOnMe = NULL;
        this->game->addPlayer(this);
    }
    string Player::getName(){
        return this->name;
    }

    string Player::role(){
        return "Player";
    }
    int Player::coins() const{
        return this->balance;
    }

    void Player::income(){
        if(!this->game->checkTurn(this)){
            throw runtime_error("Not your turn!");
        }

        if(this->balance >= MUST_COUP){
            throw runtime_error("MUST COUP!");
        }

        this->balance += 1;
        this->lastActionName = "income";
        this->game->finishTurn();
    }
    void Player::foreign_aid(){
        if(!this->game->checkTurn(this)){
            throw runtime_error("Not your turn!");
        }
        if(this->balance >= MUST_COUP){
            throw runtime_error("MUST COUP!");
        }

        this->balance += 2;
        this->lastActionName = "foreign_aid";
        this->game->finishTurn();
    }
    void Player::coup(Player &player){
        if(!this->game->checkTurn(this)){
            throw runtime_error("Not your turn!");
        }
        const int price = 7;
        if (!player.alive)
        {
            throw runtime_error("the player is dead");
        }
        
        if (this->balance < price)
        {
            throw runtime_error("the Player doesn't have enough money");
        }
        this->balance -= COUP_COST;
        player.alive = false;
        this->lastActionName = "coup";
        this->game->finishTurn();
    }
    
}