#include "Colis.h"

Colis::Colis(std::string id, double p, Dimensions d, TypeColis t, Adresse exp, Adresse dest)
    : id(id), poids(p), dimensions(d), type(t), expediteur(exp), destinataire(dest) {}

std::string Colis::typeToString() const {
    switch (type) {
        case TypeColis::STANDARD: return "Standard";
        case TypeColis::FRAGILE: return "Fragile";
        case TypeColis::DANGEREUX: return "Dangereux";
        default: return "Inconnu";
    }
}
