#include "Player.h"

Player::Player(Bag bag, std::vector<Wearable> clothes, Weapon activeWeapon,\
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

QJsonObject Player::toJson() const
{
    QJsonObject json;
    json = Fighter::toJson();
    json.insert("baseAttributs",baseAttributs.toJson());
    json.insert("bagId",bag.getId());
    json.insert("activeWeapon",activeWeapon.toJson());

    QJsonArray clothesArray;
    for(Wearable w:clothes)
    {
        clothesArray.insert("attack",QJsonValue(w.toJson()));
    }
    json.insert("attacks",QJsonValue(clothesArray));

    return json;
}
