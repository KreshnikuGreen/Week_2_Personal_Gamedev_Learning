#include "squad.h"
#include "equipment.h"
#include "soldier.h"
#include "random_utils.h"
#include <array>
#include <iostream>

std::string Squad::assign_name(){
    std::array<std::string, 7> Names = {"John", "Bob", "Bill", "Dean", "Daniel", "Sam", "Carl"};
    int Random = random_int(0, 6);

    return Names[Random];
}

void Squad::get_size() const{
    size_t Size =  Members.size();
    std::cout << "Squad has " << Size << " members\n";
}

bool Squad::is_wiped() const{
    size_t Size = Members.size();
    size_t Dead_Count = 0;
    
    for(int i = 0; i < Size; i++){
        if(Members[i].Alive == false){
            Dead_Count += 1;
        }
    }

    if(Dead_Count == Size){
        return true;
    } else {
        return false;
    }
}

void Squad::check_member_health() const{
    size_t Size = Members.size();

    std::cout << "===== Health =====\n";

    for(int i = 0; i < Size; i++){
        if(Members[i].Health < 50){
            std::cout << Members[i].Name << " is heavily wounded, only " << Members[i].Health << " health left";
        } else {
            std::cout << Members[i].Name << " has " << Members[i].Health << " health left\n";
        }
    }
}

Squad create_squad(const std::string &name, size_t Size){
    Squad Created_Squad(name, Size);
    Created_Squad.Members.reserve(Size);

    Created_Squad.Members.push_back(create_team_leader(Created_Squad.assign_name()));

    for(int i = 1; i < Size; i++){
        Created_Squad.Members.push_back(create_team_member(Created_Squad.assign_name(), 1 + i));
    }

    return Created_Squad;
}

void Squad::remove_member(int index){
    if(index >= 0 && index < (int)Members.size()){
        Members.erase(Members.begin() + index);
    }
}

void Squad::show_status() const{
    get_size();
    check_member_health();
    
    size_t Size = Members.size();

    std::cout << "===== Weapons =====\n";
    for(size_t i = 0; i < Size; i++){
        std::cout << Members[i].Name << " has " << Members[i].Primary_Weapon.Name << " " << Members[i].Secondary_Weapon.Name;
    }
    std::cout << "\n===== Ranks =====\n";
    for(size_t i = 0; i < Size; i++){
        std::cout << Members[i].Name << " is " << Members[i].RANK;
    }
}
