#include "soldier.h"

int occupation_for_rank(int rank){
    if(rank == 1){
        return 1;
    } else if(rank == 2){
        return random_int(2, 5);
    } else {
        return 6;
    }
}

Soldier create_team_leader(const std::string& name, unsigned int id){
    int rank        = 3;
    int occupation  = 6;

    return Soldier(
                100, 100,
                rank, occupation, true,
                1,
                name,
                create_random_rifle(),
                create_random_pistol(),
                Melee_Weapon(15, "Combat_Knife"),
                create_combat_suit()
            );
}

Soldier create_team_member(const std::string& name, unsigned int id){
    int rank        = random_int(1, 2);
    int occupation  = occupation_for_rank(rank);

    return Soldier(
            100, 100,
            rank, occupation, true,
            id,
            name,
            create_random_rifle(),
            create_random_pistol(),
            Melee_Weapon(15, "Combat_Knife"),
            create_combat_suit()
           );
}
