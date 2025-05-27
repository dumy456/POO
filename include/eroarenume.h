#pragma once
#include <stdexcept>
#include <string>
class Eroarenume : public std::runtime_error {
public:
    explicit Eroarenume(const std::string& mesaj);
};