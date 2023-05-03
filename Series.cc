// Series.cc

#include "Series.hh"
#include <iostream>

Series::Series(const std::string& name) : Resistor(name) {}

Series::Series(const std::string& name, Resistor* resistor) : Resistor(name) {
    resistors_.push_back(resistor);
}

double  Series::value() const {
    double res = 0;
    for (Resistor* i : resistors_) {
        res += i->value();
    }
    return res;
}

void Series::print() const {
    int j = 0;
    std::cout << "Parallel " << name() << ": ";
    for (Resistor* i : resistors_) {
        if (j > 0) { std::cout << " -- "; }
        j++;
        std::cout << i->name();
    }
    std::cout << " : " << value() << " Ohm" << std::endl;
    for (Resistor* i : resistors_) {
        std::cout << "  ";
        i->print();
    }
}

void Series::add(Resistor* resistor) {
    resistors_.push_back(resistor);
}