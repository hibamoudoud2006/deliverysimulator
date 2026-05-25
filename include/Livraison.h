#ifndef LIVRAISON_H
#define LIVRAISON_H

#include "Colis.h"
#include "Transporteur.h"

enum class StatutLivraison { EN_ATTENTE, EN_TRANSIT, LIVRE, ANNULE };

class Livraison {
public:
    Colis colis;
    Transporteur* transporteur;
    StatutLivraison statut;
    double coutEstime;
    double delaiEstime;

    Livraison(Colis c, Transporteur* t, double cout, double delai);
    std::string statutToString() const;
};

#endif
