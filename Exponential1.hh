// Exponential1.hh
#ifndef Exponential1_hh
#define Exponential1_hh

#include "Function1.hh"

class Exponential1 : public Function1 {
public:
    Exponential1(const std::string& name, const double& A = 1, const double& b = 1);

    virtual double value(double x) const;
    virtual double derivative(double x) const;
    virtual double integrate(double x1, double x2) const;

    friend std::ostream& operator<<(std::ostream& os, const Exponential1& rhs);

private:
    double A_;
    double b_;
};

#endif