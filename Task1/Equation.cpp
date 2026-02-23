#include "Equation.hpp"

#include <string>      // for std::to_string
#include <stdexcept>   // for std::invalid_argument, std::out_of_range
#include <cmath>       // for std::sqrt
#include <utility>     // for std::move
#include <cstddef>     // for std::size_t
#include <iostream>    // for std::ostream
#include <iomanip>     // for std::setprecision


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

    // get_solutions.ptr = solutions;
    // get_solutions.size = solutions_size;

}

Equation::Equation()
    : a{1}, b{}, c{}, solutions{nullptr}, solutions_size{0}//, get_solutions{nullptr, 0}
{
    // std::cout << this << ": Default Constructor" << std::endl; // Debug print
    update_solutions();
}

Equation::Equation(double a, double b, double c) 
    : a{a}, b{b}, c{c}//, get_solutions{nullptr, 0}
{
    if (a == 0) {
        throw std::invalid_argument("Coefficient a cannot be zero for a quadratic equation."); 
    }
    // std::cout << this << ": Parameterized Constructor" << std::endl; // Debug print
    update_solutions();
}

//rule of three:
Equation::Equation(const Equation& other) 
    : a{other.a}, b{other.b}, c{other.c}, solutions{nullptr}, solutions_size{other.solutions_size}//,get_solutions{nullptr, 0}
{
    if (solutions_size > 0) {
        solutions = new double[solutions_size];
        for (std::size_t i = 0; i < solutions_size; ++i) {
            solutions[i] = other.solutions[i];
        }
    }

    // get_solutions.ptr = solutions;
    // get_solutions.size = solutions_size;

    // std::cout << this << ": Copy Constructor" << std::endl; // Debug print
}


// Copy assignment operator implemented 
// using copy-and-swap idiom for strong exception safety.
Equation& Equation::operator=(Equation other) 
{
    swap(other);
    // std::cout << this << ": Copy Assignment operator" << std::endl; // Debug print
    return *this;
}       

Equation::~Equation() {
    delete[] solutions;
    // std::cout << this << ": Destructor" << std::endl; // Debug print
}

// Move constructor implemented using move semantics.
Equation::Equation(Equation&& other) noexcept
    : a{0}, b{0}, c{0}, solutions{nullptr}, solutions_size{0}//, get_solutions{}
{
    swap(other);
    // std::cout << this << ": Move Constructor" << std::endl; // Debug print
}

void Equation::swap(Equation& other) noexcept {
    using std::swap;
    swap(a, other.a);
    swap(b, other.b);
    swap(c, other.c);
    swap(solutions, other.solutions);
    swap(solutions_size, other.solutions_size);

    // get_solutions.ptr = solutions;
    // get_solutions.size = solutions_size;

    // other.get_solutions.ptr = other.solutions;
    // other.get_solutions.size = other.solutions_size;

    // std::cout << this << ": Swap function" << std::endl; // Debug print
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
double const * Equation::get_solutions() { return solutions; }

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
    os << std::fixed << std::setprecision(1) 
       << eq.get_a() << "X^2 + " << eq.get_b() << "X + " << eq.get_c() << " = 0";
    return os;
}

// const double* Equation::SolutionsAccessor::operator()() const {
//     return ptr;
// }

// double Equation::SolutionsAccessor::operator[](std::size_t index) const {
//     if (!ptr || index >= size) {
//         throw std::out_of_range("Solution index out of range");
//     }
//     return ptr[index];
// }