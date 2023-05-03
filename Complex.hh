// Complex.hh

#ifndef Complex_hh
#define Complex_hh

#include <iostream>
#include <cmath>
#include <sstream>

class Complex {
public:
    Complex(double re = 0, double im = 0);
    Complex(const Complex& comp);
    ~Complex() {};

    void setRe(double re) { real_ = re; };
    void setIm(double im) { imag_ = im; };

    double re() const { return real_; };
    double im() const { return imag_; };
    double mag() const;
    double phase() const;
    double r() const { return mag(); };
    double phi() const { return phase(); };

    std::string print()const;

    //MARK:- complex-complex operations

    Complex operator+(const Complex& rhs) const;
    Complex operator-(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;
    Complex operator/(const Complex& rhs) const;

    //MARK:- complex-real operations

    Complex operator+(const double& rhs) const;
    Complex operator-(const double& rhs) const;
    Complex operator*(const double& rhs) const;
    Complex operator/(const double& rhs) const;


private:
    double real_;
    double imag_;

};

Complex operator+(const double& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs);
Complex operator/(const double& lhs, const Complex& rhs);


#endif
