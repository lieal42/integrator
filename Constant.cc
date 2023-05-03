// Constant.cc

#include "Constant.hh"
#include <iostream>

Constant::Constant(const std::string& name, const double& k) : Function(name) {
    k_ = k;
}

double Constant::value(double x) const {
    return k_;
}

double Constant::derivative(double x) const {
    return 0;
}

double Constant::integrate(double x1, double x2) const {
    return k_ * (x2 - x1);
}

std::ostream& operator<<(std::ostream& os, const Constant& rhs) {
    os << "constant function: " << rhs.name() << " = " << rhs.k_;
    return os;
}