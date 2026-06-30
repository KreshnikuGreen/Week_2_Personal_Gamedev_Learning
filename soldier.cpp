#include "soldier.h"
#include "random_utils.h"

int occupation_for_rank(int rank){
    if(rank == 1){
        return 1;
    } else if(rank == 2){
        return random_int(2, 5);
    } else {
        return 6;
    }
}

Soldier create_team_leader(const std::string& name){
    int rank        = 3;
    /*
     * 1 - Private/Grunt
     * 2 - Specialist
     * 3 - Team Leader
     */
    int occupation  = 6;
    /*
     * 1 - Rifleman
     * 2 - Grenadier
     * 3 - Medic
     * 4 - Autorifleman
     * 5 - Sniper
     * 6 - Team Leader
     */

    return Soldier(
                100, 100,
                rank, occupation, true,
                1,
                name,
                create_random_rifle(),
                create_random_pistol(),
                Melee_Weapon(15, "Combat_Knife"),
                create_combat_suit(),
                Boots(true)
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
            create_combat_suit(),
            Boots(true)
           );
}
