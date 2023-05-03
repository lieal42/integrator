// Constant.hh

#ifndef Constant_hh
#define Constant_hh

#include "Function.hh"

class Constant : public Function {
public:
    Constant(const std::string& name, const double& k);
    virtual double value(double x) const;
    virtual double derivative(double x) const;
    virtual double integrate(double x1, double x2) const;

    friend std::ostream& operator<<(std::ostream& os, const Constant& rhs);

private:
    double k_;
};

#endif