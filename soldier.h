#pragma once
#include "equipment.h"
#include "random_utils.h"
#include <string>

struct Soldier{
    const int   MAX_HEALTH;
    const int   RANK;
    const int   OCCUPATION; 
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
