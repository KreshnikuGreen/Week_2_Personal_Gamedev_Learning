#include "equipment.h"
#include "random_utils.h"
#include "squad.h"
#include <iostream>
#include <limits>

int main(){
    int choice          = 0;
    bool Play_State     = true;
    Squad Game_Squad    = create_squad("Guh", 7);
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
        std::cout << "===== Squad Menu =====\n1. Status\n2. Toggle Boots\n3. Take Damage\n4. Heal\n5. Exit";
        
        std::cin >> choice;
        
        if(std::cin.fail() || choice < 1 || choice > 5){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input.\n";
            continue;
        }
        
        switch(choice){
            case 1: Game_Squad.show_status();
                    break;
            case 2:{ 
                       for(size_t i = 0; i < Game_Squad.Members.size(); i++){
                           Soldier& soldier = Game_Squad.Members[i];
                           soldier.Combat_Boots.toggle();
                       }
                       break;
                   }
            case 3: {
                        int Random_Soldier = random_int(1, Game_Squad.Members.size());
                        random_damage(50, Game_Squad.Members[Random_Soldier]);
                    }
            case 4: {
                        int Random_Soldier = random_int(1, Game_Squad.Members.size());
                        heal(Game_Squad.Members[Random_Soldier]);
                    }
                    break;
            case 5: Play_State = false;
                    break;
            default: break;
        }
    }
            
    return 0;
}
