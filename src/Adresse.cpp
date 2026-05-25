#include "Adresse.h"

Adresse::Adresse(std::string r, std::string v, std::string cp, std::string p)
    : rue(r), ville(v), codePostal(cp), pays(p) {}

std::string Adresse::toString() const {
    return rue + ", " + ville + " " + codePostal + ", " + pays;
}
