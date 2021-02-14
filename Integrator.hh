// Integrator.hh

#ifndef Integrator_hh
#define Integrator_hh

#include <iostream>

class Function;

class Integrator {
public:
    Integrator() {};
    virtual ~Integrator() {};
    virtual void setNPoints(int n) { std::cerr << "W:This integration method does not need a number of points." << std::endl << "Skipping..." << std::endl; };
    virtual int nPoints() const { std::cerr << "W:This integration method does not need a number of points." << std::endl << "Skipping..." << std::endl; };

    virtual double integrate(double xlo, double xhi, const Function* f) const = 0;
private:
};


#endif