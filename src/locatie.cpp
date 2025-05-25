#include "locatie.h"

Locatie::Locatie(std::string n, std::string d) : nume(n), descriere(d) {}
Locatie::Locatie() : nume("o locatie necunoscuta"), descriere("Nu poti distinge nimic in jurul tau!") {}
std::string Locatie::getnume() const { return nume; }
std::string Locatie::getdescriere() const { return descriere; }
std::string Locatie::setnume(std::string n) { nume=n; }
std::string Locatie::setdescriere(std::string d) { descriere=d;  }
void Locatie::adaugareiesire(std::string directie, Locatie* destinatie) { iesiri[directie] = destinatie; }
void Locatie::textdescriere() const {
    std::cout << "Te afli in " << nume << std::endl;
    std::cout << descriere << std::endl;
}
Locatie* Locatie::getiesire(std::string directie) {
    auto it = iesiri.find(directie);
    if (it != iesiri.end()) return iesiri[directie];
    else return NULL;
}
void Locatie::arataiesiri() const {
    for (auto& d : iesiri) std::cout << d.first << " ";
    std::cout << std::endl;
}
Locatie::~Locatie() { std::cout << "Locatia fost distrusa" << std::endl; }