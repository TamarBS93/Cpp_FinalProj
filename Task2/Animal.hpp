#ifndef ANIMAL_TBS_HPP
#define ANIMAL_TBS_HPP

#include <string>

class Animal {
    std::string name;
public:
    double temp, breath, heart;

    Animal(std::string name, double temp, double breath, double heart);
    virtual ~Animal() = default;

    //rule of three:
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual bool check_health() const = 0;
    std::string get_name() const;
};

#endif //ANIMAL_TBS_HPP