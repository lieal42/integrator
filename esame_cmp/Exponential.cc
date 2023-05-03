// Exponential.cc

#include "Exponential.hh"
#include <cmath>
#include <iostream>

Exponential::Exponential(const std::string& name, const double& A, const double& b) : Function(name) {
    A_ = A;
    b_ = b;
}

double Exponential::value(double x) const {
    return A_ * exp(b_ * x);
}

double Exponential::integrate(double xlo, double xhi) const {
    return integrator()->integrate(xlo, xhi, this);
}

double Exponential::anIntegral(double xlo, double xhi) const {
    return A_ / b_ * (exp(b_ * xhi) - exp(b_ * xlo));
}

std::ostream& operator<<(std::ostream& os, const Exponential& rhs) {
    os << "exponential function: " << rhs.name() << " = " << rhs.A_ << "exp(" << rhs.b_ << "x)";
    return os;
}
