// Series.hh

#ifndef Series_hh
#define Series_hh

#include "Resistor.hh"
#include <list>

class Series : public Resistor {
public:
    Series(const std::string& name);
    Series(const std::string& name, Resistor* resistor);

    //virtual std::string name() const; // uso la funzione della classe base
    virtual double value() const;
    virtual void print() const;

    //virtual void setName(const std::string& name); // uso la funzione della classe base
    virtual void setValue(const double& R) { std::cerr << "You can't change the value of a series" << std::endl; }

    void add(Resistor* resistor);

private:
    std::list<Resistor*> resistors_;
};

#endif