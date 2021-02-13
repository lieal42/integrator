// Polynomial.cc

#include "Polynomial.hh"
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

Polynomial::Polynomial(const std::string& name, const std::vector<double>& coeff) : Function(name) {
    coeff_ = coeff;
}

double Polynomial::value(double x) const {
    double sum = 0;
    int p = 0;
    for (double a : coeff_) {
        sum += a * pow(x, p);
        p++;
    }
    return sum;
}

double Polynomial::integrate(double xlo, double xhi) const {
    return integrator()->integrate(xlo, xhi, this);
}

double Polynomial::anIntegral(double xlo, double xhi) const {
    double sum1 = 0, sum2 = 0;;
    int p = 1;
    for (double a : coeff_) {
        sum1 += a / p * pow(xlo, p);
        p++;
    }
    p = 1;
    for (double a : coeff_) {
        sum2 += a / p * pow(xhi, p);
        p++;
    }
    return sum2 - sum1;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& rhs) {
    int p = 0;
    os << "polynomial function: " << rhs.name() << " = ";
    for (double a : rhs.coeff_) {
        os << "+(" << a << ")x^" << p;
        p++;
    }
    return os;
}