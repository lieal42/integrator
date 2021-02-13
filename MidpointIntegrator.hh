// MidpointIntegrator.hh

#ifndef MidpointIntegrator_hh
#define MidpointIntegrator_hh

#include "Integrator.hh"
#include "Function.hh"

class MidpointIntegrator : public Integrator {
public:
    MidpointIntegrator(int n = 1000);
    void setNPoints(int n) {
        npoints_ = n;
    }
    int nPoints() const { return npoints_; };
    virtual double integrate(double xlo, double xhi, const Function* f) const;
private:
    int npoints_;
};

#endif