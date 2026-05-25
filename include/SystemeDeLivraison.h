#ifndef SYSTEME_DE_LIVRAISON_H
#define SYSTEME_DE_LIVRAISON_H

#include <vector>
#include <memory>
#include "Colis.h"
#include "Transporteur.h"
#include "Livraison.h"

class SystemeDeLivraison {
private:
    std::vector<std::unique_ptr<Transporteur>> transporteurs;
    std::vector<Livraison> livraisons;

public:
    void ajouterTransporteur(std::unique_ptr<Transporteur> t);
    bool creerLivraison(const Colis& colis, double distance);
    void mettreAJourStatuts();
    const std::vector<Livraison>& getLivraisons() const;
    void genererRapport() const;
};

#endif
