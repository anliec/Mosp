#ifndef FIGHT_H
#define FIGHT_H

#include <vector>

#include "Map.h"
#include "fighter.h"

class Fight
{
public:
    void addFighter(Fighter fighter, int teamNumber = 1);

    Fight(const Map map,const std::vector<Fighter> & team1,const std::vector<Fighter> & team2);

protected:
    Map map;
    std::vector<Fighter> team1;
    std::vector<Fighter> team2;
};

#endif // FIGHT_H
