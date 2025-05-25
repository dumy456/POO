/*
#include <iostream>
#include <array>

int main() {
    std::cout << "Hello, world!\n";
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
   /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de  intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for(int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    return 0;
}
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include "obiect.h"
#include "entitate.h"
#include "locatie.h"
#include "inventar.h"
#include "actiune.h"

int main()
{
    std::cout<<"Bine ai venit! Cum te numesti?"<<std::endl;
    Jucator jucator1;
    std::cin>>jucator1;
    std::cout<<jucator1<<std::endl;
    std::cout<<"Te-ai trezit intr-o lume necunoscuta, in care trebuie sa supravietuiesti si sa te lupti cu inamici. Incepe aventura ta!"<<std::endl;
    Locatie locatiecurenta;
    Locatie campia("Campia Inceputurilor","In jurul tau vezi o campie intinsa, iar in departare in nord se zareste o padure intunecata.  In sud poti vedea un fum care se ridica deasupra unui deal, iar in est se afla un sat micut.");
    locatiecurenta=campia; 
    Locatie padure("Padurea Strigoilor","Te invarti intr-o padure intunecata, unde copacii sunt atat de inalti incat nu poti vedea cerul. In jurul tau, poti auzi sunete ciudate si vezi umbre miscandu-se printre copaci. In vest, poti vedea o pestera intunecata, iar in sud se afla campia unde ai inceput aventura ta. Din vest, auzi un paraias care curge.");
    Locatie pestera("Pestera Ursului ", "In fata ta se afla o pestera intunecata. In interior, poti auzi un zgomot infricosator si vezi niste oase pe jos.");
    Locatie mister;
    Locatie sat("Satul Linistit","Te afli intr-un sat micut, unde oamenii par prietenosi. In centru, poti vedea o piata unde se vand diverse obiecte si potiuni. In est, poti vedea o casa mare, iar in sud se afla o carciuma unde poti sa te odihnesti.");
    pestera.adaugareiesire("vest",&mister);
    locatiecurenta.adaugareiesire("nord",&padure);
    pestera.adaugareiesire("nord",&padure);
    padure.adaugareiesire("sud",&pestera);
    jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie", 3, 5));
    jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie", 1, 5));
    jucator1.getinventar().adaugaobiect(std::make_unique<Potiune>("Potiune", 2, 10));
    jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Scimitar", 1, 10));
    jucator1.getinventar().adaugaobiect(std::make_unique<Potiune>("Potiune2", 1, 15));
    Inamic inamic1("Goblin",50,7);
    int inamic_activ=1;
    Actiune actiuni;
    std::string comanda;
    int armeechipate=0;
    while(true){
        int validarecomanda=0;
        actiuni.aratalocatiecurenta(&locatiecurenta);
        std::cout<<"Actiunea ta este ";
        std::cin>>comanda;
        if(comanda=="ajutor")
        {
            validarecomanda=1;
            std::cout<<"Comenzile disponibile sunt: mers, batalie, echipare, foloseste, inventar, informatii, oprire"<<std::endl;
        }
        if(comanda=="informatii")
        {
            validarecomanda=1;
            std::cout<<jucator1<<std::endl;
        }
        if(comanda=="oprire")
        {
            validarecomanda=1;
            std::cout<<"Multumesc ca ai jucat jocul!"<<std::endl;
            break;
        }
        if(comanda=="mers")
        {
            validarecomanda=1;
            std::cout<<"Poti merge in"<<std::endl;
            locatiecurenta.arataiesiri();
            std::string directie;
            std::cin>>directie;
            if(actiuni.miscajucator(directie,&locatiecurenta)==0)
                 std::cout<<"Nu poti merge in partea aia!"<<std::endl;
            else
                locatiecurenta=*locatiecurenta.getiesire(directie);
        }
        if(comanda=="batalie")
        {
            validarecomanda=1;
            actiuni.batalie(jucator1,inamic1);
        }
        if(comanda=="echipare")
        {
            validarecomanda=1;
            std::cout<<"Introduceti numele armei pe care doriti sa o echipati: ";
            std::string numearma;
            std::cin>>numearma;
            auto& obiecte=jucator1.getinventar().getobiecte();
            int armagasita=0;
            if(armeechipate<1){

                for(int i=0;i<obiecte.size();i++)
                {
                    if(obiecte[i]->getnume()==numearma)
                    {
                        armagasita=1;
                        jucator1.echiparearma(dynamic_cast<Arma&>(*obiecte[i]));
                        std::cout<<"Arma a fost echipata!"<<std::endl;
                        armeechipate++;
                        if(obiecte[i]->getnumar()>1)
                        {
                            obiecte[i]->modificanumar();
                            break;
                        }
                        else{
                                obiecte.erase(obiecte.begin()+i);
                                break;
                        }
                    }
                }
                if(armagasita==0)   
                {
                    std::cout<<"Arma nu exista in inventar!"<<std::endl;
                }
            }
            else
            {
                std::cout<<"Ai echipat deja 2 arme!"<<std::endl;
            }

        }
        if(comanda=="dezechipare")
        {
            validarecomanda=1;
            if(armeechipate>0)
            {
                jucator1.setputere(10);
                armeechipate--;
                std::cout<<"Arma a fost dezechipata!"<<std::endl;
            }
            else
            {
                std::cout<<"Nu ai nicio arma echipata!"<<std::endl;
            }
        }
            
            
        if(comanda=="foloseste")
        {
            validarecomanda=1;
            std::cout<<"Introduceti numele potiunii pe care doriti sa o folositi: ";
            std::string numepotiune;
            std::cin>>numepotiune;
            int potiunegasita=0;
            auto& obiecte=jucator1.getinventar().getobiecte();
            for(int i=0;i<obiecte.size();i++)
            {
                if(obiecte[i]->getnume()==numepotiune)
                {
                    potiunegasita=1;
                    jucator1.folosestePotiune(dynamic_cast<Potiune&>(*obiecte[i]));
                    std::cout<<"Potiunea a fost consumata!"<<std::endl;
                    if(obiecte[i]->getnumar()>1)
                    {
                        obiecte[i]->modificanumar();
                        break;
                    }
                    else{
                            obiecte.erase(obiecte.begin()+i);
                            break;
                    }
                }
            }
            if(potiunegasita==0)   
            {
                std::cout<<"Potiunea nu exista in inventar!"<<std::endl;
            }
        }
        if(comanda=="inventar")
        {
            validarecomanda=1;
            auto & obiecte=jucator1.getinventar().getobiecte();
            for(int i=0;i<obiecte.size();i++)
            {
                for(int j=i+1;j<obiecte.size();)
                {
                    if(*obiecte[i]==*obiecte[j])
                    {
                        *obiecte[i]=*obiecte[i]+*obiecte[j];
                        obiecte.erase(obiecte.begin()+j);
                    }
                    else 
                    {
                        j++;
                    }
                }
            }
            std::sort(obiecte.begin(), obiecte.end(), [](const std::unique_ptr<Obiect>& a, const std::unique_ptr<Obiect>& b) {
                if(auto armaA=dynamic_cast<Arma*>(a.get()))
                    if(auto armaB=dynamic_cast<Arma*>(b.get()))
                        return armaA->getputerebonus() > armaB->getputerebonus();
                    else
                        return true;
                if(auto potiuneA=dynamic_cast<Potiune*>(a.get()))
                    if(auto potiuneB=dynamic_cast<Potiune*>(b.get()))
                        return potiuneA->getviatavindecata() > potiuneB->getviatavindecata();
                    else
                        return false;
                return false;
            });
            std::cout<<"Inventarul tau este: "<<std::endl;
            jucator1.getinventar().afisareinventar();
        }
        if(jucator1.getviata()==0)
        {
            std::cout<<"Ai murit!"<<std::endl;
            std::cout<<"Sfarsitul jocului!"<<std::endl;
            return 0;
        }
        if (validarecomanda==0) {
            std::cout<<"Comanda invalida!"<<std::endl;
        }
    }
  
    return 0;
}
