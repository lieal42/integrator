//Function1.cc

#include "Function1.hh"
#include <string>
#include <iostream>

Function1::Function1(const std::string& name) {
    name_ = name;
}

Function1::~Function1() {

}

std::ostream& operator<<(std::ostream& os, const Function1& rhs) {
    os << "generic function: " << rhs.name_;
    return os;
}
