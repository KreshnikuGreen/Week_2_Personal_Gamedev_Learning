#include "equipment.h"
#include <iostream>

void Infantry_Ranged_Weapon::reload(){
    if(Magazines <= 0){
        Magazines = 0; // Doing both cases at once to reduce how much I have to write
        std::cout << "Can't reload, no magazines left\n";
        return;
    }

    if(Ammo == 0){
        Ammo = Max_Ammo - 1;
    } else {
        Ammo = Max_Ammo; // This is because Max_Ammo includes the round in the chamber, thus the initial -1 above
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
    
    if(Suit_Integrity >= Max_Integrity){
        Suit_Integrity = Max_Integrity;
    }
}

void Suit::Replenish_Oxygen(Oxygen_Tank& tank){
    int difference = tank.Oxygen_Amount - Max_Oxygen;
    
    if(difference < 0){
        difference *= -1;
    }

    Oxygen += tank.Oxygen_Amount;
    tank.Oxygen_Amount -= difference;

    if(Oxygen >= Max_Oxygen){
        Oxygen = Max_Oxygen;
    }
}

void Boots::toggle(){
    State = !State;
}
