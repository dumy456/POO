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
        void final(Inamic &rege, Inamic &strigoi, Inamic &urs, Inamic &bandit3, int finalfericit);
        void start();
        ~Joc() = default;
};