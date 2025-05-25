#include "entitate.h"

Entitate::Entitate(std::string n, int h, int s) : nume(n), viata(h), putere(s) {}
Entitate::Entitate() = default;
std::string Entitate::getnume() const { return nume; }
int Entitate::getviata() const { return viata; }
int Entitate::getputere() const { return putere; }
void Entitate::setputere(int s) { putere = s;}
void Entitate::setviata(int v) { viata = v; }
void Entitate::ranire(int contorranire) {
    viata -= contorranire;
    if (viata <= 0) viata = 0;
}
void Entitate::atac(Entitate &ent) {
    std::cout << nume << " ataca " << ent.getnume() << std::endl;
    ent.ranire(putere);
    std::cout << ent.getnume() << " mai are " << ent.getviata() << " viata" << std::endl;
}


Jucator::Jucator(std::string n, int h, int s, int a) : Entitate(n, h, s), inventar(10), agilitate(a) {}
Jucator::Jucator() : Entitate("", 100, 10), inventar(10), agilitate(3) {}
int Jucator::getagilitate() const { return agilitate; }
Inventar<Obiect>& Jucator::getinventar() { return inventar; }
const Inventar<Obiect>& Jucator::getinventar() const { return inventar; }
void Jucator::atac(Entitate &ent) {
    std::cout << nume << " ataca " << ent.getnume() << std::endl;
    ent.ranire(putere);
    if (std::rand() % 10 < agilitate) {
        std::cout << "Lovire critica!" << std::endl;
        ent.ranire(5);
    }
    std::cout << ent.getnume() << " mai are " << ent.getviata() << " viata" << std::endl;
}
void Jucator::echiparearma(const Arma& arma) {
    putere += arma.getputerebonus();
    std::cout << "Ai echipat " << arma.getnume() << " (+" << arma.getputerebonus() << " putere). Putere curenta: " << putere << "\n";
}
void Jucator::folosestePotiune(const Potiune& potiune) {
    viata += potiune.getviatavindecata();
    if (viata > 100) viata = 100;
    std::cout << "Ai folosit " << potiune.getnume() << " (+" << potiune.getviatavindecata() << " viata). Viata curenta: " << viata << "\n";
}
std::ostream& operator<<(std::ostream& os, const Jucator& e) {
    os << "Nume: " << e.nume << ", Viata: " << e.viata << ", Putere: " << e.putere << ", Agilitate: " << e.agilitate;
    return os;
}
std::istream& operator>>(std::istream& is, Jucator& e) {
    std::cout << "Nume: "; is >> e.nume;
    return is;
}
Jucator::~Jucator() { std::cout << "Jucatorul a fost distrus" << std::endl; }


Inamic::Inamic(std::string n, int h, int s) : Entitate(n, h, s) {}
Inamic::Inamic(const Inamic& copie) : Entitate(copie) {}
Inamic& Inamic::operator=(const Inamic& copie) {
    if (this != &copie) {
        nume = copie.nume;
        viata = copie.viata;
        putere = copie.putere;
    }
    return *this;
}
void Inamic::atac(Entitate &ent) {
    std::cout << nume << " contraataca " << ent.getnume() << std::endl;
    ent.ranire(putere);
    std::cout << ent.getnume() << " mai are " << ent.getviata() << " viata" << std::endl;
}
Inamic::~Inamic() { std::cout << "Inamicul a fost distrus" << std::endl; }