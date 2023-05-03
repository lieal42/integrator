// lab5.cpp

#include "Resistor.hh"
#include "Parallel.hh"
#include "Series.hh"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    Resistor r1("r1", 1000);
    Resistor r2("r2", 1000);
    Parallel p1("p1");
    Series s1("s1");
    p1.add(&r1);
    p1.add(&r2);
    s1.add(&r1);
    s1.add(&r2);
    p1.print();
    s1.print();
    r1.print();
    r1.setValue(500);
    p1.print();
    s1.print();
    r1.print();

    std::cout << r1 << "|---|" << p1 << "|---|" << s1 << std::endl;
    return 0;
}