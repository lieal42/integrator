// integration_example.cpp

#include "CustomMCIntegrator.hh"
#include "CustomIntegrator.hh"
#include "Function.hh"
#include "Gauss.hh"
#include "Exponential.hh"
#include "Constant.hh"
#include "Polynomial.hh"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    CustomMCIntegrator cinteg = CustomMCIntegrator();
    Function* g1 = new Gauss("g1", 0, 1);
    Function* e1 = new Exponential("e1", 1, 1);
    Function* c1 = new Constant("c1", 1);
    Function* p1 = new Polynomial("p1", { 5,0,6,0,0,1,4,6431 });
    cinteg.setIntegrand(g1);

    double a, b;
    cout << "Program computes integral of the Gaussian function between a * sigma -> b * sigma" << endl;
    cout << "a";
    cin >> a;
    cout << "b";
    cin >> b;

    for (unsigned long int n = 10; n < 1e8; n *= 10) {
        cinteg.setNPoints(n);
        double sum = cinteg.integrate(a, b);
        cout << "# points: " << setw(10) << n << "\t Integral: " << setprecision(6) << sum << endl;
    }

    delete g1;

    cinteg.setIntegrand(e1);

    cout << "Now the exponential between 0 and 1..." << endl;

    for (unsigned long int n = 10; n < 1e8; n *= 10) {
        cinteg.setNPoints(n);
        double sum = cinteg.integrate(0, 1);
        cout << "# points: " << setw(10) << n << "\t Integral: " << setprecision(6) << sum << endl;
    }

    delete e1;

    cout << "Now the constant 1 between 0, 10..." << endl;

    cinteg.setIntegrand(c1);

    for (unsigned long int n = 10; n < 1e8; n *= 10) {
        cinteg.setNPoints(n);
        double sum = cinteg.integrate(0, 10);
        cout << "# points: " << setw(10) << n << "\t Integral: " << setprecision(6) << sum << endl;
    }

    delete c1;

    cout << "Yes, it's time for polynomial between 0 and 1" << endl;

    cinteg.setIntegrand(p1);

    for (unsigned long int n = 10; n < 1e8; n *= 10) {
        cinteg.setNPoints(n);
        double sum = cinteg.integrate(0, 1);
        cout << "# points: " << setw(10) << n << "\t Integral: " << setprecision(6) << sum << endl;
    }

    delete p1;

}