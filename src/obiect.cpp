#include "obiect.h"

Obiect::Obiect(std::string n, int nr) : nume(n), numar(nr) {}
std::string Obiect::getnume() const { return nume; }
int Obiect::getnumar() const { return numar; }
void Obiect::modificanumar() { numar--; }
bool Obiect::operator==(const Obiect& copie) const { return nume == copie.nume; }
Obiect Obiect::operator+(const Obiect& copie) const {
    if (nume == copie.nume) return Obiect(nume, numar + copie.numar);
    return Obiect(nume, numar);
}
Obiect::~Obiect() { std::cout << "Obiectul a fost distrus!" << std::endl; }

Arma::Arma(std::string n, int nr, int p) : Obiect(n, nr), puterebonus(p) {}
int Arma::getputerebonus() const { return puterebonus; }

Potiune::Potiune(std::string n, int nr, int v) : Obiect(n, nr), viatavindecata(v) {}
int Potiune::getviatavindecata() const { return viatavindecata; }