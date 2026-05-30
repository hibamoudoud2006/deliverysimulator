#include "Camion.h"

Camion::Camion() : Transporteur("Camion", 80.0, 2000.0) {}

bool Camion::canDeliver(const Colis& colis) const {
    return colis.poids <= capaciteMaximale;
}

double Camion::computeCost(const Colis& colis, double distance) const {
    double base = 10.0 + (0.1 * distance * colis.poids);
    if (colis.type == TypeColis::DANGEREUX) base *= 1.5;
    return base;
}

double Camion::computeTime(const Colis& colis, double distance) const {
    return distance / vitesseMoyenne;
}
