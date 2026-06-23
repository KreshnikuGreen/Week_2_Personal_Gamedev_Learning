#pragma once
#include <string>

struct Infantry_Ranged_Weapon{
    float       MASS;
    float       Muzzle_Velocity;
    int         Magazines;
    const int   MAX_AMMO;
    int         Ammo;
    const int   MAX_DAMAGE;
    bool        Is_Loaded;
    std::string Name;

    Infantry_Ranged_Weapon(float m, float mV, int mG, int mA, int a, int mD, bool loaded, std::string nM) : MASS(m), Muzzle_Velocity(mV), Magazines(mG), MAX_AMMO(mA), Ammo(a), MAX_DAMAGE(mD), Is_Loaded(loaded), Name(nM){}
    
    void reload();
    void fire();
};

struct Melee_Weapon{
    const int   MAX_DAMAGE;
    std::string Name;

    Melee_Weapon(int mD, std::string nM) : MAX_DAMAGE(mD), Name(nM){}

    void hit();
};

struct Repair_Kit{
    int         Repair_Amount;
    float       MASS;
    std::string Name;
    
    Repair_Kit(int rA, float m, std::string nM) : Repair_Amount(rA), MASS(m), Name(nM){}
};

struct Oxygen_Tank{
    const int   MAX_OXYGEN;
    int         Oxygen_Amount;
    float       MASS;
    std::string Name;

    Oxygen_Tank(int mO, int oA, float m, std::string nM) : MAX_OXYGEN(mO), Oxygen_Amount(oA), MASS(m), Name(nM){}
};

struct Suit{
    enum class  Armor_Type{
        Standard,
        Level_I,
        Level_II,
        Level_IIIA,
        Level_III,
        Level_IIIPlus,
        Level_IV
    };
    int         Suit_Integrity;
    const int   MAX_INTEGRITY;
    int         Oxygen;
    const int   MAX_OXYGEN;
    const float MASS;
    std::string Name;
    Armor_Type  armor_type;

    Suit(Armor_Type aT, int sI, int mI, int o, int mO, float m, std::string nM) : armor_type(aT), Suit_Integrity(sI), MAX_INTEGRITY(mI), Oxygen(o), MAX_OXYGEN(mO), MASS(m), Name(nM){}

    void Check_Integrity();
    void repair(Repair_Kit& kit);
    void Replenish_Oxygen(Oxygen_Tank& tank);
};

struct Boots{
    bool        State;

    Boots(bool s) : State(s){}

    void toggle();
};
