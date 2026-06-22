#include "equipment.h"
#include <iostream>

void Infantry_Ranged_Weapon::reload(){
    if(Magazines <= 0){
        Magazines = 0;// Doing both cases at once to reduce how much I have to write
        std::cout << "Can't reload, no magazines left\n";
    }

    if(Ammo == 0){
        Ammo = Max_Ammo - 1;
    } else {
        Ammo = Max_Ammo; // This is because Max_Ammo includes the round in the chamber, thus the initial -1 above
    }
}

void Infantry_Ranged_Weapon::fire(){
    int Rounds;

    if(Ammo == 0){
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
