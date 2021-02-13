// MidpointIntegrator.cc

#include "MidpointIntegrator.hh"

MidpointIntegrator::MidpointIntegrator(int n) : Integrator() {
    npoints_ = n;
}


double MidpointIntegrator::integrate(double xlo, double xhi, const Function* f) const {
    double sum = 0.;
    double l = xhi - xlo;
    double dx = l / nPoints();
    double x;
    for (int i = 0; i < npoints_; i++) {
        sum += f->value(xlo + ((double)i + 0.5) * dx);
    }
    return sum * l / npoints_;
}