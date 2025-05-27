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
#pragma once
class Joc{
    public:
        Joc() = default;
        void final(const Inamic &rege,const Inamic &strigoi,const Inamic &urs,const Inamic &bandit3, int finalfericit);
        void start();
        ~Joc() = default;
};