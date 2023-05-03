// MidpointIntegrator.cc

#include "MidpointIntegrator.hh"

MidpointIntegrator::MidpointIntegrator(int n) : CustomIntegrator() {
    npoints_ = n;
}

double MidpointIntegrator::integrate(double xlo, double xhi) const {
    double sum = 0.;
    double l = xhi - xlo;
    double dx = l / npoints_;
    double x;
    for (int i = 0; i < npoints_; i++) {
        x = xlo + i * dx;
        sum += (integrand(x) + integrand(x + dx)) * dx / 2;
    }
    return sum;
}
