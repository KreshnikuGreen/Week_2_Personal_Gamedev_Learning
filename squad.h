#pragma once
#include "soldier.h"
#include <vector>

struct Squad{
    std::string             Name;
    int                     Max_Size;
    std::vector<Soldier>    Members;

    Squad(std::string nM, int mS):
        Name(nM),
        Max_Size(mS)
    {}

    void                    remove_member(int index);
    void                    get_size()  const;
    bool                    is_wiped()  const;
    void                    check_member_health();
    std::string             assign_name();
};

Squad create_squad(const std::string& Name, size_t Size);
