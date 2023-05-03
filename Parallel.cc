// Parallel.cc

#include "Parallel.hh"
#include <iostream>

Parallel::Parallel(const std::string& name) : Resistor(name) {}

Parallel::Parallel(const std::string& name, Resistor* resistor) : Resistor(name) {
    resistors_.push_back(resistor);
}

double  Parallel::value() const {
    double res = 0;
    for (Resistor* i : resistors_) {
        res += 1 / i->value();
    }
    return 1 / res;
}

void Parallel::print() const {
    int j = 0;
    std::cout << "Parallel " << name() << ": ";
    for (Resistor* i : resistors_) {
        if (j > 0) { std::cout << " || "; }
        j++;
        std::cout << i->name();
    }
    std::cout << " : " << value() << " Ohm" << std::endl;
    for (Resistor* i : resistors_) {
        std::cout << "  ";
        i->print();
    }
}

void Parallel::add(Resistor* resistor) {
    resistors_.push_back(resistor);
}