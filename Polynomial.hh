// Polynomial.hh

#ifndef Polynomial_hh
#define Polynomial_hh

#include "Function.hh"
#include<vector>

class Polynomial : public Function {
public:
    Polynomial(const std::string& name, const std::vector<double>& coeff);

    virtual double value(double x) const;
    virtual double derivative(double x) const;
    virtual double integrate(double x1, double x2) const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);

private:
    std::vector<double> coeff_;
};

#endif