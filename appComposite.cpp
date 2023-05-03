#include "Vector3D.hh"
#include <iostream>
#include <iomanip>
#include "SimpleBody.hh"
#include "CompositeSystem.hh"
#include "TGraph.h"
#include "TCanvas.h"
#include "TGaxis.h"
#include "TAxis.h"
#include "TMultiGraph.h"

#include <cmath>

using std::cout;
using std::endl;

int main() {

    TGraph* g1 = new TGraph();
    TGraph* g2 = new TGraph();
    TGraph* g3 = new TGraph();
    TCanvas c1("c1", "earth orbit", 1024, 800);
    TMultiGraph* mg = new TMultiGraph();


    double theta0 = M_PI / 10; // random position along the orbit
    double earthVel = 30.e3; // 30 km/s
    double astrUnit = 150.e9; // 150 x 10^6 km
    double earthMass = 6.e24; // kg
    SimpleBody earth("earth", earthMass, Vector3D(0, 0, 0));
    earth.setVelocity(Vector3D(0, 0, 0));

    double moonVel = 1.e3; // 1 km/s
    double moonDist = 384399.e3; // 384 399 km
    double moonMass = 7.e22; // kg
    SimpleBody moon("moon", moonMass, Vector3D(0, 0, 0));//Vector3D(moonDist * cos(theta0), moonDist * sin(theta0), 0));
    moon.setVelocity(Vector3D(0, 0, 0));
    //moon.setVelocity(Vector3D(-moonVel * sin(theta0), moonVel * cos(theta0), 0));

    CompositeSystem earthSystem("earth+moon", &earth);
    earthSystem.add(&moon,
        Vector3D(moonDist * cos(theta0), moonDist * sin(theta0), 0),
        Vector3D(-moonVel * sin(theta0), moonVel * cos(theta0), 0)
    );


    double sunMass = 2.e30; // kg
    SimpleBody sun("sun", sunMass, Vector3D(0, 0, 0));
    sun.setVelocity(Vector3D(0, 0, 0));


    CompositeSystem solarSystem("solarSystem", &sun);
    solarSystem.add(&earth, //System,
        Vector3D(astrUnit * cos(theta0), astrUnit * sin(theta0), 0),
        Vector3D(-earthVel * sin(theta0), earthVel * cos(theta0), 0));

    solarSystem.add(&moon,
        Vector3D(astrUnit * cos(theta0), astrUnit * sin(theta0), 0) + Vector3D(moonDist * cos(theta0), moonDist * sin(theta0), 0),
        Vector3D(-earthVel * sin(theta0), earthVel * cos(theta0), 0) + Vector3D(-moonVel * sin(theta0), moonVel * cos(theta0), 0));


    solarSystem.print();


    cout << std::setprecision(4) << std::setw(10);

    // estimate position every minute
    int days(600), hours(24), mins(60);
    for (int i = 0; i <= days * hours * mins; ++i) {

        if (i % (hours * mins * 10) == 0) {
            cout << " ---- Day: Hour " << i / (hours * mins) << ": " << i / (days * mins) << " ----- " << endl;
            cout << "earth position: " << earth.position()
                << endl;
            g1->SetPoint(g1->GetN(), earth.position().x(), earth.position().y());
            g2->SetPoint(g2->GetN(), sun.position().x(), sun.position().y());
            g3->SetPoint(g3->GetN(), moon.position().x(), moon.position().y());
        }
        earthSystem.evolve(60);
    }
    g1->SetTitle("Earth Orbit");
    g1->GetXaxis()->SetTitle("x[m]");
    g1->GetYaxis()->SetTitle("y[m]");
    solarSystem.print();
    mg->Add(g1);
    //mg->Add(g2);
    mg->Add(g3);

    mg->Draw("AC*");
    //g3->Draw("AC*");
    c1.SaveAs("solar-system-lol.pdf");
    //g1 = g2;
    //g2->Draw();
    //c1.SaveAs("o-sol.pdf");
    delete g1;

    return 0;

}