#include "Ambassador.hpp"

using namespace std;
namespace coup{
    void Ambassador::transfer(Player& srcPlayer, Player & dstPlayer){
        if(!this->game->checkTurn(this)){
            throw runtime_error("Not your turn!");
        }
        if(!srcPlayer.alive || !dstPlayer.alive){
            throw runtime_error("Player is dead!");
        }
        if(srcPlayer.balance == 0){
           throw runtime_error("Not enough balance!");
        }

        srcPlayer.balance-=1;
        dstPlayer.balance+=1;

        this->lastActionName = "tranfer";
        this->game->finishTurn();
    }
    void Ambassador::block(Player& player){
        if(player.lastActionName == "steal"){
            player.playerActionFromMe->balance += 2;
            player.balance -= 2;
            player.lastActionName = "";
        }
        else{
            throw runtime_error("Canno't block action that didn't happened!");
        }
    }
    string Ambassador::role(){
        return "Ambassador";
    }
}