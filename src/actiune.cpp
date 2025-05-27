#include "actiune.h"
#include <iostream>

void Actiune::aratalocatiecurenta(Locatie* locatiecurenta) const {
    locatiecurenta->textdescriere();
}
int Actiune::miscajucator(std::string directie, Locatie* locatiecurenta) const {
    if (locatiecurenta->getiesire(directie) == NULL) return 0;
    else return 1;
}
void Actiune::batalie(Jucator &jucator, Inamic &inamic) {
    while (true) {
        jucator.atac(inamic);
        if (inamic.getviata() <= 0) {
            std::cout << inamic.getnume() << " a fost invins!" << std::endl;
            break;
        }
        inamic.atac(jucator);
        if (jucator.getviata() <= 0) {
            std::cout << jucator.getnume() << " a fost invins!" << std::endl;
            break;
        }
        if(inamic.getnume() == "Rege") {
            if(inamic.getviata()<=100 && inamic.getviata()>=65)
            std::cout << "'Nu te voi lasa sa distrugi regatul meu!' striga regele" << std::endl;
        }
    }
}
void Actiune::foloseste(Jucator& jucator1, int viatamax){
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
void Actiune::echipare(Jucator &jucator1, int &armeechipate) {
    std::cout<<"Introduceti numele armei pe care doriti sa o echipati: ";
    std::string numearma;
    std::getline(std::cin >> std::ws, numearma);
    auto& obiecte=jucator1.getinventar().getobiecte();
    if(armeechipate<1){
        int armagasita=0;
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
        std::cout<<"Ai echipat deja o arma!"<<std::endl;
        
    }
}
void Actiune::mers(Locatie*& locatiecurenta){
    std::cout<<"Poti merge in"<<std::endl;
    locatiecurenta->arataiesiri();
    std::string directie;
    std::cin>>directie;
    if(Actiune::miscajucator(directie,locatiecurenta)==0)
        { std::cout<<"Nu poti merge in partea aia!"<<std::endl;
        }
    else{
            locatiecurenta=locatiecurenta->getiesire(directie);
        }
    Actiune::aratalocatiecurenta(locatiecurenta);
}
void Actiune::inventar(Jucator &jucator1) {
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
void Actiune::turneu(Jucator &jucator1,Locatie* &locatiecurenta, Inamic &bandit1, Inamic &bandit2, Inamic &bandit3, int &viatamax, int &armeechipate) {
    Actiune::batalie(jucator1,bandit1);
            if(bandit1.getviata()==0)
            {
                std::cout<<"Ai invins banditul si ai primit o recompensa!"<<std::endl;
                std::cout<<"Gasesti pe jos o potiune de viata."<<std::endl;
                jucator1.getinventar().adaugaobiect(std::make_unique<Potiune>("Potiune de viata", 1, 50));
            }
            else{
                return;
            }
    std::cout<<"Daca vrei sa continui turneul, scrie 'continua'."<<std::endl;
    std::cout<<"Daca vrei sa abandonezi, scrie 'abandoneaza'."<<std::endl;
    int contor=0;
    while(true){
        int validarecomanda=0;
        contor++;
        std::cout<<"Actiunea ta este: ";
        std::string comanda;
        std::cin>>comanda;
        if(comanda=="abandoneaza")
        {
            std::cout<<"Ai abandonat turneul."<<std::endl;
            return;
        }
        if(comanda=="informatii")
            {
                validarecomanda=1;
                std::cout<<jucator1<<std::endl;
            }
        if(comanda=="echipare")
        {
            validarecomanda=1;
            echipare(jucator1,armeechipate);
        }
        if(comanda=="dezechipare")
        {
            validarecomanda=1;
                if(armeechipate>0)
                {
                    jucator1.setputere(10);
                    armeechipate--;
                    std::cout<<"Arma a fost distrusa!"<<std::endl;
                }
                else
                {
                    std::cout<<"Nu ai nicio arma echipata!"<<std::endl;
                }
        }
        if(comanda=="foloseste")
        {
            validarecomanda=1;
            foloseste(jucator1, viatamax);
        }
        if(comanda=="inventar")
        {
            validarecomanda=1;
            inventar(jucator1);
        }
        if(comanda=="continua")
        {
           break;
        }
        if(contor>10)
        {
            std::cout<<"Ai depasit numarul maxim de comenzi permise!"<<std::endl;
            return;
        }
        if(validarecomanda==0){
            std::cout<<"Comanda invalida! Te rog sa incerci din nou."<<std::endl;
        }

    }
    Actiune::batalie(jucator1,bandit2);
            if(bandit2.getviata()==0)
                {
                    std::cout<<"Ai invins capitanul banditilor si ai primit o recompensa!"<<std::endl;
                    std::cout<<"Gasesti pe jos o sabie de argint."<<std::endl;
                    jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de argint", 1, 20));
                }
            else{
                return;
            }
    std::cout<<"Daca vrei sa continui turneul, scrie 'continua'."<<std::endl;
    std::cout<<"Daca vrei sa abandonezi, scrie 'abandoneaza'."<<std::endl;
    contor=0;
    while(true){
        contor++;
        int validarecomanda=0;
        std::cout<<"Actiunea ta este: ";
        std::string comanda;
        std::cin>>comanda;
        if(comanda=="abandoneaza")
        {
            std::cout<<"Ai abandonat turneul."<<std::endl;
            return;
        }
        if(comanda=="informatii")
            {
                validarecomanda=1;
                std::cout<<jucator1<<std::endl;
            }
        if(comanda=="echipare")
        {
            validarecomanda=1;
            echipare(jucator1,armeechipate);
        }
        if(comanda=="dezechipare")
        {
            validarecomanda=1;
                if(armeechipate>0)
                {
                    jucator1.setputere(10);
                    armeechipate--;
                    std::cout<<"Arma a fost distrusa!"<<std::endl;
                }
                else
                {
                    std::cout<<"Nu ai nicio arma echipata!"<<std::endl;
                }
        }
        if(comanda=="foloseste")
        {
            validarecomanda=1;
            foloseste(jucator1, viatamax);
        }
        if(comanda=="inventar")
        {
            validarecomanda=1;
            inventar(jucator1);
        }
        if(comanda=="continua")
        {
           break;
        }
        if(contor>10)
        {
            std::cout<<"Ai depasit numarul maxim de comenzi permise!"<<std::endl;
            return;
        }
        if(validarecomanda==0){
            std::cout<<"Comanda invalida! Te rog sa incerci din nou."<<std::endl;
        }

    }
    Actiune::batalie(jucator1,bandit3);
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
        locatiecurenta->setnume("Tabara Abandonata");
        locatiecurenta->setdescriere("Te afli in Tabara Abandonata. Inainte se numea Tabara Banditilor, dar acum este mai linistita.");
        return;
    }
    else{
        return;
    }
}
void Actiune::bataieurs(Jucator &jucator1, Inamic &urs,int &viatamax,Locatie* &locatiecurenta){
    Actiune::batalie(jucator1, urs);      
    if(urs.getviata()==0)
    {
        locatiecurenta->setnume("Pestera Intunecata");
        locatiecurenta->setdescriere("Te afli in Pestera Intunecata. Inainte se numea Pestera Ursului, dar acum este mai linistita.");
        std::cout<<"Ai invins ursul!"<<std::endl;
        std::cout<<"Te simti mai rezistent."<<std::endl;
        jucator1.setviata(125);
        viatamax=125;
        std::cout<<jucator1<<std::endl;
        std::cout<<"Gasesti pe jos o sabie de fier."<<std::endl;
        jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de fier", 1, 10));
        return;
    }
    else{
        return;
    }
}
void Actiune::bataiestrigoi(Jucator &jucator1, Inamic &strigoi,int &viatamax,Locatie* &locatiecurenta){
    Actiune::batalie(jucator1, strigoi);         
    if(strigoi.getviata()==0)
    {
        locatiecurenta->setnume("Padurea Linistita");
        locatiecurenta->setdescriere("Te afli in Padurea Linistita. Inainte era Padurea Strigoilor, dar acum este mai linistita.");
        std::cout<<"Ai invins strigoiul!"<<std::endl;
        std::cout<<"Te simti mai rezistent."<<std::endl;
        jucator1.setviata(110);
        viatamax=110;
        std::cout<<jucator1<<std::endl;
        std::cout<<"Gasesti pe jos o sabie de lemn."<<std::endl;
        jucator1.getinventar().adaugaobiect(std::make_unique<Arma>("Sabie de lemn", 1, 1));
        return;
    }
    else{
        return;
    }
}
Actiune::~Actiune() { std::cout << "Actiune a fost distrus" << std::endl; }