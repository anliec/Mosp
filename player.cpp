#include "player.h"

Player::Player(std::vector<HoldableObject> bag, std::vector<Wearable> clothes, Weapon activeWeapon,\
               int level, Attributs attributs, std::vector<Attack> attacks, std::vector<Effect> effects,\
               int className, std::string livingName, Coordinate livingCoordinate):\
    Fighter(level,attributs,attacks,effects,className,livingName,livingCoordinate),\
    bag(bag), clothes(clothes), activeWeapon(activeWeapon)
{

}

void Player::updateAttributs()
{
    attributs = baseAttributs;
    for(int i=0 ; i<clothes.size() ; i++)
    {
        attributs += clothes.at(i).getAttributs();
    }
}
