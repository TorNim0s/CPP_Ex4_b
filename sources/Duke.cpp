#include "Duke.hpp"

using namespace std;
namespace coup{
    void Duke::tax(){
        if(!this->game->checkTurn(this)){
            throw runtime_error("Not your turn!");
        }

        if(this->balance >= MUST_COUP){
            throw runtime_error("MUST COUP!");
        }


        this->balance += 3;
        this->lastActionName = "tax";
        this->game->finishTurn();
    }
    void Duke::block(Player& player){
        if(player.lastActionName != "foreign_aid"){
            throw runtime_error("cannot block something that didn't happened");
        }

        player.balance -= 2;
        player.lastActionName = "";
        this->lastActionName = "block";
    }   
    string Duke::role(){
        return "Duke";
    }
}