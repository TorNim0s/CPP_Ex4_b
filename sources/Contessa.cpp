#include "Contessa.hpp"

using namespace std;
namespace coup{
    void Contessa::block(Player& player){
        if(player.lastActionName != "assasin_coup"){
            throw runtime_error("cannot block something that didn't happened");
        }
        
        player.playerActionFromMe->alive = true;
        player.lastActionName = "";
    }
    string Contessa::role(){
        return "Contessa";
    }
}