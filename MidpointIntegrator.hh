// MidpointIntegrator.hh

#ifndef MidpointIntegrator_hh
#define MidpointIntegrator_hh

#include "CustomIntegrator.hh"

class MidpointIntegrator : public CustomIntegrator {
public:
    MidpointIntegrator(int n = 1000);
    void setNPoint(const int& n) {
        npoints_ = n;
    }
    virtual double integrate(double xlo, double xhi) const;

private:
    int npoints_;
};

#endif