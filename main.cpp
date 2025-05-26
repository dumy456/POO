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
#include "eroarenume.h"
int main()
{
    std::cout<<"Bine ai venit! Cum te numesti?"<<std::endl;
    try{
        Jucator jucator1;
        std::cin>>jucator1;
        std::cout<<jucator1<<std::endl;
        std::cout<<"Te-ai trezit intr-o lume necunoscuta, in care trebuie sa supravietuiesti si sa te lupti cu inamici. Incepe aventura ta!"<<std::endl;
        Locatie campia("Campia Inceputurilor","In jurul tau vezi o campie intinsa, iar in departare in nord se zareste o padure intunecata.  In sud poti vedea un fum care se ridica deasupra unui deal, iar in est se afla un sat micut.");
        Locatie padure("Padurea Strigoilor","Te invarti intr-o padure intunecata, unde copacii sunt atat de inalti incat nu poti vedea cerul. In jurul tau, poti auzi sunete ciudate si vezi umbre miscandu-se printre copaci. In est, poti vedea o pestera, iar in sud se afla campia unde ai inceput aventura ta. Din vest, auzi un paraias care curge.");
        Locatie pestera("Pestera Ursului", "In fata ta se afla o pestera intunecata. In interior, poti auzi un zgomot infricosator si vezi niste oase pe jos.");
        Locatie mister;
        Locatie sat("Satul Linistit","Te afli intr-un sat micut, unde oamenii par prietenosi. La iesirea din est a satului vezi o carare care duce catre un castel impunator.");
        Locatie tabarabandit("Tabara Banditilor","Te afli intr-o tabara a banditilor, unde poti vedea corturi si focuri de tabara. In jurul tau, banditii se pregatesc de lupta. In nord, poti vedea o campie intinsa.");
        Locatie rau("Raul Inundat","Te afli langa un rau care curge rapid. Apa este rece si tulbure, iar in jurul tau poti vedea pietre si copaci cazuti. In est, poti vedea o padure intunecata.");
        Locatie castel("Castelul Impunator","Te afli inauntrul unui castel impunator, cu ziduri groase si turnuri inalte. In jurul tau, poti vedea arme si armuri vechi, iar in fata ta se afla o usa mare care duce catre o sala de tron.");
        Locatie tron("Tronul Regal","Te afli in sala de tron a castelului, unde poti vedea un tron mare si impunator. In fata ta vezi regele care te asteapta sa te ingenunchiezi.");
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
        sat.adaugareiesire("est", &castel);
        castel.adaugareiesire("vest", &sat);
        castel.adaugareiesire("usa", &tron);
        tron.adaugareiesire("usa", &castel);
        Locatie* locatiecurenta=&campia;
        Inamic strigoi("Strigoi",90,8);
        Inamic urs("Urs",100,15);
        Inamic bandit1("Bandit",110,18);
        Inamic bandit2("Capitanul Bandit",115,23);
        Inamic bandit3("Regele Bandit",120,25);
        Inamic demon("Demon", 150, 35);
        Inamic rege("Rege", 170, 37);
        int viatamax=100;
        Actiune actiuni;
        std::string comanda;
        int armeechipate=0;
        int batuturs=0;
        int batutstrigoi=0;;
        int batutturneu=0;
        int batutrege=0;
        int ascultatrege=0;
        int dezbaterea=0;
        int finalfericit=0;
        locatiecurenta->setvizitat();
        actiuni.aratalocatiecurenta(locatiecurenta);
        std::cout<<"Gasesti pe jos o sabie de lemn si o potiune de viata."<<std::endl;
        jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de lemn", 1, 1));
        jucator1.getinventar().adaugaobiect(std::make_unique<Potiune>("Potiune de viata", 1, 30));
        std::cout<<"Daca vrei sa echipezi sabia, scrie 'echipare'."<<std::endl;
        std::cout<<"Daca vrei sa folosesti potiunea, scrie 'foloseste'."<<std::endl;
        std::cout<<"Daca vrei sa vezi inventarul, scrie 'inventar'."<<std::endl;
        int validarecomanda=0;
        while(true){
            validarecomanda=0;
            if(locatiecurenta->getnume()=="Castelul Impunator" && dezbaterea==1 && demon.getviata()>0)
            {
                std::cout<<"'Nu trebuia sa te intorci aici! Nu ai respectat dorintele regelui! Acum vei muri!' striga un demon."<<std::endl;
                std::cout<<"Demonul te ataca!"<<std::endl;
                std::cout<<"Daca vrei sa te lupti cu el, scrie 'batalie'."<<std::endl;
                std::cout<<"Daca vrei sa fugi, scrie 'mers'."<<std::endl;
            }
            if(locatiecurenta->getnume()=="Campia Inceputurilor" && ascultatrege==1)
            {
                std::cout<<"Te afli in Campia Inceputurilor, locul unde a inceput totul. Aici trebuie sa te sacrifici pentru a salva regatul."<<std::endl;
                std::cout<<"In ultimele tale clipe te uiti la propria reflectie in sabie si iti dai seama ca ai facut tot ce ai putut pentru a supravietui. Stai pe ganduri daca actiunile tale au fost justificate sau haosul cauzat trebuie reparat prin sacrificiul suprem."<<std::endl;
                std::cout<<"'Cu ce a afectat venirea mea acest regat...? Nu exista alta solutie...?'"<<std::endl;
                std::cout<<"Daca vrei sa te sacrifici, scrie 'sacrificiu'."<<std::endl;
                std::cout<<"Daca vrei sa continui lupta, intoarce-te la castel si afla adevarul."<<std::endl;
                dezbaterea=1;
            }
            if(locatiecurenta->getnume()=="Tronul Regal" && locatiecurenta->getvizitat()==0)
            {
                locatiecurenta->setvizitat();
                std::cout<<"Te afli in fata regelui. Daca vrei sa te ingenunchezi, scrie 'ingenuncheaza'."<<std::endl;
                std::cout<<"Daca vrei sa te lupti cu el, scrie 'batalie'."<<std::endl;
            }
            if(locatiecurenta->getnume()=="Padurea Strigoilor" && strigoi.getviata()>0)
            {
                std::cout << "Strigoiul te priveste cu ochi reci. 'Poti lupta cu mine, dar nu stii ce vei descoperi. Sau poate nu vei descoperi nimic...'" << std::endl;
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
                std::cout<<"Iti pui in inventar o potiune de apa vindecatoare."<<std::endl;
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
            if(comanda=="sacrificiu" && dezbaterea==1 && locatiecurenta->getnume()=="Campia Inceputurilor")
            {
                validarecomanda=1;
                std::cout<<"Stai pe ganduri daca ai facut ceva sa meriti aceasta soarta, dar nu poti trai cu gandul ca ai cauzat atata distrugere."<<std::endl;
                std::cout<<"Te sacrifici pentru a salva regatul. In ultimele tale clipe, te gandesti la tot ce ai realizat si la tot ce ai invatat. Te simti impacat cu tine insuti si cu alegerile tale."<<std::endl;
                std::cout<<"Cine stie ce s-a intamplat cu regatul..."<<std::endl;
                jucator1.setviata(0);
            }
           if(locatiecurenta->getnume()=="Tronul Regal" && locatiecurenta->getvizitat()==1 && comanda=="ingenuncheaza" )
            {
                validarecomanda=1;
                std::cout<<"Regele te priveste cu niste ochi rosii plini de dispret. Acesta iti povesteste cum aparatia ta in regatul sau a lasat in urma numai moarte si distrugere"<<std::endl;
                std::cout<<"Acesta spune: 'Daca vrei sa iti speli pacatele du-te in locul de unde a inceput totul si sacrifica-te pentru a salva regatul de demonii care il bantuie.'"<<std::endl;
                ascultatrege=1;
            }
            if(locatiecurenta->getnume()=="Tronul Regal" && dezbaterea==0 && comanda=="batalie")
            {
                std::cout<<"Regele este surprins de atitudinea ta si te provoaca la lupta. Acesta isi ia sabia de pe peretele din spatele tronului si o indreapta spre tine."<<std::endl;
                validarecomanda=1;
                actiuni.batalie(jucator1,rege);      
                if(rege.getviata()==0)
                {
                    batutrege=1;
                    jucator1.setviata(0);
                }
            }
            if(comanda=="batalie" && locatiecurenta->getnume()=="Castelul Impunator" && demon.getviata()>0 && dezbaterea==1)
            {
                validarecomanda=1;
                actiuni.batalie(jucator1,demon);      
                if(demon.getviata()==0)
                {
                    std::cout<<"Ai reusit sa il invingi pe demon si poti sa continui in cautarea adevarului!"<<std::endl;
                    std::cout<<"Te simti mai rezistent."<<std::endl;
                    viatamax=175;
                    jucator1.setviata(175);
                    std::cout<<"Gasesti pe jos o gheara de demon."<<std::endl;
                    jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Gheara de demon", 1,40));
                }
            }
            if(comanda=="batalie" && locatiecurenta->getnume()=="Tronul Regal" && rege.getviata()>0 && dezbaterea==1)
            {
                validarecomanda=1;
                std::cout<<"'Esti un tradator si te voi executa cu mana mea'."<<std::endl;
                actiuni.batalie(jucator1, rege);
                if(rege.getviata()==0)
                {
                    batutrege=1;
                    finalfericit=1;
                    jucator1.setviata(0);
                }
            }
            if((comanda=="mers"|| comanda=="mers usa")&& locatiecurenta->getnume()=="Castelul Impunator" && dezbaterea==1 && demon.getviata()>0)
            {
                validarecomanda=1;
                std::cout<<"'Nu te pot lasa sa fugi'. Demonul isi infige ghearele in tine si iti musca gatul."<<std::endl;
                std::cout<<"Lasitatea ta a condamnat regatul la moarte."<<std::endl;
                jucator1.setviata(0);
            }
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
                    viatamax=110;
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
                    viatamax=125;
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
                    viatamax=150;
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
                jucator1.setviata(0);
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
                        jucator1.folosestePotiune(dynamic_cast<Potiune&>(*obiecte[i]),viatamax);
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
                    for(size_t j=i+1;j<obiecte.size();)
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
                    }
                    return false;
                    
                });
                std::cout<<"Inventarul tau este: "<<std::endl;
                jucator1.getinventar().afisareinventar();
            }
            if(jucator1.getviata()==0)
            {
                if(batutrege==1)
                {
                    if(finalfericit==1)
                    {
                        std::cout<<"Ai reusit sa il invingi pe rege si ai oprit tirania sa! Regatul este salvat!"<<std::endl;
                        std::cout<<"Felicitari! Ai terminat jocul cu final fericit!"<<std::endl;
                    }
                    else
                    {
                        std::cout<<"Nu ai respectat dorintele regelui si ai decis sa te lupti cu el. Ai reusit sa il invingi si in absenta lui haosul din regat dispare."<<std::endl;
                        std::cout<<"Totul e bine cand se termina cu bine!"<<std::endl;
                    }
                }
                else{
                    std::cout<<"Ai murit!"<<std::endl;
                    std::cout<<"Sfarsitul jocului!"<<std::endl;
                    std::cout<<"Multumesc ca ai jucat jocul!"<<std::endl;
                }
                if(batutturneu==1)
                {
                    std::cout<<"Ai terminat turneul si ai devenit Ucigasul de Banditi!"<<std::endl;
                }
                if(batutstrigoi==1)
                {
                    std::cout<<"Ai invins strigoiul si ai adus liniste in padure!"<<std::endl;
                }
                if(batuturs==1)
                {
                    std::cout<<"Ai invins ursul si ai adus liniste in pestera!"<<std::endl;
                }
                if(finalfericit==1&& batutstrigoi==1 && batuturs==1 && batutturneu==1)
                {
                    std::cout<<"Ai reusit sa invingi toti inamicii!"<<std::endl;
                }
                break;
            }
            if (validarecomanda==0) {
                std::cout<<"Comanda invalida!"<<std::endl;
            }
            
        }
    }catch(const std::exception& e)
    {
        std::cerr<<"Eroare la crearea jucatorului "<<e.what()<<std::endl;
    }
    return 0;
}
