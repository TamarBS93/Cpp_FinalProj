#include "Animal.hpp"
#include "Cat.hpp"

// Cat::Cat();
Cat::Cat(std::string name, double temp, double breath, double heart)
    : Animal(name, temp, breath, heart){}

bool Cat::check_health() const {
    if(temp < 38 || temp > 39.2) return false;
    if(breath < 16 || breath > 40) return false;
    if(heart < 120 || heart > 140) return false;
  
    return true;
}

