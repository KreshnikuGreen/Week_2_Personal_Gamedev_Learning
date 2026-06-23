#pragma once
#include <string>

struct Infantry_Ranged_Weapon{
    float Mass;
    float Muzzle_Velocity;
    int Magazines;
    const int Max_Ammo;
    int Ammo;
    const int Max_Damage;
    bool Is_Loaded;
    std::string Name;

    Infantry_Ranged_Weapon(float m, float mV, int mG, int mA, int a, int mD, bool loaded, std::string nM) : Mass(m), Muzzle_Velocity(mV), Magazines(mG), Max_Ammo(mA), Ammo(a), Max_Damage(mD), Is_Loaded(loaded), Name(nM){}
    
    void reload();
    void fire();
};

struct Melee_Weapon{
    const int Max_Damage;
    std::string Name;

    Melee_Weapon(int mD, std::string nM) : Max_Damage(mD), Name(nM){}

    void hit();
};

struct Repair_Kit{
    int Repair_Amount;
    float Mass;
    std::string Name;
    
    Repair_Kit(int rA, float m, std::string nM) : Repair_Amount(rA), Mass(m), Name(nM){}
};

struct Oxygen_Tank{
    const int Max_Oxygen;
    int Oxygen_Amount;
    float Mass;
    std::string Name;

    Oxygen_Tank(int mO, int oA, float m, std::string nM) : Max_Oxygen(mO), Oxygen_Amount(oA), Mass(m), Name(nM){}
};

struct Suit{
    enum class Armor_Type{
        Standard,
        Level_I,
        Level_II,
        Level_IIIA,
        Level_III,
        Level_IIIPlus,
        Level_IV
    };
    int Suit_Integrity;
    const int Max_Integrity;
    int Oxygen;
    const int Max_Oxygen;
    float Mass;
    std::string Name;
    Armor_Type armor_type;

    Suit(Armor_Type aT, int sI, int mI, int o, int mO, float m, std::string nM) : armor_type(aT), Suit_Integrity(sI), Max_Integrity(mI), Oxygen(o), Max_Oxygen(mO), Mass(m), Name(nM){}

    void Check_Integrity();
    void repair(Repair_Kit& kit);
    void Replenish_Oxygen(Oxygen_Tank& tank);
};
