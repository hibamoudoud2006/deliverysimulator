#ifndef DIMENSIONS_H
#define DIMENSIONS_H

class Dimensions {
public:
    double longueur;
    double largeur;
    double hauteur;

    Dimensions(double l, double w, double h);
    double volume() const;
};

#endif
