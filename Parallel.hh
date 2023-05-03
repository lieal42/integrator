// Parallel.hh

#ifndef Parallel_hh
#define Parallel_hh

#include "Resistor.hh"
#include <list>

class Parallel : public Resistor {
public:
    Parallel(const std::string& name);
    Parallel(const std::string& name, Resistor* resistor);

    //virtual std::string name() const; //uso la funzione della classe base
    virtual double value() const;
    virtual void print() const;

    virtual void setValue(const double& R) { std::cerr << "You can't change the value of a parallel" << std::endl; }

    void add(Resistor* resistor);

private:
    std::list<Resistor*> resistors_;
};

#endif