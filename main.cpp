#include "squad.h"
#include <iostream>

int main(){
    bool Play_State = true;
    Squad Game_Squad = create_squad("Guh", 7);
    std::string Boots_State;

    while(Play_State == true){
        for (size_t i = 0; i < Game_Squad.Members.size(); i++){
            const Soldier& soldier = Game_Squad.Members[i];
            if(soldier.Combat_Boots.State == true){
                Boots_State = "ON";
            } else {
                Boots_State = "OFF";
            }
        }
        std::cout << "";
    }

    return 0;
}
