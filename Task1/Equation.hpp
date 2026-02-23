#ifndef EQUATION_TBS_HPP
#define EQUATION_TBS_HPP

#include <cstddef>
#include <stdexcept>
#include <iosfwd> // for std::ostream

/**
 * @brief Represents a quadratic equation of the form:
 *        a*x^2 + b*x + c = 0
 *
 * The class dynamically manages its solutions array and follows
 * the Rule of Three.
 */
class Equation {
    double a{1.0}, b{0.0}, c{0.0}; // coefficients of the equation ax^2 + bx + c = 0
    double  *solutions{nullptr};   // Dynamically allocated array to hold the solutions of the equation
    std::size_t solutions_size{0}; // number of solutions (0,1 or 2)

    /**
     * @brief Recalculates the solutions based on current coefficients.
     */
    void update_solutions();

public:

    /**
     * @brief Default constructor. Creates equation x^2 = 0.
     */
    Equation();

    /**
     * @brief Constructs a quadratic equation.
     * @param a Coefficient of x^2 (must not be zero).
     * @param b Coefficient of x.
     * @param c Constant term.
     * @throws std::invalid_argument if a == 0.
     */
    explicit Equation(double a, double b, double c);

    /*-----------------------
        rule of three:
    ------------------------*/
    /**
     * @brief Copy constructor.
     * @param other Equation to copy from.
     */
    Equation(const Equation& other);
    
    /**
     * @brief Copy assignment operator.
     * @param other Equation to assign from.
     * @return Reference to this object.
     */
    Equation& operator=(Equation other); 
    /**
     * @brief Destructor. Cleans up dynamically allocated memory.
     */     
    ~Equation() noexcept;

    /*-----------------------
        rule of five:
    ------------------------*/
    /**
     * @brief Move constructor.
     * @param other Equation to move from.
     */
    Equation(Equation&& other) noexcept;
    
    /**
     * @brief Move assignment operator.
     * @param other Equation to move from.
     * @return Reference to this object.
     */    
    void swap(Equation& other) noexcept;

    /* -----------------------
        geters and setters:
    -------------------------*/
    /// @return Coefficient a
    double get_a() const;

    /// @return Coefficient b
    double get_b() const;
    
    /// @return Coefficient c
    double get_c() const;
    
    /**
     * @brief Sets coefficient a.
     * @param a New coefficient (must not be zero).
     * @throws std::invalid_argument if a == 0.
     */
    void set_a(double a);
    
    /**
     * @brief Sets coefficient b.
     * @param b New coefficient.
     */
    void set_b(double b);
    
    /**
     * @brief Sets coefficient c.
     * @param c New coefficient.
     */
    void set_c(double c);
  
    // /**
    // * @brief Helper object that allows access to equation solutions
    // *        using both function-call and array syntax.
    // * Supports:
    // *  - eq.get_solutions[0]
    // *  - eq.get_solutions()[0]
    // */
    // struct SolutionsAccessor {  
    //     const double* ptr{nullptr};
    //     std::size_t size{0};
        
    //     /**
    //     @brief Constructor for SolutionsAccessor.
    //     @param p Pointer to the solutions array.
    //     @param s Size of the solutions array.
    //     */
    //     SolutionsAccessor(const double* p = nullptr, std::size_t s = 0)
    //         : ptr(p), size(s) {}
    //     /**
    //         * @brief Returns the raw solutions array.
    //         * @return Pointer to the solutions array.
    //         */
    //     const double* operator()() const;

    //     /**
    //         * @brief Access a solution by index.
    //         * @param index Index of the solution.
    //         * @return The solution value.
    //         * @throws std::out_of_range if index is invalid.
    //         */
    //     double operator[](std::size_t index) const;
    // };

    // SolutionsAccessor get_solutions; // Public accessor for solutions

    /**
     * @brief Returns a pointer to the array of solutions.
     * @return Pointer to the array of solutions (may be nullptr if no solutions).
     */
    double const * get_solutions();
    
    /**
     * @brief Returns number of solutions.
     * @return Number of solutions (0, 1, or 2).
     */
    std::size_t get_solutions_size() const;

    /* -----------------------
        operator overloads:
    -------------------------*/
    /**
     * @brief Adds two equations.
     * @param other Equation to add.
     * @return New Equation representing the sum.
     */
    Equation operator+(const Equation& other) const;

    /**
     * @brief Adds a constant to the equation (affects c).
     * @param additional_constant Constant to add.
     * @return New Equation with modified c.
     */
    Equation operator+(double additional_constant) const;

};

/**
 * @brief Adds a constant to an equation (constant on the left).
 * @param additional_constant Constant to add.
 * @param eq Equation to modify.
 * @return New Equation with modified c.
 */
Equation operator+(double additional_constant, const Equation& eq);

/**
    * @brief Stream output operator.
    * @param os Output stream.
    * @param eq Equation to print.
    * @return Output stream.
    */
std::ostream& operator<<(std::ostream& os, const Equation& eq);

#endif // EQUATION_TBS_HPP