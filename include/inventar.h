#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "obiect.h"
template <typename T>
class Inventar {
private:
std::vector<std::unique_ptr<T>> obiecte;
int capacitatemaxima;
public:
    Inventar(int c);
    int getcapacitatemaxima() const;
    std::vector<std::unique_ptr<T>>& getobiecte();
    bool esteplin() const;
    void adaugaobiect(std::unique_ptr<T> ob);
    void afisareinventar() const;
    ~Inventar();
};
#include "inventar.tpp"