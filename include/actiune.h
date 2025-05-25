#pragma once
#include "locatie.h"
#include "entitate.h"

class Actiune {
public:
    Actiune() = default;
    void aratalocatiecurenta(Locatie* locatiecurenta) const;
    int miscajucator(std::string directie, Locatie* locatiecurenta) const;
    void batalie(Jucator &jucator, Inamic &inamic);
    ~Actiune();
};