#include "SystemeDeLivraison.h"
#include <iostream>
#include <iomanip>
#include <limits>

void SystemeDeLivraison::ajouterTransporteur(std::unique_ptr<Transporteur> t) {
    transporteurs.push_back(std::move(t));
}

bool SystemeDeLivraison::creerLivraison(const Colis& colis, double distance) {
    Transporteur* meilleurTransporteur = nullptr;
    double coutMinimal = std::numeric_limits<double>::max();
    double delaiCorrespondant = 0;

    // Défi avancé : Attribution automatique par polymorphisme
    for (const auto& t : transporteurs) {
        if (t->canDeliver(colis)) {
            double cout = t->computeCost(colis, distance);
            if (cout < coutMinimal) {
                coutMinimal = cout;
                meilleurTransporteur = t.get();
                delaiCorrespondant = t->computeTime(colis, distance);
            }
        }
    }

    if (meilleurTransporteur) {
        livraisons.emplace_back(colis, meilleurTransporteur, coutMinimal, delaiCorrespondant);
        return true;
    }
    return false;
}

void SystemeDeLivraison::mettreAJourStatuts() {
    for (auto& l : livraisons) {
        if (l.statut == StatutLivraison::EN_ATTENTE) {
            l.statut = StatutLivraison::EN_TRANSIT;
        } else if (l.statut == StatutLivraison::EN_TRANSIT) {
            l.statut = StatutLivraison::LIVRE;
        }
    }
}

const std::vector<Livraison>& SystemeDeLivraison::getLivraisons() const {
    return livraisons;
}

void SystemeDeLivraison::genererRapport() const {
    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << std::setw(40) << "RAPPORT LOGISTIQUE DE LIVRAISON" << "\n";
    std::cout << std::string(80, '=') << "\n";
    std::cout << std::left << std::setw(10) << "ID Colis" 
              << std::setw(15) << "Transporteur" 
              << std::setw(15) << "Statut" 
              << std::setw(15) << "Cout" 
              << std::setw(15) << "Delai (h)" << "\n";
    std::cout << std::string(80, '-') << "\n";

    for (const auto& l : livraisons) {
        std::cout << std::left << std::setw(10) << l.colis.id 
                  << std::setw(15) << l.transporteur->getNom() 
                  << std::setw(15) << l.statutToString() 
                  << std::setw(15) << std::fixed << std::setprecision(2) << l.coutEstime 
                  << std::setw(15) << l.delaiEstime << "\n";
    }
    std::cout << std::string(80, '=') << "\n";
}
