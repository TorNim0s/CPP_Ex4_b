#include "Captain.hpp"

using namespace std;
namespace coup{
    void Captain::block(Player& player){
        if(player.lastActionName == "steal"){
            player.playerActionOnMe->balance -= 2;
            player.balance += 2;
            player.lastActionName = "";
        }
        else{
            throw runtime_error("Canno't block action that didn't happened!");
        }
    }
    void Captain::steal(Player& player){
        if(!this->game->checkTurn(this)){
            throw runtime_error("Not your turn!");
        }
        if(this->balance >= MUST_COUP){
            throw runtime_error("MUST COUP!");
        }
        if(player.balance < 2){
            this->balance += player.balance;
            player.balance = 0;
        }
        else{
            this->balance += 2;
            player.balance -= 2;
        }
        
        this->lastActionName = "steal";
        this->playerActionFromMe = &player;
        this->game->finishTurn();
    }
    string Captain::role(){
        return "Captain";
    }
}