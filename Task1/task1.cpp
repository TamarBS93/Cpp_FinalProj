#include <iostream>

#include "Equation.hpp"

int main() {
    using namespace std;

    Equation eq_default;
    std::cout << eq_default << std::endl;
    //should print: 
    // Default Constructor
    // 1X^2 + 0X + 0 = 0
    // 1. Works!

    Equation eq_param(1, 3, -4);   // 2 solutions
    std::cout << eq_param << std::endl;
    //should print: 
    // Parameter Constructor
    // 1X^2 + 3X + -4 = 0
    // 2. Works!

    Equation eq_copy(eq_param);
    std::cout << eq_copy << std::endl;
    //should print:
    // Copy Constructor
    // 1X^2 + 3X + -4 = 0
    // 3. Works!

    Equation eq_assign;
    eq_assign = eq_param;
    std::cout << eq_assign << std::endl;
    //should print:
    // Default Constructor
    // Copy Assignment operator
    // 1X^2 + 3X + -4 = 0
    // 4. Works!

    eq_assign = eq_assign;
    std::cout << eq_assign << std::endl;
    //should print:
    // Copy Constructor
    // Copy Assignment operator (self-assignment)
    // 1X^2 + 3X + -4 = 0
    // 5. Works! (self-assignment handled correctly)

    Equation eq_move_ctor(std::move(eq_param));
    std::cout << eq_move_ctor << std::endl;
    //should print:
    // Move Constructor
    // 1X^2 + 3X + -4 = 0
    // 6. Works!

    Equation eq_move_assign;
    eq_move_assign = std::move(eq_copy);
    std::cout << eq_move_assign << std::endl;
    //should print:
    // Default Constructor
    // Move Assignment operator
    // 1X^2 + 3X + -4 = 0
    try
    {
        Equation bad_eq(0, 2, 3);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
    //should print:
    // Caught exception: Coefficient a cannot be zero for a quadratic equation.

    std::cout << "===== End of construction tests =====\n";

    Equation eq(10,20,30);
    cout << eq << endl;
    //should print: 10X^2 + 20X + 30 = 0
    cout << eq.get_solutions_size() << endl;
    //should print 0
    eq = -20 + eq;

    cout << eq << endl;
    //should print: 10X^2 + 20X + 10 = 0
    cout << eq.get_solutions_size() << endl;
    //should print 1
    //cout << eq.get_solutions[0] << endl; // error : should be eq.get_solutions()[0]
    cout << eq.get_solutions()[0] << endl;
    //should print -1
    cout << Equation(1,5,3) + Equation(2,6,4) << endl;
    //should print: 3X^2 + 11X + 7 = 0
    eq = Equation(1,3,-4);
    cout << eq << endl;
    //should print 1X^2 + 3X + -4 = 0
    cout << eq.get_solutions_size() << endl;
    //should print 2
    cout << "X1 = " << eq.get_solutions()[0] << endl;
    //should print: X1 = 1
    cout << "X2 = " << eq.get_solutions()[1] << endl;
    //should print: X2 = -4

    return 0;
}