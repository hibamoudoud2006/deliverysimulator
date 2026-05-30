#ifndef VELO_H
#define VELO_H

#include "Transporteur.h"

class Velo : public Transporteur {
public:
    Velo();
    bool canDeliver(const Colis& colis) const override;
    double computeCost(const Colis& colis, double distance) const override;
    double computeTime(const Colis& colis, double distance) const override;
};

#endif
