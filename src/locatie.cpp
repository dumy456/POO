#include "locatie.h"

Locatie::Locatie(std::string n, std::string d) : nume(n), descriere(d), vizitat(0) {}
Locatie::Locatie() : nume("o locatie necunoscuta"), descriere("Nu poti distinge nimic in jurul tau!"), vizitat(false){}
const std::string& Locatie::getnume() const { return nume; }
std::string Locatie::setnume(const std::string& n) { nume=n; return nume;}
std::string Locatie::setdescriere(const std::string& d) { descriere=d;  return descriere; } 
void Locatie::adaugareiesire(const std::string& directie, Locatie* destinatie) { iesiri[directie] = destinatie; }
void Locatie::textdescriere() const {
    std::cout << "Te afli in " << nume << std::endl;
    std::cout << descriere << std::endl;
}
int Locatie::setvizitat() {
    vizitat++;
    return vizitat;
}
int Locatie::getvizitat()const{
    return vizitat;
}
Locatie* Locatie::getiesire(std::string directie) {
    auto it = iesiri.find(directie);
    if (it != iesiri.end()) return iesiri[directie];
    else return NULL;
}
void Locatie::arataiesiri() const {
    for (const auto& d : iesiri) std::cout << d.first << " ";
    std::cout << std::endl;
}

Locatie::~Locatie() { std::cout << "Locatia fost distrusa" << std::endl; }