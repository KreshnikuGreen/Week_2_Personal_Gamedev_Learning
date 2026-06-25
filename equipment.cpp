#include "equipment.h"
#include "soldier.h"
#include <algorithm>
#include <iostream>

void Infantry_Ranged_Weapon::reload(){
    if(Magazines < 0){
        Magazines = 0; // Doing both cases at once to reduce how much I have to write
        std::cout << "Can't reload, no magazines left\n";
        return;
    }

    if(Ammo == 0){
        Ammo = Max_Ammo - 1;
    } else {

        Ammo = Max_Ammo; // This is because Max_Ammo includes the round in the chamber, thus the initial -1 above
    }
    
    Magazines -= 1;

}

void Infantry_Ranged_Weapon::fire(){
    int Rounds;

    if(Ammo <= 0){
        Ammo = 0;
        std::cout << "Can't fire, no ammo left\n";
        return;
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
    int Missing = Max_Integrity - Suit_Integrity;

    int Repair_Amount = std::min(Missing, kit.Repair_Amount);
    
    Suit_Integrity += Repair_Amount;
    kit.Repair_Amount -= Repair_Amount;
}

void Suit::Replenish_Oxygen(Oxygen_Tank& tank){
    int Missing = Max_Oxygen - Oxygen;

    int Refill_Amount = std::min(Missing, tank.Oxygen_Amount);

    Oxygen += Refill_Amount;
    tank.Oxygen_Amount -= Refill_Amount;
}

void Boots::toggle(){
    State = !State;
}

Infantry_Ranged_Weapon create_random_rifle(){
    int type = random_int(1, 3);
    switch(type){
        case 1: return Infantry_Ranged_Weapon(3.5f, 900, 5, 31, 30, 25, true, "M4A1");
        case 2: return Infantry_Ranged_Weapon(4.0f, 850, 4, 26, 25, 30, true, "AK-47");
        case 3: return Infantry_Ranged_Weapon(2.5f, 1000, 6, 21, 20, 35, true, "Sniper");
        default: return Infantry_Ranged_Weapon(3.0f, 800, 3, 21, 20, 20, true, "Default_Rifle");
    }
}

Infantry_Ranged_Weapon create_random_pistol(){
    int type = random_int(1, 2);
    switch(type){
        case 1: return Infantry_Ranged_Weapon(1.0f, 400, 3, 16, 15, 10, true, "Glock");
        case 2: return Infantry_Ranged_Weapon(1.2f, 380, 4, 13, 12, 12, true, "M1911");
        default: return Infantry_Ranged_Weapon(1.0f, 350, 3, 11, 10, 10, true, "Default_Pistol");
    }
}
