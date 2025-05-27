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
    const std::string& getnume() const;
    std::string setnume(const std::string& n);
    std::string setdescriere(const std::string& d);
    int setvizitat();
    int getvizitat() const;
    void adaugareiesire(const std::string& directie, Locatie* destinatie);
    void textdescriere() const;
    Locatie* getiesire(std::string directie);
    void arataiesiri() const;
    ~Locatie();
};