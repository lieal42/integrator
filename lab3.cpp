#include <iostream>
#include <string>
#include <vector>
#include "Function.hh"
#include "Constant.hh"
#include "Exponential.hh"
#include "Polynomial.hh"

using std::cout;
using std::endl;

int main() {
    Function* k = new Constant("f", 4.3);
    cout << Constant("f", 4.3) << endl;
    cout << "val f(3):" << k->value(3) << endl;
    //cout << "der f(2):" << k->derivative(2) << endl;
    //cout << "int f(1,4)):" << k->integrate(1, 4) << endl;
    delete k;
    Function* exp = new Exponential("f", 1, 1);
    cout << Exponential("f", 1, 1) << endl;
    cout << "val f(1):" << exp->value(1) << endl;
    //cout << "der f(1):" << exp->derivative(1) << endl;
    //cout << "int f(0,1)):" << exp->integrate(0, 1) << endl;
    delete exp;
    std::vector<double> v = { 1,2,3,4,5 };
    Function* pol = new Polynomial("f", v);
    cout << Polynomial("f", v) << endl;
    cout << "val f(1):" << pol->value(1) << endl;
    //cout << "der f(1):" << pol->derivative(1) << endl;
    //cout << "int f(0,1)):" << pol->integrate(0, 1) << endl;
    delete pol;
}