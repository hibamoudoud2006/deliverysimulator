# Projet 4 : Simulateur de Système de Livraison

## Conception de l'Architecture et des Classes

Ce document décrit la conception architecturale et les classes principales du simulateur de système de livraison. L'objectif est de modéliser une entreprise de livraison gérant différents types de colis et de transporteurs, avec un calcul des coûts, des délais et un suivi logistique. Un défi avancé consiste à implémenter un système d'attribution automatique des transporteurs basé sur le polymorphisme.

### 1. Entités Principales

Nous identifierons les entités clés du système et leurs attributs.

#### 1.1. Colis

Représente un article à livrer. Ses caractéristiques influencent le choix du transporteur et le coût.

**Attributs :**
- `ID` (chaîne de caractères unique)
- `Poids` (double, en kg)
- `Dimensions` (objet `Dimensions`, incluant `Longueur`, `Largeur`, `Hauteur` en cm)
- `Type` (énumération : `FRAGILE`, `STANDARD`, `DANGEREUX`)
- `AdresseExpediteur` (objet `Adresse`)
- `AdresseDestinataire` (objet `Adresse`)

#### 1.2. Adresse

Représente une adresse physique pour l'expédition et la livraison.

**Attributs :**
- `Rue` (chaîne de caractères)
- `Ville` (chaîne de caractères)
- `CodePostal` (chaîne de caractères)
- `Pays` (chaîne de caractères)

#### 1.3. Transporteur (Classe Abstraite)

Classe de base abstraite pour tous les types de transporteurs. Elle définira l'interface polymorphique.

**Attributs :**
- `Nom` (chaîne de caractères)
- `VitesseMoyenne` (double, en km/h)
- `CapaciteMaximale` (double, en kg)

**Méthodes Abstraites :**
- `canDeliver(Colis colis)` : Retourne `true` si le transporteur peut livrer le colis, `false` sinon.
- `computeCost(Colis colis, double distance)` : Calcule le coût de livraison pour un colis donné sur une distance donnée.
- `computeTime(Colis colis, double distance)` : Calcule le temps de livraison pour un colis donné sur une distance donnée.

#### 1.4. Transporteurs Concrets

Ces classes hériteront de `Transporteur` et implémenteront les méthodes abstraites.

- **Vélo**
  - Spécificités : faible capacité, faible vitesse, coût bas, ne peut pas livrer de colis dangereux.
- **Camion**
  - Spécificités : haute capacité, vitesse moyenne, coût moyen, peut livrer tous types de colis.
- **Drone**
  - Spécificités : capacité moyenne, haute vitesse, coût élevé, limité par les dimensions et le poids, ne peut pas livrer de colis dangereux.
- **Avion**
  - Spécificités : très haute capacité, très haute vitesse, coût très élevé, pour les longues distances.

#### 1.5. Livraison

Représente une livraison spécifique d'un colis par un transporteur.

**Attributs :**
- `Colis` (objet `Colis`)
- `Transporteur` (pointeur vers `Transporteur`)
- `Statut` (énumération : `EN_ATTENTE`, `EN_TRANSIT`, `LIVRE`, `ANNULE`)
- `CoutEstime` (double)
- `DelaiEstime` (double)
- `DateDebut` (objet `Date`)
- `DateLivraisonEstimee` (objet `Date`)
- `DateLivraisonReelle` (objet `Date`, optionnel)

#### 1.6. SystemeDeLivraison

Gère l'ensemble du processus de livraison.

**Attributs :**
- `ListeColis` (vecteur de `Colis`)
- `ListeTransporteurs` (vecteur de pointeurs vers `Transporteur`)
- `ListeLivraisons` (vecteur de `Livraison`)

**Méthodes :**
- `ajouterColis(Colis colis)`
- `ajouterTransporteur(Transporteur transporteur)`
- `attribuerTransporteur(Colis colis)` : Utilise le polymorphisme pour trouver le meilleur transporteur.
- `mettreAJourStatut(Livraison livraison, Statut nouveauStatut)`
- `genererRapport()`

### 2. Relations entre les Classes

- `Colis` contient `Dimensions` et deux objets `Adresse`.
- `Livraison` contient un `Colis` et un pointeur vers un `Transporteur`.
- `SystemeDeLivraison` agrège des `Colis`, des `Transporteurs` et des `Livraisons`.
- Les transporteurs concrets (`Vélo`, `Camion`, `Drone`, `Avion`) héritent de `Transporteur`.

### 3. Polymorphisme pour l'Attribution des Transporteurs

La méthode `attribuerTransporteur` dans `SystemeDeLivraison` itérera sur la `ListeTransporteurs`. Pour chaque transporteur, elle appellera `canDeliver(colis)`, `computeCost(colis, distance)` et `computeTime(colis, distance)`. Grâce au polymorphisme, la bonne implémentation de ces méthodes sera appelée pour chaque type de transporteur sans avoir besoin de `if/else` ou `switch` sur le type de transporteur.

Le choix du 
