// MCIntegrator.hh

#ifndef MCIntegrator_hh
#define MCIntegrator_hh

#include "Integrator.hh"
#include "Function.hh"

class MCIntegrator : public Integrator {
public:
    MCIntegrator(int n = 1000);

    virtual double point(double xlo, double xhi, int i) const;

    virtual double integrate(double xlo, double xhi, const Function* f) const;

private:
    double uniform(double a, double b) const;
};

#endif