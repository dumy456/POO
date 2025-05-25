#pragma once
#include <string>
#include <map>
#include <iostream>

class Locatie {
private:
    std::string nume;
    std::string descriere;
    int vizitat;
    std::map<std::string, Locatie*> iesiri;
public:
    Locatie(std::string n, std::string d);
    Locatie();
    std::string getnume() const;
    std::string getdescriere() const;
    std::string setnume(std::string n);
    std::string setdescriere(std::string d);
    int setvizitat();
    int getvizitat() const;
    void adaugareiesire(std::string directie, Locatie* destinatie);
    void textdescriere() const;
    Locatie* getiesire(std::string directie);
    void arataiesiri() const;
    ~Locatie();
};