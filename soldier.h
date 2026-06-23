#pragma once
#include "equipment.h"
#include "random_utils.h"
#include <string>

struct Soldier{
    const int   MAX_HEALTH;
    const int   OCCUPATION;
    /*
     *  1 - Rifleman (if rank == 1)
     *  2 - Designated_Marksman (if rank == 2)
     *  3 - Grenadier (if rank == 2)
     *  4 - Team Leader (if rank == 2)
     *  5 - Medic/Repairman (if rank == 2)
     *  6 - Team Leader (if rank == 3)
     */
    const int   RANK;
    /*
     * 1 - Normal
     * 2 - Specialist
     * 3 - Team Leader
     */
    bool        Alive;
    /*
     * True     = Alive
     * False    = Dead
     */
    std::string Name;

    Soldier() : 
        MAX_HEALTH(100), 
        RANK(random_int(1, 3)),
        OCCUPATION(occupation_for_rank(RANK)),
        Alive(true),
        Name("Unnamed")
    {}

    private:

    static int occupation_for_rank(int rank){
        if(rank == 1){
            return 1;
        } else if(rank == 2){
            return random_int(2, 5);
        } else {
            return 6;
        }
    }
};
