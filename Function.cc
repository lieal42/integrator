//Function.cc

#include "Function.hh"
#include <string>
#include <iostream>

Function::Function(const std::string& name) {
    name_ = name;
}

Function::~Function() {

}

std::ostream& operator<<(std::ostream& os, const Function& rhs) {
    os << "generic function: " << rhs.name_;
    return os;
}
