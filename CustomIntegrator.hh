// CustomIntegrator.hh

#ifndef CustomIntegrator_hh
#define CustomIntegrator_hh

#include "Function.hh"

class CustomIntegrator {
public:
    CustomIntegrator() { integrand_ = 0; }
    virtual ~CustomIntegrator() {}
    void setIntegrand(Function* f) { integrand_ = f; }
    double integrand(double x) const { return integrand_->value(x); }
    Function* integrand() const { return integrand_; }
    virtual double integrate(double xlo, double xhi) const = 0;
private:
    Function* integrand_;
};


#endif