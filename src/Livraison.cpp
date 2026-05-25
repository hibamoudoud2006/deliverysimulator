#include "Livraison.h"

Livraison::Livraison(Colis c, Transporteur* t, double cout, double delai)
    : colis(c), transporteur(t), statut(StatutLivraison::EN_ATTENTE), coutEstime(cout), delaiEstime(delai) {}

std::string Livraison::statutToString() const {
    switch (statut) {
        case StatutLivraison::EN_ATTENTE: return "En attente";
        case StatutLivraison::EN_TRANSIT: return "En transit";
        case StatutLivraison::LIVRE: return "Livre";
        case StatutLivraison::ANNULE: return "Annule";
        default: return "Inconnu";
    }
}
