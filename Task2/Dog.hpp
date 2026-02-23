#ifndef DOG__TBS_HPP
#define DOG__TBS_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    bool is_large;

    Dog()=default;
    Dog(std::string name, double temp, double breath, double heart, bool is_large);

    ~Dog()=default;

    //rule of three:
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);

    bool check_health() const override;
};

#endif //DOG__TBS_HPP