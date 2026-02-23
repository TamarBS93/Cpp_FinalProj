#ifndef COW__TBS_HPP
#define COW__TBS_HPP

#include "Animal.hpp"

class Cow : public Animal {
public:
    double milk;

    Cow()=default;
    Cow(std::string name, double temp, double breath, double heart, double liters);

    ~Cow()=default;

    //rule of three:
    Cow(const Cow& other);
    Cow& operator=(const Cow& other);

    bool check_health() const override;
};

#endif //COW__TBS_HPP