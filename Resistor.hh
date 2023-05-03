// Resistor.hh

#ifndef Resistor_hh
#define Resistor_hh

#include <iostream>
#include <string>

class Resistor {
public:
    Resistor(const std::string& name, const double& R = 0);
    virtual ~Resistor() {}

    virtual std::string name() const;
    virtual double value() const;
    virtual void print() const;

    virtual void setName(const std::string& name);
    virtual void setValue(const double& R);

    friend std::ostream& operator<<(std::ostream& os, Resistor& rhs);

private:
    std::string name_;
    double R_;

};

#endif