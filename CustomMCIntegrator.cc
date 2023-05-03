// CustomMCIntegrator.cc

#include "CustomMCIntegrator.hh"
#include <stdlib.h>
#include <time.h>

CustomMCIntegrator::CustomMCIntegrator(int n) : CustomIntegrator() {
    npoints_ = n;
    srand48(time(0));
}

double CustomMCIntegrator::uniform(double a, double b) const {
    return a + (b - a) * lrand48() / RAND_MAX;
}

double CustomMCIntegrator::integrate(double xlo, double xhi) const {
    double sum = 0.;
    for (int i = 0; i < npoints_; i++) {
        sum += integrand(uniform(xlo, xhi));
    }
    sum *= (xhi - xlo) / npoints_;
    return sum;
}