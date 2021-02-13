// MCIntegrator.cc

#include "MCIntegrator.hh"
#include <stdlib.h>
#include <time.h>

MCIntegrator::MCIntegrator(int n) : Integrator() {
    srand48(time(0));
    npoints_ = n;
}

double MCIntegrator::uniform(double a, double b) const {
    return a + (b - a) * lrand48() / RAND_MAX;
}

double MCIntegrator::integrate(double xlo, double xhi, const Function* f) const {
    double sum = 0.;;
    for (int i = 0; i < npoints_; i++) {
        sum += f->value(uniform(xlo, xhi));
    }
    return sum * (xhi - xlo) / npoints_;
}