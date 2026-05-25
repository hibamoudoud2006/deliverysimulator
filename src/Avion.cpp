#include "Avion.h"

Avion::Avion() : Transporteur("Avion", 800.0, 50000.0) {}

bool Avion::canDeliver(const Colis& colis) const {
    return colis.poids <= capaciteMaximale;
}

double Avion::computeCost(const Colis& colis, double distance) const {
    double base = 100.0 + (0.05 * distance * colis.poids);
    if (colis.type == TypeColis::FRAGILE) base *= 1.2;
    return base;
}

double Avion::computeTime(const Colis& colis, double distance) const {
    return (distance / vitesseMoyenne) + 2.0; // +2h pour la logistique aéroportuaire
}
