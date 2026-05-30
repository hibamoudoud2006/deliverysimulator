#ifndef TRANSPORTEUR_H
#define TRANSPORTEUR_H

#include <string>
#include "Colis.h"

class Transporteur {
protected:
    std::string nom;
    double vitesseMoyenne; // km/h
    double capaciteMaximale; // kg

public:
    Transporteur(std::string n, double v, double c);
    virtual ~Transporteur() = default;

    std::string getNom() const { return nom; }

    virtual bool canDeliver(const Colis& colis) const = 0;
    virtual double computeCost(const Colis& colis, double distance) const = 0;
    virtual double computeTime(const Colis& colis, double distance) const = 0;
};

#endif
