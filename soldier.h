#pragma once
#include "equipment.h"
#include "random_utils.h"
#include <string>

Infantry_Ranged_Weapon create_random_rifle();
Infantry_Ranged_Weapon create_random_pistol();

struct Soldier{
    int                     MAX_HEALTH;
    int                     Health;
    int                     RANK;
    int                     OCCUPATION; 
    bool                    Alive;
    /*
     * True     = Alive
     * False    = Dead
     */
    std::string             Name;

    Infantry_Ranged_Weapon  Primary_Weapon;
    Infantry_Ranged_Weapon  Secondary_Weapon;
    Melee_Weapon            Knife;

    Soldier(int mH, int h, int r, int o, bool a, std::string nM, Infantry_Ranged_Weapon pW, Infantry_Ranged_Weapon sW, Melee_Weapon k): 
        MAX_HEALTH(mH), 
        Health(h), 
        RANK(r), 
        OCCUPATION(o), 
        Alive(a), 
        Name(nM), 
        Primary_Weapon(pW), 
        Secondary_Weapon(sW), 
        Knife(k)
    {}
};
