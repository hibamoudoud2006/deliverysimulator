#include "Drone.h"

Drone::Drone() : Transporteur("Drone", 60.0, 5.0) {}

bool Drone::canDeliver(const Colis& colis) const {
    return colis.poids <= capaciteMaximale && 
           colis.dimensions.longueur < 50 && 
           colis.dimensions.largeur < 50 && 
           colis.type != TypeColis::DANGEREUX;
}

double Drone::computeCost(const Colis& colis, double distance) const {
    return 15.0 + (1.0 * distance);
}

double Drone::computeTime(const Colis& colis, double distance) const {
    return distance / vitesseMoyenne;
}
