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

std::ostream& operator<<(std::ostream& os, const Exponential& rhs) {
    os << "exponential function: " << rhs.name() << " = " << rhs.A_ << "exp(" << rhs.b_ << "x)";
    return os;
}