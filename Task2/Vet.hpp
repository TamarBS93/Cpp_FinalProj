#ifndef VET__TBS_HPP
#define VET__TBS_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "Animal.hpp"

class Vet {
    std::vector< std::unique_ptr<Animal> > animals;    

    Vet(); 
    ~Vet() = default;
    //rule of three:
    Vet(const Vet& other) = delete;
    Vet& operator=(const Vet& other) = delete;

public:
    static Vet& get_instance();
    void add_animal(Animal * &&animal_ptr);
    void show_sick() const;
    void show_sick_dogs() const;
};

#endif //VET__TBS_HPP