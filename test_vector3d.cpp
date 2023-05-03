#include "Vector3D.hh"
#include <iostream>

using namespace std;

int main() {
    const Vector3D a(1, 1, 1, "cartesian");
    const Vector3D b = a;
    const Vector3D c = b + a;
    Vector3D f = a;
    f += a;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c = b + a: " << c << endl;
    cout << "f = a + a (f+=): " << f << endl;

    cout << "dist(f,a): " << f.distance(a) << " = " << a.distance(f) << endl;

    return 0;

}