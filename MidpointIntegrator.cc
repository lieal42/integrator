// MidpointIntegrator.cc

#include "MidpointIntegrator.hh"

MidpointIntegrator::MidpointIntegrator(int n) : Integrator(n) {}

double MidpointIntegrator::point(double xlo, double xhi, int i) const {
    double l = xhi - xlo;
    double dx = l / nPoints();
    double x;
    return xlo + ((double)i + 0.5) * dx;
}

double MidpointIntegrator::integrate(double xlo, double xhi, const Function* f) const {
    double sum = 0.;
    double l = xhi - xlo;
    double dx = l / nPoints();
    double x;
    int points = nPoints();
    for (int i = 0; i < points; i++) {
        sum += f->value(xlo + ((double)i + 0.5) * dx);
    }
    return sum * l / points;
}