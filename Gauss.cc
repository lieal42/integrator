// Gauss.cc

#include "Gauss.hh"
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

Gauss::Gauss(const std::string& name, double mean, double width) : Function(name) {
    mean_ = mean;
    width_ = width;
}

double Gauss::value(double x) const {
    double pull = (x - mean_) / width_;
    double y = (1 / sqrt(2. * M_PI * width_)) * exp(-pull * pull / 2);
    return y;
}

void Gauss::setMean(const double& mean) {
    mean_ = mean;
}

void Gauss::setWidth(const double& width) {
    width_ = width;
}

std::ostream& operator<<(std::ostream& os, const Gauss& rhs) {
    os << "gaussian function: " << rhs.name() << "(x) = 1 / sqrt( 2 * pi * " << rhs.width_ << " ) * exp( - ( x - " << rhs.mean_ << " ) ^ 2 / ( 2 * " << rhs.width_ << " ) )";
    return os;
}