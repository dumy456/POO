
#include "eroarenume.h"
Eroarenume::Eroarenume(const std::string& mesaj) : std::runtime_error(mesaj) {
}