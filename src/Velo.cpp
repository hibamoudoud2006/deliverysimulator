#include "Velo.h"

Velo::Velo() : Transporteur("Velo", 15.0, 20.0) {}

bool Velo::canDeliver(const Colis& colis) const {
    return colis.poids <= capaciteMaximale && colis.type != TypeColis::DANGEREUX;
}

double Velo::computeCost(const Colis& colis, double distance) const {
    return 2.0 + (0.5 * distance);
}

double Velo::computeTime(const Colis& colis, double distance) const {
    return distance / vitesseMoyenne;
}
