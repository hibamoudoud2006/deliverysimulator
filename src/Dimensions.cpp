#include "Dimensions.h"

Dimensions::Dimensions(double l, double w, double h) : longueur(l), largeur(w), hauteur(h) {}

double Dimensions::volume() const {
    return longueur * largeur * hauteur;
}
