#include "Equation.hpp"

#include <string>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <cstddef>
#include <iostream>


void Equation::update_solutions() {
    delete[] solutions;
    solutions = nullptr;
    solutions_size = 0;

    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0.0) {
        solutions_size = 2;
        solutions = new double[solutions_size];
        solutions[0] = (-b + std::sqrt(discriminant)) / (2 * a);
        solutions[1] = (-b - std::sqrt(discriminant)) / (2 * a);
    } else if (std::abs(discriminant) < 1e-9) {
        solutions_size = 1;
        solutions = new double[solutions_size];
        solutions[0] = -b / (2 * a);
    } else {
        solutions_size = 0;
    }

    get_solutions.ptr = solutions;
    get_solutions.size = solutions_size;

}

Equation::Equation()
    : a{1}, b{}, c{}, solutions{nullptr}, solutions_size{0},
        get_solutions{nullptr, 0}

{
    update_solutions();
}

Equation::Equation(double a, double b, double c) 
    : a{a}, b{b}, c{c}, get_solutions{nullptr, 0}
{
    if (a == 0) {
        throw std::invalid_argument("Coefficient a cannot be zero for a quadratic equation.");
    }
    update_solutions();
}

//rule of three:
Equation::Equation(const Equation& other) 
    : a{other.a}, b{other.b}, c{other.c}, solutions{nullptr}, solutions_size{other.solutions_size},
        get_solutions{nullptr, 0}
{
    if (solutions_size > 0) {
        solutions = new double[solutions_size];
        for (std::size_t i = 0; i < solutions_size; ++i) {
            solutions[i] = other.solutions[i];
        }
    }

    get_solutions.ptr = solutions;
    get_solutions.size = solutions_size;
}

Equation& Equation::operator=(const Equation& other) 
{
    if (this != &other) {
        delete[] solutions;
        solutions = nullptr;
        solutions_size = other.solutions_size;
        
        a = other.a;
        b = other.b;
        c = other.c;
        
        if (solutions_size > 0) {
            solutions = new double[solutions_size];
            for (std::size_t i = 0; i < solutions_size; ++i) {
                solutions[i] = other.solutions[i];
            }
        }
        get_solutions.ptr = solutions;
        get_solutions.size = solutions_size;
    }
    return *this;
}       

Equation::~Equation() {
    delete[] solutions;
}

// geters and setters:
double Equation::get_a() const { return a; }
double Equation::get_b() const { return b; }
double Equation::get_c() const { return c; } 
void Equation::set_a(double a) { 
    if (a == 0) {
        throw std::invalid_argument("Coefficient a cannot be zero for a quadratic equation.");
    }
    else {
        this->a = a; 
    }
    update_solutions();
}
void Equation::set_b(double b) { this->b = b; update_solutions();}
void Equation::set_c(double c) { this->c = c; update_solutions();}

std::size_t Equation::get_solutions_size() const { return solutions_size; }

Equation Equation::operator+(const Equation& other) const {
    return Equation(a + other.a, b + other.b, c + other.c);
}

Equation Equation::operator+(double additional_constant) const {
    return Equation(a, b, c + additional_constant);
}

Equation operator+(double additional_constant, const Equation& eq) {
    return Equation(eq.get_a(), eq.get_b(), eq.get_c() + additional_constant);
}

std::ostream& operator<<(std::ostream& os, const Equation& eq) {
    os << eq.a << "X^2 + " << eq.b << "X + " << eq.c << " = 0";
    return os;
}

const double* Equation::SolutionsAccessor::operator()() const {
    return ptr;
}

double Equation::SolutionsAccessor::operator[](std::size_t index) const {
    if (!ptr || index >= size) {
        throw std::out_of_range("Solution index out of range");
    }
    return ptr[index];
}