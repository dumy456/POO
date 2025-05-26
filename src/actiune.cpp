#include "actiune.h"
#include <iostream>

void Actiune::aratalocatiecurenta(Locatie* locatiecurenta) const {
    locatiecurenta->textdescriere();
}
int Actiune::miscajucator(std::string directie, Locatie* locatiecurenta) const {
    if (locatiecurenta->getiesire(directie) == NULL) return 0;
    else return 1;
}
void Actiune::batalie(Jucator &jucator, Inamic &inamic) {
    while (true) {
        jucator.atac(inamic);
        if (inamic.getviata() <= 0) {
            std::cout << inamic.getnume() << " a fost invins!" << std::endl;
            break;
        }
        inamic.atac(jucator);
        if (jucator.getviata() <= 0) {
            std::cout << jucator.getnume() << " a fost invins!" << std::endl;
            break;
        }
        if(inamic.getnume() == "Rege") {
            if(inamic.getviata()<=100 && inamic.getviata()>=65)
            std::cout << "'Nu te voi lasa sa distrugi regatul meu!' striga regele" << std::endl;
        }
    }
}
Actiune::~Actiune() { std::cout << "Actiune a fost distrus" << std::endl; }