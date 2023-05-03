// MCIntegrator.hh

#ifndef MCIntegrator_hh
#define MCIntegrator_hh

#include "Integrator.hh"
#include "Function.hh"

class MCIntegrator : public Integrator {
public:
    MCIntegrator(int n = 1000);

    virtual void setNPoints(int n) {
        npoints_ = n;
    }
    virtual int nPoints() const { return npoints_; };

    virtual double integrate(double xlo, double xhi, const Function* f) const;

private:
    double uniform(double a, double b) const;
    int npoints_;
};

#endif