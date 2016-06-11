#ifndef ATTRIBUTS_H
#define ATTRIBUTS_H

#include <vector>
#include <QJsonObject>

#include "core/spec/value.h"
#include "core/attack/Damage.h"

class Attributs
{
public:
    ///Seters:
    void setLive(const int live);
    void setAtionPoint(const int actionPoint);
    void setMovePoint(const int movePoint);
    void setValues(const std::vector<Value> values);
    void setFixResistances(const std::vector<Value> fixResistances);
    void setRelativeResistances(const std::vector<Value> relativeResistances);
    void setFixFightBonus(const std::vector<Value> fixFightBonus);
    void setRelativeFightBonus(const std::vector<Value> relativeFightBonus);
    ///Geters:
    int getLive() const;
    int getAtionPoint() const;
    int getMovePoint() const;
    std::vector<Value> getValues() const;
    std::vector<Value> getFixResistances() const;
    std::vector<Value> getRelativeResistances() const;
    std::vector<Value> getFixFightBonus() const;
    std::vector<Value> getRelativeFightBonus() const;
    ///Methods:
    //methods appling the atributs to the attack's damage:
    void applyAttackValues(Damage &damage) const;
    //algo: the damages of every type is raised by one pourcent
    //      for each attributs' point of the same type.
    //      (also use powerBonnus)
    void applyAttackFixBonnus(Damage &damage) const;
    //algo: the damages of every type is raised by the quantity
    //      given in the attributs' fix damage bonnus.
    //      (also use fixDamageBonnus)
    void applyAttackRelativeBonnus(Damage &damage) const;
    //algo: the damages of every type is raised by one pourcent
    //      for each attributs' point of realative damage bonnus
    //      of the same type.
    void applyDefenseFixResistances(Damage &damage) const;
    //algo: the damages of every type is lowered by the quantity
    //      given in the attributs' fix resistance bonnus.
    void applyDefenseRelativeResistances(Damage &damage) const;
    //algo: the damages of every type is lowered by one pourcent
    //      for each attributs' point of realative resistance
    //      bonnus of the same type.
    void looseLiveFromDamage(const Damage &damage);
    //algo: get the live down by the quantity of each damage
    //      (don't apply any ressistances or bonnus)
    ///Operators:
    Attributs operator=(const Attributs & other);
    Attributs operator+(const Attributs & other) const;
    //algo: do the some of each values of the same type.
    Attributs operator+=(const Attributs & other);
    //algo: do the some of each values of the same type and
    //      put the result in the first/the current.
    ///Constructors:
    Attributs();

    QJsonObject toJson() const;

protected:
    int live;
    int actionPoint;
    int movePoint;
    //Attack modificator depanding on value type:
    std::vector<Value> values;
    std::vector<Value> fixResistances;
    std::vector<Value> relativeResistances;
    std::vector<Value> fixFightBonus;
    std::vector<Value> relativeFightBonus;
    //Attack modificator for each value type:
    int powerBonnus;
    int fixDamageBonnus;
};

#endif // ATTRIBUTS_H
