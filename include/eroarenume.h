#pragma once
#include <stdexcept>
#include <string>
class Eroarenume : public std::runtime_error {
public:
    Eroarenume(const std::string& mesaj);
};