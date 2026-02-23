#include "Animal.hpp"
#include "Cow.hpp"

Cow::Cow(std::string name, double temp, double breath, double heart, double liters)
    : Animal(name, temp, breath, heart), milk(liters) {}

bool Cow::check_health() const {
    if(temp < 38.5 || temp > 39.5) return false;
    if(breath < 26 || breath > 50) return false;
    if(heart < 48 || heart > 84) return false;
    if(milk < 30) return false;
    return true;
}

