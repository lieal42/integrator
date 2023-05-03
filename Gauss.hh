// Gauss.hh

#ifndef Gauss_hh
#define Gauss_hh

#include <string>
#include "Function.hh"


class Gauss : public Function {
public:
    Gauss(const std::string& name, double mean, double width);

    virtual double value(double x) const;

    void setMean(const double& mean);
    void setWidth(const double& width);

    friend std::ostream& operator<<(std::ostream& os, const Gauss& rhs);

private:
    double mean_;
    double width_;
};

#endif