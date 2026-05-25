#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include "SystemeDeLivraison.h"
#include "Velo.h"
#include "Camion.h"
#include "Drone.h"
#include "Avion.h"

void afficherMenu() {
    std::cout << "\n--- SIMULATEUR DE SYSTEME DE LIVRAISON ---\n";
    std::cout << "1. Creer une nouvelle livraison\n";
    std::cout << "2. Mettre a jour les statuts de livraison\n";
    std::cout << "3. Generer le rapport logistique\n";
    std::cout << "4. Quitter\n";
    std::cout << "Choix : ";
}

int main() {
    SystemeDeLivraison systeme;

    // Initialisation des transporteurs
    systeme.ajouterTransporteur(std::make_unique<Velo>());
    systeme.ajouterTransporteur(std::make_unique<Camion>());
    systeme.ajouterTransporteur(std::make_unique<Drone>());
    systeme.ajouterTransporteur(std::make_unique<Avion>());

    int choix = 0;
    while (choix != 4) {
        afficherMenu();
        if (!(std::cin >> choix)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choix == 1) {
            std::string id, rue, ville, cp, pays;
            double poids, l, w, h, distance;
            int typeInt;

            std::cout << "ID du colis : "; std::cin >> id;
            std::cout << "Poids (kg) : "; std::cin >> poids;
            std::cout << "Dimensions (L W H en cm) : "; std::cin >> l >> w >> h;
            std::cout << "Type (0:Standard, 1:Fragile, 2:Dangereux) : "; std::cin >> typeInt;
            
            std::cout << "Adresse de destination (Rue Ville CP Pays) : ";
            std::cin >> rue >> ville >> cp >> pays;
            
            std::cout << "Distance de livraison (km) : "; std::cin >> distance;

            TypeColis type = static_cast<TypeColis>(typeInt);
            Adresse exp("123 Depot Central", "Paris", "75000", "France");
            Adresse dest(rue, ville, cp, pays);
            Colis nouveauColis(id, poids, Dimensions(l, w, h), type, exp, dest);

            if (systeme.creerLivraison(nouveauColis, distance)) {
                std::cout << "Livraison creee avec succes et transporteur attribue automatiquement.\n";
            } else {
                std::cout << "Erreur : Aucun transporteur n'est capable de livrer ce colis.\n";
            }
        } else if (choix == 2) {
            systeme.mettreAJourStatuts();
            std::cout << "Statuts mis a jour.\n";
        } else if (choix == 3) {
            systeme.genererRapport();
        }
    }

    std::cout << "Merci d'avoir utilise le simulateur. Au revoir !\n";
    return 0;
}
