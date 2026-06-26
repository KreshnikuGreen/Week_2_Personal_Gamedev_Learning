#pragma once
#include <random>
#include <iostream>
#include "soldier.h"

inline int random_int(int min, int max){
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

inline void random_damage(unsigned int Type_Of_Damage, Soldier& target){

    int Armor_Damage = 0;
    int Health_Damage = 0;
    int Ammo_Type_Index = 0;
    /*
     *  1 - HP, Armor_Damage = 5; Health_Damage = 25;
     *  2 - FMJ, Armor_Damage = 10; Health_Damage = 15;
     *  3 - AP, Armor_Damage = 20; Health_Damage = 10;
     */
    int Amount_Of_Hits = 0;

    std::cout << "How many times would you like to hit them?\n";
    std::cin >> Amount_Of_Hits;

    if(Type_Of_Damage == 1){
        for(int i = 0; i < Amount_Of_Hits; i++){
            target.Health -= target.Knife.Max_Damage;
        }
    } else if(Type_Of_Damage == 2) {
        for(int i = 0; i < Amount_Of_Hits; i++){
            Ammo_Type_Index = random_int(1, 3);
            switch(Ammo_Type_Index){
                case 1: {
                            Armor_Damage = 5;
                            Health_Damage = 25;
                        }
                case 2: {
                            Armor_Damage = 10;
                            Health_Damage = 15;
                        }
                case 3: {
                            Armor_Damage = 20;
                            Health_Damage = 10;
                        }
            }
            target.Combat_Suit.Suit_Integrity -= Armor_Damage;
            target.Health -= Health_Damage;
            if(target.Combat_Suit.Suit_Integrity <= 0){
                target.Combat_Suit.Suit_Integrity = 0;
            }
            if(target.Health <= 0){
                target.Health = 0;
                target.Alive = false;
            }
        }
    }
}

inline void heal(Soldier& target){
    target.Health += 25;
    if(target.Health > target.MAX_HEALTH){
        target.Health = target.MAX_HEALTH;
    }
}


