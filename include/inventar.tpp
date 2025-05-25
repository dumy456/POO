#include "obiect.h"
template <typename T>
Inventar<T>::Inventar(int c) : capacitatemaxima(c) {}

template <typename T>
int Inventar<T>::getcapacitatemaxima() const { return capacitatemaxima; }

template <typename T>
std::vector<std::unique_ptr<T>>& Inventar<T>::getobiecte() { return obiecte; }

template <typename T>
bool Inventar<T>::esteplin() const { return obiecte.size() >= capacitatemaxima; }

template <typename T>
void Inventar<T>::adaugaobiect(std::unique_ptr<T> ob) {
    if (!esteplin()) {
        obiecte.push_back(std::move(ob));
    } else {
        std::cout << "Inventarul este plin!" << std::endl;
    }
}

template <typename T>
void Inventar<T>::afisareinventar() const {
    for (const auto& ob : obiecte) {
        std::cout << ob->getnume() << " " << ob->getnumar() << ", ";
        if (auto arma = dynamic_cast<Arma*>(ob.get()))
            std::cout << "Putere bonus oferita: " << arma->getputerebonus() << std::endl;
        if (auto potiune = dynamic_cast<Potiune*>(ob.get()))
            std::cout << "Viata vindecata: " << potiune->getviatavindecata() << std::endl;
    }
}

template <typename T>
Inventar<T>::~Inventar() {
    std::cout << "Inventar fost distrus" << std::endl;
}