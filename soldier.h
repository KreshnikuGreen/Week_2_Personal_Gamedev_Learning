#pragma once
#include "equipment.h"
#include "random_utils.h"
#include <string>

Infantry_Ranged_Weapon create_random_rifle();
Infantry_Ranged_Weapon create_random_pistol();
int occupation_for_rank(int rank);

struct Soldier{
    int                     MAX_HEALTH;
    int                     Health;
    int                     RANK;
    int                     OCCUPATION; 
    bool                    Alive;
    unsigned int            ID_Number;
    /*
     * True     = Alive
     * False    = Dead
     */
    std::string             Name;

    Infantry_Ranged_Weapon  Primary_Weapon;
    Infantry_Ranged_Weapon  Secondary_Weapon;
    Melee_Weapon            Knife;
    Suit                    Combat_Suit;

    Soldier(int mH, int h, int r, int o, bool a, unsigned int id, std::string nM, Infantry_Ranged_Weapon pW, Infantry_Ranged_Weapon sW, Melee_Weapon k, Suit s): 
        MAX_HEALTH(mH), 
        Health(h), 
        RANK(r), 
        OCCUPATION(o), 
        Alive(a),
        ID_Number(id),
        Name(nM), 
        Primary_Weapon(pW), 
        Secondary_Weapon(sW), 
        Knife(k),
        Combat_Suit(s)
    {}
};

Soldier create_team_leader(const std::string& name);
Soldier create_team_member(const std::string& name, unsigned int id);
