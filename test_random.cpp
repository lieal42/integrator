#include "TRandom.h"
#include "Vector3D.hh"
#include <iostream>

int main() {
    TRandom rand(0);
    double x, y, z;
    rand.Sphere(x, y, z, 10);

    std::cout << x << y << z << std::endl;
}