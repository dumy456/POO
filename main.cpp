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
    Locatie campia("Campia Inceputurilor","In jurul tau vezi o campie intinsa, iar in departare in nord se zareste o padure intunecata.  In sud poti vedea un fum care se ridica deasupra unui deal, iar in est se afla un sat micut.");
    Locatie padure("Padurea Strigoilor","Te invarti intr-o padure intunecata, unde copacii sunt atat de inalti incat nu poti vedea cerul. In jurul tau, poti auzi sunete ciudate si vezi umbre miscandu-se printre copaci. In est, poti vedea o pestera, iar in sud se afla campia unde ai inceput aventura ta. Din vest, auzi un paraias care curge.");
    Locatie pestera("Pestera Ursului", "In fata ta se afla o pestera intunecata. In interior, poti auzi un zgomot infricosator si vezi niste oase pe jos.");
    Locatie mister;
    Locatie sat("Satul Linistit","Te afli intr-un sat micut, unde oamenii par prietenosi. In centru, poti vedea o piata unde se vand diverse obiecte si potiuni. In est, poti vedea o casa mare, iar in sud se afla o carciuma unde poti sa te odihnesti.");
    Locatie tabarabandit("Tabara Banditilor","Te afli intr-o tabara a banditilor, unde poti vedea corturi si focuri de tabara. In jurul tau, banditii se pregatesc de lupta. In nord, poti vedea o campie intinsa.");
    Locatie rau("Raul Inundat","Te afli langa un rau care curge rapid. Apa este rece si tulbure, iar in jurul tau poti vedea pietre si copaci cazuti. In est, poti vedea o padure intunecata.");
    campia.adaugareiesire("nord",&padure);
    campia.adaugareiesire("sud",&tabarabandit);
    campia.adaugareiesire("est",&sat);
    padure.adaugareiesire("sud",&campia);
    padure.adaugareiesire("est",&pestera);
    padure.adaugareiesire("vest",&rau);
    pestera.adaugareiesire("vest",&padure);
    rau.adaugareiesire("est",&padure);
    tabarabandit.adaugareiesire("nord",&campia);
    sat.adaugareiesire("vest",&campia);
    Locatie* locatiecurenta=&campia;
    Inamic strigoi("Strigoi",90,8);
    Inamic urs("Urs",100,15);
    Inamic bandit1("Bandit",110,18);
    Inamic bandit2("Capitanul Bandit",115,23);
    Inamic bandit3("Regele Bandit",120,25);
    Actiune actiuni;
    std::string comanda;
    int armeechipate=0;
    int batuturs=0;
    int batutstrigoi=0;;
    int batutturneu=0;
    locatiecurenta->setvizitat();
    actiuni.aratalocatiecurenta(locatiecurenta);
    std::cout<<"Gasesti pe jos o sabie de lemn si o potiune de viata."<<std::endl;
    jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de lemn", 1, 1));
    jucator1.getinventar().adaugaobiect(std::make_unique<Potiune>("Potiune de viata", 1, 10));
    std::cout<<"Daca vrei sa echipezi sabia, scrie 'echipare'."<<std::endl;
    std::cout<<"Daca vrei sa folosesti potiunea, scrie 'foloseste'."<<std::endl;
    std::cout<<"Daca vrei sa vezi inventarul, scrie 'inventar'."<<std::endl;
    int validarecomanda=0;
    while(true){
        validarecomanda=0;
        if(locatiecurenta->getnume()=="Padurea Strigoilor" && strigoi.getviata()>0)
        {
            std::cout<<"Un strigoi te ataca!"<<std::endl;
            std::cout<<"Daca vrei sa te lupti cu el, scrie 'batalie'."<<std::endl;
            std::cout<<"Daca vrei sa fugi, scrie 'mers'."<<std::endl;
        }
        if(locatiecurenta->getnume()=="Pestera Ursului" && urs.getviata()>0)
        {
            std::cout<<"Un urs te ataca!"<<std::endl;
            std::cout<<"Daca vrei sa te lupti cu el, scrie 'batalie'."<<std::endl;
            std::cout<<"Daca vrei sa fugi, scrie 'mers'."<<std::endl;
        }
        if(locatiecurenta->getnume()=="Raul Inundat" && locatiecurenta->getvizitat()==0)
        {
            std::cout<<"Raul ofera oportunitatea de a te vindeca."<<std::endl;
            locatiecurenta->setvizitat();
            jucator1.getinventar().adaugaobiect(std::make_unique<Potiune>("Apa vindecatoare", 1, 100));
        }
        if(locatiecurenta->getnume()=="Tabara Banditilor" && locatiecurenta->getvizitat()==0)
        {
            locatiecurenta->setvizitat();
            std::cout<<"Banditii te observa si iti propun o provocare. Poti participa intr-un turneu si dupa fiecare stadiu primesti o recompensa."<<std::endl;
            std::cout<<"Turneul consta in 3 etape, fiecare cu un bandit diferit. Daca reusesti sa ii invingi pe toti, vei fi cunoscut drept Ucigasul de Banditi"<<std::endl;
            std::cout<<"Daca vrei sa participi, scrie 'batalie'."<<std::endl;
        }
        std::cout<<"Actiunea ta este ";
        std::cin>>comanda;
        if(comanda=="batalie"&& locatiecurenta->getnume()=="Padurea Strigoilor" && strigoi.getviata()>0)
        {
            validarecomanda=1;
            actiuni.batalie(jucator1,strigoi);      
            if(strigoi.getviata()==0)
            {
                batutstrigoi=1;
                locatiecurenta->setdescriere("Te afli in Padurea Strigoilor, dar acum este mai linistita.");
                std::cout<<"Ai invins strigoiul!"<<std::endl;
                std::cout<<"Te simti mai rezistent."<<std::endl;
                jucator1.setviata(110);
                std::cout<<jucator1<<std::endl;
                std::cout<<"Gasesti pe jos o sabie de lemn."<<std::endl;
                jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de lemn", 1, 1));
            }
        }
        if(comanda=="batalie"&& locatiecurenta->getnume()=="Pestera Ursului" && urs.getviata()>0)
        {
            validarecomanda=1;
            actiuni.batalie(jucator1,urs);      
            if(urs.getviata()==0)
            {
                batuturs=1;
                locatiecurenta->setdescriere("Te afli in Pestera Ursului, dar acum este mai linistita.");
                std::cout<<"Ai invins ursul!"<<std::endl;
                std::cout<<"Te simti mai rezistent."<<std::endl;
                jucator1.setviata(125);
                std::cout<<jucator1<<std::endl;
                std::cout<<"Gasesti pe jos o sabie de fier."<<std::endl;
                jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de fier", 1, 10));
            }
        }
        if(comanda=="batalie" && locatiecurenta->getnume()=="Tabara Banditilor" && bandit3.getviata()>0 && bandit2.getviata()==0)
        {
            validarecomanda=1;
            actiuni.batalie(jucator1,bandit3);
            if(bandit3.getviata()==0)
            {
                std::cout<<"Ai invins regele banditilor si ai primit o recompensa!"<<std::endl;
                std::cout<<"Te simti mai rezistent."<<std::endl;
                jucator1.setviata(150);
                std::cout<<"Felicitari! Ai terminat turneul si ai devenit Ucigasul de Banditi!"<<std::endl;
                std::cout<<jucator1<<std::endl;
                std::cout<<"Gasesti pe jos o potiune de viata mare si o sabie de diamant."<<std::endl;
                jucator1.getinventar().adaugaobiect(std::make_unique<Potiune>("Potiune de viata mare", 1, 50));
                jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de diamant", 1, 30));
                batutturneu=1;
                locatiecurenta->setdescriere("Te afli in Tabara Banditilor, dar acum este mai linistita.");
            }
        }
        if(comanda=="batalie" && locatiecurenta->getnume()=="Tabara Banditilor" && bandit2.getviata()>0 && bandit1.getviata()==0)
        {
    
            validarecomanda=1;
            actiuni.batalie(jucator1,bandit2);
            if(bandit2.getviata()==0)
            {
                std::cout<<"Ai invins capitanul banditilor si ai primit o recompensa!"<<std::endl;
                std::cout<<"Gasesti pe jos o sabie de argint."<<std::endl;
                jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de argint", 1, 20));
            }
        }
        if(comanda=="batalie" && locatiecurenta->getnume()=="Tabara Banditilor" && bandit1.getviata()>0)
        {
                validarecomanda=1;
                actiuni.batalie(jucator1,bandit1);
                if(bandit1.getviata()==0)
                {
                    std::cout<<"Ai invins banditul si ai primit o recompensa!"<<std::endl;
                    std::cout<<"Gasesti pe jos o potiune de viata."<<std::endl;
                    jucator1.getinventar().adaugaobiect(std::make_unique<Potiune>("Potiune de viata", 1, 50));
                }
        }
        if(comanda=="ajutor")
        {
            validarecomanda=1;
            std::cout<<"Comenzile disponibile sunt: mers, batalie, echipare, dezechipare, foloseste, inventar, informatii, oprire"<<std::endl;
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
            std::cout<<"Poti merge in"<<std::endl;
            locatiecurenta->arataiesiri();
            std::string directie;
            std::cin>>directie;
            if(actiuni.miscajucator(directie,locatiecurenta)==0)
                { std::cout<<"Nu poti merge in partea aia!"<<std::endl;
                    validarecomanda=1;}
            else{
                    locatiecurenta=locatiecurenta->getiesire(directie);
                    validarecomanda=1;
                }
            actiuni.aratalocatiecurenta(locatiecurenta);
        }
        if(comanda=="echipare")
        {
            std::cout<<"Introduceti numele armei pe care doriti sa o echipati: ";
            std::string numearma;
            std::getline(std::cin >> std::ws, numearma);
            auto& obiecte=jucator1.getinventar().getobiecte();
            int armagasita=0;
            if(armeechipate<1){

                for(size_t i=0;i<obiecte.size();i++)
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
                            validarecomanda=1;
                            break;
                        }
                        else{
                                obiecte.erase(obiecte.begin()+i);
                                validarecomanda=1;
                                break;
                        }
                    }
                }
                if(armagasita==0)   
                {
                    std::cout<<"Arma nu exista in inventar!"<<std::endl;
                    validarecomanda=1;
                }
            }
            else
            {
                std::cout<<"Ai echipat deja o arma!"<<std::endl;
                validarecomanda=1;
            }

        }
        if(comanda=="dezechipare")
        {

            if(armeechipate>0)
            {
                jucator1.setputere(10);
                armeechipate--;
                std::cout<<"Arma a fost distrusa!"<<std::endl;
                validarecomanda=1;
            }
            else
            {
                std::cout<<"Nu ai nicio arma echipata!"<<std::endl;
                validarecomanda=1;
            }
        }
            
            
        if(comanda=="foloseste")
        {
            std::cout<<"Introduceti numele potiunii pe care doriti sa o folositi: ";
            std::string numepotiune;
            std::getline(std::cin >> std::ws, numepotiune);
            int potiunegasita=0;
            auto& obiecte=jucator1.getinventar().getobiecte();
            for(size_t i=0;i<obiecte.size();i++)
            {
                if(obiecte[i]->getnume()==numepotiune)
                {
                    potiunegasita=1;
                    jucator1.folosestePotiune(dynamic_cast<Potiune&>(*obiecte[i]));
                    std::cout<<"Potiunea a fost consumata!"<<std::endl;
                    if(obiecte[i]->getnumar()>1)
                    {
                        obiecte[i]->modificanumar();
                        validarecomanda=1;
                        break;
                    }
                    else{
                            obiecte.erase(obiecte.begin()+i);
                            validarecomanda=1;
                            break;
                    }
                }
            }
            if(potiunegasita==0)   
            {
                std::cout<<"Potiunea nu exista in inventar!"<<std::endl;
                validarecomanda=1;
            }
        }
        if(comanda=="inventar")
        {
            validarecomanda=1;
            auto & obiecte=jucator1.getinventar().getobiecte();
            for(size_t i=0;i<obiecte.size();i++)
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
                if (auto armaA = dynamic_cast<Arma*>(a.get())) {
                        if (auto armaB = dynamic_cast<Arma*>(b.get())) {
                            return armaA->getputerebonus() > armaB->getputerebonus();
                        } else {
                            return true;
                        }
                }
                if(auto potiuneA=dynamic_cast<Potiune*>(a.get())){
                    if(auto potiuneB=dynamic_cast<Potiune*>(b.get())){
                        return potiuneA->getviatavindecata() > potiuneB->getviatavindecata();
                    }else{
                        return false;
                    }
                return false;
                }
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

    //if(batutturneu+)
    return 0;
}
