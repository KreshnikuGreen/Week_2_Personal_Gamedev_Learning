#include "squad.h"
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

void Squad::check_member_health(){
    size_t Size = Members.size();

    for(int i = 0; i < Size; i++){
        if(Members[i].Health < 50){
            std::cout << Members[i].Name << " is heavily wounded\n";
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
