// CustomMCIntegrator.hh

#ifndef CustomMCIntegrator_hh
#define CustomMCIntegrator_hh

#include "CustomIntegrator.hh"

class CustomMCIntegrator : public CustomIntegrator {
public:
    CustomMCIntegrator(int n = 1000);
    void setNPoints(int n) {
        npoints_ = n;
    }
    virtual double integrate(double xlo, double xhi) const;

private:
    int npoints_;
    double uniform(double a, double b) const;
};

#endif