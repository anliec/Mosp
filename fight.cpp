#include "fight.h"

Fight::Fight(const Map map, const std::vector<Fighter> &team1, const std::vector<Fighter> &team2):\
    map(map),team1(team1),team2(team2)
{

}

void Fight::addFighter(Fighter fighter, int teamNumber)
{
    if(teamNumber == 1)
    {
        team1.push_back(fighter);
    }
    else if(teamNumber == 2)
    {
        team2.push_back(fighter);
    }
}
