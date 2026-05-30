#ifndef DRONE_H
#define DRONE_H

#include "Transporteur.h"

class Drone : public Transporteur {
public:
    Drone();
    bool canDeliver(const Colis& colis) const override;
    double computeCost(const Colis& colis, double distance) const override;
    double computeTime(const Colis& colis, double distance) const override;
};

#endif
