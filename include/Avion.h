#ifndef AVION_H
#define AVION_H

#include "Transporteur.h"

class Avion : public Transporteur {
public:
    Avion();
    bool canDeliver(const Colis& colis) const override;
    double computeCost(const Colis& colis, double distance) const override;
    double computeTime(const Colis& colis, double distance) const override;
};

#endif
