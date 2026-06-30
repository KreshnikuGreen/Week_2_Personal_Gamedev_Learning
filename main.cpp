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
                        int Random_Soldier = random_int(0, Game_Squad.Members.size() - 1);
                        int Damage_Type = random_int(1, 2);
                        random_damage(Damage_Type, Game_Squad.Members[Random_Soldier]);
                    }
                    break;
            case 4: {
                        int Random_Soldier = random_int(0, Game_Squad.Members.size() - 1);
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
