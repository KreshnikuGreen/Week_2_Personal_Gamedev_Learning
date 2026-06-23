#include "equipment.h"
#include <iostream>

void Infantry_Ranged_Weapon::reload(){
    if(Magazines <= 0){
        Magazines = 0; // Doing both cases at once to reduce how much I have to write
        std::cout << "Can't reload, no magazines left\n";
    }

    if(Ammo == 0){
        Ammo = MAX_AMMO - 1;
    } else {
        Ammo = MAX_AMMO; // This is because MAX_AMMO includes the round in the chamber, thus the initial -1 above
    }
}

void Infantry_Ranged_Weapon::fire(){
    int Rounds;

    if(Ammo <= 0){
        Ammo = 0;
        std::cout << "Can't fire, no ammo left\n";
    }

    std::cout << "How many rounds do you want to fire? ";
    std::cin >> Rounds;

    if(Ammo < Rounds){
        std::cout << "Can't fire, only " << Ammo << " rounds left\n";
    } else {
        Ammo -= Rounds;
        std::cout << "FIRE!!! " << Rounds << " fired\n";
    }
}

void Melee_Weapon::hit(){
    std::cout << "Hit Something\n";
}

void Suit::Check_Integrity(){
    std::cout << "Suit Integrity is " << Suit_Integrity << "\n";
}

void Suit::repair(Repair_Kit& kit){
    int difference = kit.Repair_Amount - Suit_Integrity;
    
    if(difference < 0){
        difference *= -1;
    }
    
    Suit_Integrity += difference;
    kit.Repair_Amount -= difference;
    
    if(Suit_Integrity >= MAX_INTEGRITY){
        Suit_Integrity = MAX_INTEGRITY;
    }
}

void Suit::Replenish_Oxygen(Oxygen_Tank& tank){
    int difference = tank.Oxygen_Amount - MAX_OXYGEN;
    
    if(difference < 0){
        difference *= -1;
    }

    Oxygen += tank.Oxygen_Amount;
    tank.Oxygen_Amount -= difference;

    if(Oxygen >= MAX_OXYGEN){
        Oxygen = MAX_OXYGEN;
    }
}

void Boots::toggle(){
    State = !State;
}
