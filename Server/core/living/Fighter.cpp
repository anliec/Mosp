#include "Fighter.h"

Fighter::Fighter(int level, Attributs attributs, std::vector<Attack> attacks, std::vector<Effect> effects,\
                 int className, std::string livingName, Coordinate livingCoordinate):\
    Living(className,livingName,livingCoordinate),\
    level(level), attributs(attributs), attacks(attacks), effects(effects)
{

}

void Fighter::receiveDamages(Damage &damage)
{
    attributs.applyDefenseFixResistances(damage);
    attributs.applyDefenseRelativeResistances(damage);
    attributs.looseLiveFromDamage(damage);
}

Damage Fighter::useAttack(unsigned int attackNumber) const
{
    Damage ret = attacks.at(attackNumber).randomDamage();
    attributs.applyAttackRelativeBonnus(ret);
    attributs.applyAttackFixBonnus(ret);
    return ret;
}

QJsonObject Fighter::toJson() const
{
    QJsonObject json;
    json = Living::toJson();
    json.insert("level",level);
    json.insert("attributs",attributs.toJson());

    QJsonObject attacksArray;
    for(Attack a:attacks)
    {
        attacksArray.insert("attack",QJsonValue(a.toJson()));
    }
    json.insert("attacks",QJsonValue(attacksArray));

    QJsonObject effectsArray;
    for(Effect e:effects)
    {
        effectsArray.insert("effect",QJsonValue(e.toJson()));
    }
    json.insert("effects",QJsonValue(effectsArray));

    return json;
}
