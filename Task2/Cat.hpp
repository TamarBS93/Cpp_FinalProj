#ifndef CAT__TBS_HPP
#define CAT__TBS_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:

    Cat()=default;

    Cat(std::string name, double temp, double breath, double heart);

    ~Cat()=default;

    //rule of three:
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    bool check_health() const override;
};

#endif //CAT__TBS_HPP