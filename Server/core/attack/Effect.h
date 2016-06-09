#ifndef EFFECT_H
#define EFFECT_H

#include <QJsonObject>

class Effect
{
public:
    Effect();

    QJsonObject toJson() const;
};

#endif // EFFECT_H
