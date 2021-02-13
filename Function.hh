//Function.hh

#ifndef Function_hh
#define Function_hh

#include <string>
#include "Integrator.hh"

class Function {
public:
    Function(const std::string& name);
    virtual ~Function();
    virtual double value(double x) const = 0;

    void setIntegrator(Integrator* integrator) { integrator_ = integrator; };

    Integrator* integrator() const { return integrator_; };

    virtual double integrate(double xlo, double xhi) const = 0;

    virtual double anIntegral(double xlo, double xhi) const = 0;

    virtual std::string name() const { return name_; }

    friend std::ostream& operator<<(std::ostream& os, const Function& rhs);


private:
    std::string name_;
    Integrator* integrator_;
};
#endif