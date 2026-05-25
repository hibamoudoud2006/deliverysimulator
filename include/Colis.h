#ifndef COLIS_H
#define COLIS_H

#include <string>
#include "Dimensions.h"
#include "Adresse.h"

enum class TypeColis { STANDARD, FRAGILE, DANGEREUX };

class Colis {
public:
    std::string id;
    double poids;
    Dimensions dimensions;
    TypeColis type;
    Adresse expediteur;
    Adresse destinataire;

    Colis(std::string id, double p, Dimensions d, TypeColis t, Adresse exp, Adresse dest);
    std::string typeToString() const;
};

#endif
