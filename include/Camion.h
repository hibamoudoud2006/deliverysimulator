#ifndef CAMION_H
#define CAMION_H

#include "Transporteur.h"

class Camion : public Transporteur {
public:
    Camion();
    bool canDeliver(const Colis& colis) const override;
    double computeCost(const Colis& colis, double distance) const override;
    double computeTime(const Colis& colis, double distance) const override;
};

#endif
