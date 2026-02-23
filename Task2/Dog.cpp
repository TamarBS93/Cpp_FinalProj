#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(std::string name, double temp, double breath, double heart, bool is_large)
    : Animal(name, temp, breath, heart), is_large(is_large) {}

bool Dog::check_health() const {

    if(temp < 38.5 || temp > 39.2) return false;
    if(breath < 10 || breath > 35) return false;
    if(is_large){
        if(heart < 60 || heart > 100) return false;
    } else {
        if(heart < 100 || heart > 140) return false;
    }
    return true;
}

