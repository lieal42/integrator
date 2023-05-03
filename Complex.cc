// Complex.cc

#include "Complex.hh"
#include <iostream>
#include <cmath>
#include <sstream>


Complex::Complex(double re, double im) {
    real_ = re;
    imag_ = im;
}

Complex::Complex(const Complex& comp) {
    real_ = comp.re();
    imag_ = comp.im();
}

double Complex::mag() const {
    return sqrt(real_ * real_ + imag_ * imag_);
}

double Complex::phase() const {
    if (real_ == 0) {
        return ((imag_ > 0) - (imag_ < 0)) * M_PI_2;
    }
    double angle = atan(imag_ / real_);
    if (real_ < 0) {
        return atan(imag_ / real_) + ((imag_ > 0) - (imag_ < 0)) * M_PI;
    }
    return atan(imag_ / real_);
}

std::string Complex::print()const {
    std::ostringstream testo;
    testo << real_ << "+(" << imag_ << ")i";
    return testo.str();
}

Complex Complex::operator+(const Complex& rhs) const {
    Complex sum(real_ + rhs.real_, imag_ + rhs.imag_);
    return sum;
}

Complex Complex::operator-(const Complex& rhs) const {
    Complex sub(real_ - rhs.real_, imag_ - rhs.imag_);
    return sub;
}

Complex Complex::operator*(const Complex& rhs) const {
    Complex prod(real_ * rhs.real_ - imag_ * rhs.imag_, real_ * rhs.imag_ + imag_ * rhs.real_);
    return prod;
}

Complex Complex::operator/(const Complex& rhs) const {
    Complex num1(real_, imag_);
    Complex num(rhs.real_ / (rhs.mag() * rhs.mag()), -rhs.imag_ / (rhs.mag() * rhs.mag()));
    return (num1 * num);
}

Complex Complex::operator+(const double& rhs) const {
    Complex sum(real_ + rhs, imag_);
    return sum;
}

Complex Complex::operator-(const double& rhs) const {
    Complex sub(real_ - rhs, imag_);
    return sub;
}

Complex Complex::operator*(const double& rhs) const {
    Complex prod(real_ * rhs, imag_ * rhs);
    return prod;
}

Complex Complex::operator/(const double& rhs) const {
    Complex num(real_ * (1. / rhs), imag_ * (1. / rhs));
    return (num);
}

Complex operator+(const double& lhs, const Complex& rhs) {
    Complex sum(lhs + rhs.re(), rhs.im());
    return sum;
}
Complex operator-(const double& lhs, const Complex& rhs) {
    Complex sub(lhs - rhs.re(), -rhs.im());
    return sub;
}
Complex operator*(const double& lhs, const Complex& rhs) {
    Complex prod(lhs * rhs.re(), lhs * rhs.im());
    return prod;
}
Complex operator/(const double& lhs, const Complex& rhs) {
    Complex num(rhs.re() / (rhs.mag() * rhs.mag()), -rhs.im() / (rhs.mag() * rhs.mag()));
    return (lhs * num);
}
