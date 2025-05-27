#pragma once
#include <string>
#include <iostream>

class Obiect {
protected:
    std::string nume;
    int numar;
public:
    Obiect(std::string n, int nr);
    const std::string& getnume() const;
    int getnumar() const;
    void modificanumar();
    bool operator==(const Obiect& copie) const;
    Obiect operator+(const Obiect& copie) const;
    virtual ~Obiect();
};

class Arma : public Obiect {
    int puterebonus;
public:
    Arma(const std::string& n, int nr, int p);
    int getputerebonus() const;
};

class Potiune : public Obiect {
    int viatavindecata;
public:
    Potiune(const std::string& n, int nr, int v);
    int getviatavindecata() const;
};