// MCIntegrator.cc

#include "MCIntegrator.hh"
#include <stdlib.h>
#include <time.h>

MCIntegrator::MCIntegrator(int n) : Integrator(n) {
    srand48(time(0));
}

double MCIntegrator::uniform(double a, double b) const {
    return a + (b - a) * lrand48() / RAND_MAX;
}

double MCIntegrator::point(double xlo, double xhi, int i) const {
    return uniform(xlo, xhi);
}

double MCIntegrator::integrate(double xlo, double xhi, const Function* f) const {
    double sum = 0.;
    int points = nPoints();
    for (int i = 0; i < points; i++) {
        sum += f->value(uniform(xlo, xhi));
    }
    return sum * (xhi - xlo) / points;
}