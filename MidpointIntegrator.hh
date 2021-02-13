// MidpointIntegrator.hh

#ifndef MidpointIntegrator_hh
#define MidpointIntegrator_hh

#include "Integrator.hh"
#include "Function.hh"

class MidpointIntegrator : public Integrator {
public:
    MidpointIntegrator(int n = 1000);
    virtual double point(double xlo, double xhi, int i) const;
    virtual double integrate(double xlo, double xhi, const Function* f) const;
private:
};

#endif