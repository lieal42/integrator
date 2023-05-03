// tets_complex_class.cpp

#include <iostream>
#include "Complex.hh"
using namespace std;

int main() {
    const Complex a(1, 0), b(3, 5);

    // proviamo i metodi get

    cout << "re(a): " << a.re() << endl;
    cout << "im(a): " << a.im() << endl;
    cout << "mag(a): " << b.mag() << "=" << b.r() << endl;
    cout << "phi(a): " << b.phase() << "=" << b.phi() << endl;

    // proviamo gli operatori com-com

    cout << "a+b=" << (a + b).print() << endl;
    cout << "a-b=" << (a - b).print() << endl;
    cout << "a*b=" << (a * b).print() << endl;
    cout << "a/b=" << (a / b).print() << endl;

    // operatori com-real

    cout << "b+3=" << (b + 3).print() << endl;
    cout << "b-3=" << (b - 3).print() << endl;
    cout << "b*3=" << (b * 3).print() << endl;
    cout << "b/3=" << (b / 3).print() << endl;

    // test rapido per real-com

    Complex d = 3 * a + 2 / b;

    cout << "d=" << d.print() << endl;

    cout << "3+b=" << (3 + b).print() << endl;
    cout << "3-b=" << (3 - b).print() << endl;
    cout << "3*b=" << (3 * b).print() << endl;
    cout << "3/b=" << (3 / b).print() << endl;
    return 0;
}