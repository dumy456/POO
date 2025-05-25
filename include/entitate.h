#pragma once
#include <string>
#include "inventar.h"
#include "obiect.h"
#include <iostream>

class Entitate {
protected:
    std::string nume;
    int viata;
    int putere;
public:
    Entitate(std::string n, int h, int s);
    Entitate();
    std::string getnume() const;
    int getviata() const;
    int getputere() const;
    void setputere( int s);
    void ranire(int contorranire);
    virtual void atac(Entitate &ent);
    virtual ~Entitate() = default;
};

class Jucator : public Entitate {
private:
    int agilitate;
    Inventar<Obiect> inventar;
public:
    Jucator(std::string n, int h, int s, int a);
    Jucator();
    int getagilitate() const;
    Inventar<Obiect>& getinventar();
    const Inventar<Obiect>& getinventar() const;
    void atac(Entitate &ent) override;
    void echiparearma(const Arma& arma);
    void folosestePotiune(const Potiune& potiune);
    friend std::ostream& operator<<(std::ostream& os, const Jucator& e);
    friend std::istream& operator>>(std::istream& is, Jucator& e);
    ~Jucator();
};

class Inamic : public Entitate {
public:
    Inamic(std::string n, int h, int s);
    Inamic(const Inamic& copie);
    Inamic& operator=(const Inamic& copie);
    void atac(Entitate &ent) override;
    ~Inamic();
};