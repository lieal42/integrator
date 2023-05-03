// Resistor.cc

#include "Resistor.hh"

Resistor::Resistor(const std::string& name, const double& R) {
    name_ = name;
    R_ = R;
}

std::string Resistor::name() const {
    return name_;
}

double Resistor::value() const {
    return R_;
}

void Resistor::print() const {
    std::cout << name_ << ": " << R_ << " Ohm" << std::endl;
}

void Resistor::setName(const std::string& name) {
    name_ = name;
}

void Resistor::setValue(const double& R) {
    R_ = R;
}

std::ostream& operator<<(std::ostream& os, Resistor& rhs) {
    os << rhs.name_ << ": " << rhs.value() << " Ohm";
    return os;
}