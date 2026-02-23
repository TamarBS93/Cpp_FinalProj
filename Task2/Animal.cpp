#include "Animal.hpp"

Animal::Animal(std::string name, double temp, double breath, double heart)
    : name(name), temp(temp), breath(breath), heart(heart) {}

//rule of three:
Animal::Animal(const Animal& other)
    : name(other.name), temp(other.temp), breath(other.breath), heart(other.heart) {}

Animal& Animal::operator=(const Animal& other){
    if(this == &other) return *this;
    name = other.name;
    temp = other.temp;
    breath = other.breath;
    heart = other.heart;
    return *this;
}

std::string Animal::get_name() const {
    return name;
}

