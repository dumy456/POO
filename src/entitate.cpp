#include "entitate.h"
#include "eroarenume.h"
Entitate::Entitate(std::string n, int h, int s) : nume(n), viata(h), putere(s) {}
Entitate::Entitate() : viata(0), putere(0){}
const std::string& Entitate::getnume() const { return nume; }
int Entitate::getviata() const { return viata; }
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
Entitate::~Entitate(){
    std::cout << "Entitatea a fost distrusa" << std::endl;
};


Jucator::Jucator(const std::string& n, int h, int s, int a) : Entitate(n, h, s), inventar(10), agilitate(a) {}
Jucator::Jucator() : Entitate("", 100, 10), inventar(10), agilitate(3) {}
Inventar<Obiect>& Jucator::getinventar() { return inventar; }
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
void Jucator::folosestePotiune(const Potiune& potiune, int viatamax) {
    viata += potiune.getviatavindecata();
    if (viata > viatamax) viata = viatamax;
    std::cout << "Ai folosit " << potiune.getnume() << " (+" << potiune.getviatavindecata() << " viata). Viata curenta: " << viata << "\n";
}
std::ostream& operator<<(std::ostream& os, const Jucator& e) {
    os << "Nume: " << e.nume << ", Viata: " << e.viata << ", Putere: " << e.putere << ", Agilitate: " << e.agilitate;
    return os;
}
std::istream& operator>>(std::istream& is, Jucator& e) {
    std::cout << "Nume: ";
    std::getline(is, e.nume);
    if (e.nume.find_first_not_of(" \t\n\r") == std::string::npos)
        throw Eroarenume("Numele jucatorului nu poate fi gol!");

    return is;
}


int Inamic::numar_inamici = 0;
Inamic::Inamic(const std::string& n, int h, int s) : Entitate(n, h, s) { numar_inamici++; }
Inamic::Inamic(const Inamic& copie) : Entitate(copie) {}
Inamic& Inamic::operator=(const Inamic& copie) {
    if (this != &copie) {
        nume = copie.nume;
        viata = copie.viata;
        putere = copie.putere;
    }
    return *this;
}
int Inamic::getnumar_inamici() {
    return numar_inamici;
}
void Inamic::atac(Entitate &ent) {
    std::cout << nume << " contraataca " << ent.getnume() << std::endl;
    ent.ranire(putere);
    std::cout << ent.getnume() << " mai are " << ent.getviata() << " viata" << std::endl;
}