#ifndef ADRESSE_H
#define ADRESSE_H

#include <string>

class Adresse {
public:
    std::string rue;
    std::string ville;
    std::string codePostal;
    std::string pays;

    Adresse(std::string r, std::string v, std::string cp, std::string p);
    std::string toString() const;
};

#endif
