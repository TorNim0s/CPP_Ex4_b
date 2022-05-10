#include "Assassin.hpp"

using namespace std;
namespace coup{
    void Assassin::coup(Player & player){
        if(!this->game->checkTurn(this)){
            throw runtime_error("Not your turn!");
        }
        const int price = 3;
        const int normal_price = 7;

        if (!player.alive)
        {
            throw runtime_error("the player is dead");
        }

        if(this->balance < price){
            throw runtime_error("not enough balance!");
        }

        if(this->balance >= price && this->balance < normal_price){
            player.alive = false;
            this->lastActionName = "assasin_coup";
            this->playerActionFromMe = &player;
            this->balance -= price;
        }
        else{
            player.alive = false;
            this->lastActionName = "coup";
            this->balance -= normal_price;
        }
        this->game->finishTurn();
    }
    string Assassin::role(){
        return "Assassin";
    }
}