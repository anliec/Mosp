#include "attributs.h"

Attributs::Attributs()
{

}

///Methods:

void Attributs::applyAttackValues(Damage &damage) const
{
    for(int i=0; i<damage.getValues().size() ; i++)
    {
        for(int a=0 ; a<values.size() ; a++)
        {
            if(damage.getValues().at(i).getType() == values.at(a).getType() )
            {
                int newDamage = damage.getValues().at(i).getValue();
                newDamage += (newDamage * values.at(a).getValue()) / 100; //one value point -> add 1% damage
                damage.getValues().at(i).setValue(newDamage);
            }
        }
    }
}

void Attributs::applyAttackFixBonnus(Damage &damage) const
{
    for(int i=0; i<damage.getValues().size() ; i++)
    {
        for(int a=0 ; a<fixFightBonus.size() ; a++)
        {
            if(damage.getValues().at(i).getType() == fixFightBonus.at(a).getType() )
            {
                int newDamage = damage.getValues().at(i).getValue();
                newDamage += fixFightBonus.at(a).getValue(); //add fix attack bonnus
                damage.getValues().at(i).setValue(newDamage);
            }
        }
    }
}

void Attributs::applyAttackRelativeBonnus(Damage &damage) const
{
    for(int i=0; i<damage.getValues().size() ; i++)
    {
        for(int a=0 ; a<relativeFightBonus.size() ; a++)
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
    for(int i=0; i<damage.getValues().size() ; i++)
    {
        for(int a=0 ; a<fixResistances.size() ; a++)
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
    for(int i=0; i<damage.getValues().size() ; i++)
    {
        for(int a=0 ; a<relativeResistances.size() ; a++)
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
    for(int i=0 ; i<damage.getValues().size() ; i++)
    {
        live -= damage.getValues().at(i).getValue();
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

Attributs & Attributs::operator +(const Attributs & other) const
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






















