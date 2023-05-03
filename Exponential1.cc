// Exponential1.cc

#include "Exponential1.hh"
#include <cmath>
#include <iostream>

Exponential1::Exponential1(const std::string& name, const double& A, const double& b) : Function1(name) {
    A_ = A;
    b_ = b;
}

double Exponential1::value(double x) const {
    return A_ * exp(b_ * x);
}

double Exponential1::derivative(double x) const {
    return A_ * b_ * exp(b_ * x);
}

double Exponential1::integrate(double x1, double x2) const {
    return A_ / b_ * exp(b_ * x2) - A_ / b_ * exp(b_ * x1);
}

std::ostream& operator<<(std::ostream& os, const Exponential1& rhs) {
    os << "exponential function: " << rhs.name() << " = " << rhs.A_ << "exp(" << rhs.b_ << "x)";
    return os;
}