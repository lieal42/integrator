// Exponential.hh
#ifndef Exponential_hh
#define Exponential_hh

#include "Function.hh"

class Exponential : public Function {
public:
    Exponential(const std::string& name, const double& A = 1, const double& b = 1);

    virtual double value(double x) const;

    friend std::ostream& operator<<(std::ostream& os, const Exponential& rhs);

private:
    double A_;
    double b_;
};

#endif