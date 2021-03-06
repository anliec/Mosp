#include "Attributs.h"

#include <QJsonArray>

Attributs::Attributs()
{
    live=0;
    actionPoint=0;
    movePoint=0;
    powerBonnus=0;
    fixDamageBonnus=0;
}

///Methods:

void Attributs::applyAttackValues(Damage &damage) const
{
    for(unsigned i=0; i<damage.getValues().size() ; i++)
    {
        int newDamage = damage.getValues().at(i).getValue();
        int damageBonnus = powerBonnus;
        for(unsigned a=0 ; a<values.size() ; a++)
        {
            if(damage.getValues().at(i).getType() == values.at(a).getType() )
            {
                damageBonnus += values.at(a).getValue(); //one value point -> add 1% damage
                //exit for loop: (there are only one couple)
                a = values.size();
            }
        }
        newDamage += newDamage*damageBonnus/100;
        damage.getValues().at(i).setValue(newDamage);
    }
}

void Attributs::applyAttackFixBonnus(Damage &damage) const
{
    for(unsigned i=0; i<damage.getValues().size() ; i++)
    {
        int newDamage = damage.getValues().at(i).getValue();
        newDamage += fixDamageBonnus;
        for(unsigned a=0 ; a<fixFightBonus.size() ; a++)
        {
            if(damage.getValues().at(i).getType() == fixFightBonus.at(a).getType() )
            {
                newDamage += fixFightBonus.at(a).getValue(); //add fix attack bonnus
                //exit for loop: (there are only one couple)
                a = values.size();
            }
        }
        damage.getValues().at(i).setValue(newDamage);
    }
}

void Attributs::applyAttackRelativeBonnus(Damage &damage) const
{
    for(unsigned i=0; i<damage.getValues().size() ; i++)
    {
        for(unsigned a=0 ; a<relativeFightBonus.size() ; a++)
        {
            if(damage.getValues().at(i).getType() == relativeFightBonus.at(a).getType() )
            {
                int newDamage = damage.getValues().at(i).getValue();
                newDamage += (newDamage * relativeFightBonus.at(a).getValue()) / 100; //one value point -> add 1% damage
                damage.getValues().at(i).setValue(newDamage);
            }
        }
    }
}

void Attributs::applyDefenseFixResistances(Damage &damage) const
{
    for(unsigned i=0; i<damage.getValues().size() ; i++)
    {
        for(unsigned a=0 ; a<fixResistances.size() ; a++)
        {
            if(damage.getValues().at(i).getType() == fixResistances.at(a).getType() )
            {
                int newDamage = damage.getValues().at(i).getValue();
                newDamage -= fixResistances.at(a).getValue(); //add fix attack bonnus
                if(newDamage<0)
                {
                    newDamage = 0;
                }
                damage.getValues().at(i).setValue(newDamage);
            }
        }
    }
}

void Attributs::applyDefenseRelativeResistances(Damage &damage) const
{
    for(unsigned i=0; i<damage.getValues().size() ; i++)
    {
        for(unsigned a=0 ; a<relativeResistances.size() ; a++)
        {
            if(damage.getValues().at(i).getType() == relativeResistances.at(a).getType() )
            {
                int newDamage = damage.getValues().at(i).getValue();
                newDamage -= (newDamage * relativeResistances.at(a).getValue()) / 100; //one value point -> add 1% resistances
                if(newDamage<0)
                {
                    newDamage = 0;
                }
                damage.getValues().at(i).setValue(newDamage);
            }
        }
    }
}

void Attributs::looseLiveFromDamage(const Damage &damage)
{
    for(int i=0 ; i<damage.getMaxIndex() ; i++)
    {
        live -= damage.getValue(i).getValue();
    }
}

///Operators:

Attributs Attributs::operator =(const Attributs & other)
{
    live = other.live;
    actionPoint = other.actionPoint;
    movePoint = other.movePoint;
    values = other.values;
    fixFightBonus = other.fixFightBonus;
    fixResistances = other.fixResistances;
    relativeFightBonus = other.relativeFightBonus;
    relativeResistances = other.relativeResistances;
    return *this;
}

Attributs Attributs::operator +(const Attributs & other) const
{
    Attributs ret;
    ret.setLive(live + other.live);
    ret.setAtionPoint(actionPoint + other.actionPoint);
    ret.setMovePoint(movePoint + other.movePoint);
    ret.setValues(values + other.values);
    ret.setFixFightBonus(fixFightBonus + other.fixFightBonus);
    ret.setFixResistances(fixResistances + other.fixResistances);
    ret.setRelativeFightBonus(relativeFightBonus + other.relativeFightBonus);
    ret.setRelativeResistances(relativeResistances + other.relativeResistances);
    return ret;
}

Attributs Attributs::operator +=(const Attributs & other)
{
    *this = *this+other;
    return *this;
}

///Seters:
void Attributs::setLive(const int live)
{
    this->live = live;
}
void Attributs::setAtionPoint(const int actionPoint)
{
    this->actionPoint = actionPoint;
}
void Attributs::setMovePoint(const int movePoint)
{
    this->movePoint = movePoint;
}
void Attributs::setValues(const std::vector<Value> values)
{
    this->values = values;
}
void Attributs::setFixResistances(const std::vector<Value> fixResistances)
{
    this->fixResistances = fixResistances;
}
void Attributs::setRelativeResistances(const std::vector<Value> relativeResistances)
{
    this->relativeResistances = relativeResistances;
}
void Attributs::setFixFightBonus(const std::vector<Value> fixFightBonus)
{
    this->fixFightBonus = fixFightBonus;
}
void Attributs::setRelativeFightBonus(const std::vector<Value> relativeFightBonus)
{
    this->relativeFightBonus = relativeFightBonus;
}

///Geters:
int Attributs::getLive() const
{
    return live;
}
int Attributs::getAtionPoint() const
{
    return actionPoint;
}
int Attributs::getMovePoint() const
{
    return movePoint;
}
std::vector<Value> Attributs::getValues() const
{
    return values;
}
std::vector<Value> Attributs::getFixResistances() const
{
    return fixResistances;
}
std::vector<Value> Attributs::getRelativeResistances() const
{
    return relativeResistances;
}
std::vector<Value> Attributs::getFixFightBonus() const
{
    return fixFightBonus;
}
std::vector<Value> Attributs::getRelativeFightBonus() const
{
    return relativeFightBonus;
}

QJsonObject Attributs::toJson() const
{
    QJsonObject json;
    json.insert("live", QJsonValue(live));
    json.insert("actionPoint", QJsonValue(actionPoint));
    json.insert("movePoint",QJsonValue(movePoint));
    json.insert("powerBonnus",QJsonValue(powerBonnus));
    json.insert("fixDamageBonnus",QJsonValue(fixDamageBonnus));

    QJsonArray valuesArray;
    for(Value v:values)
    {
        valuesArray.push_back(v.toJson());
    }
    json.insert("values",QJsonValue(valuesArray));

    QJsonArray fixResistancesArray;
    for(Value v:fixResistances)
    {
        fixResistancesArray.push_back(v.toJson());
    }
    json.insert("fixResistances",QJsonValue(fixResistancesArray));

    QJsonArray relativeResistancesArray;
    for(Value v:relativeResistances)
    {
        relativeResistancesArray.push_back(v.toJson());
    }
    json.insert("relativeResistances",QJsonValue(relativeResistancesArray));

    QJsonArray fixFightBonusArray;
    for(Value v:fixFightBonus)
    {
        fixFightBonusArray.push_back(v.toJson());
    }
    json.insert("fixFightBonus",QJsonValue(fixFightBonusArray));

    QJsonArray relativeFightBonusArray;
    for(Value v:relativeFightBonus)
    {
        relativeFightBonusArray.push_back(v.toJson());
    }
    json.insert("relativeFightBonus",QJsonValue(relativeFightBonusArray));
}




















