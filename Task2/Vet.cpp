#include "Vet.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Cow.hpp"

#include <iostream>

Vet::Vet()
    : animals() {}

Vet& Vet::get_instance(){
    static Vet instance;
    return instance;
}

void Vet::add_animal(Animal * && animal_ptr){
    if (animal_ptr == nullptr) {
        return;
    }
    animals.emplace_back(std::unique_ptr<Animal>(animal_ptr));
}
void Vet::show_sick() const{
    for(const auto& animal : animals){
        if(!animal->check_health()){
            std::cout << animal->get_name() << " ";
        }
    }
    std::cout<< std::endl;
}

void Vet::show_sick_dogs() const {
    for (const auto& animal : animals) {
        Dog* dog = dynamic_cast<Dog*>(animal.get());
        if (dog && !dog->check_health()) {
            std::cout << dog->get_name() << " ";
        }
    }
    std::cout << std::endl;
}

