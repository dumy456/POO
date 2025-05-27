#pragma once
#include "locatie.h"
#include "entitate.h"

class Actiune {
public:
    Actiune() = default;
    void aratalocatiecurenta(Locatie* locatiecurenta) const;
    int miscajucator(std::string directie, Locatie* locatiecurenta) const;
    void batalie(Jucator &jucator, Inamic &inamic);
    void foloseste(Jucator &jucator1, int viatamax);
    void echipare(Jucator &jucator1, int &armeechipate);
    void mers(Locatie* &locatiecurenta);
    void inventar(Jucator &jucator1);
    void turneu(Jucator &jucator1, Locatie* &locatiecurenta, Inamic &bandit1, Inamic &bandit2, Inamic &bandit3, int &viatamax,int &armeechipate);
    void bataieurs(Jucator &jucator1, Inamic &urs, int &viatamax, Locatie* &locatiecurenta);
    void bataiestrigoi(Jucator &jucator1, Inamic &strigoi, int &viatamax, Locatie* &locatiecurenta);
    ~Actiune();
};