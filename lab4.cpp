// lab4.cpp

#include "CustomMCIntegrator.hh"
#include "CustomIntegrator.hh"
#include "MidpointIntegrator.hh"
#include "Function.hh"
#include "Gauss.hh"
#include "Exponential.hh"
#include "Exponential1.hh"
#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    CustomMCIntegrator mci = CustomMCIntegrator();
    MidpointIntegrator mi = MidpointIntegrator();
    Function* e1 = new Exponential("e1", 1, 1);
    mci.setIntegrand(e1);
    mi.setIntegrand(e1);
    mci.setNPoints(1000);
    mi.setNPoint(1000);
    double realValue = Exponential1("", 1, 1).integrate(0, 1);
    TH1F h1("h1", "MC integration residuals (1000 points)", 20, -0.15, 0.15), h2("h2", "Midpoint integration residuals (10000 points)", 20, -0.15, 0.15);

    TGraph g1 = TGraph();
    TGraph g2 = TGraph();

    for (int i = 0; i < 100; i++) {
        double sum = mci.integrate(0, 1);
        double sum1 = mi.integrate(0, 1);
        h1.Fill(sum - realValue);
        h2.Fill(sum1 - realValue);
    }



    for (unsigned long int n = 10; n < 1e8; n *= 10) {
        mci.setNPoints(n);
        mi.setNPoint(n);
        double sum = mci.integrate(0, 1);
        double sum1 = mi.integrate(0, 1);
        g1.SetPoint(g1.GetN(), n, sum - realValue);
        g2.SetPoint(g2.GetN(), n, sum1 - realValue);
    }

    delete e1;

    TCanvas c1("c1", "MC istogram", 1024, 800);
    TCanvas c2("c2", "MP istogram", 1024, 800);
    h1.Draw();
    c2.SaveAs("residual-mc.pdf");

    h2.Draw();
    c2.SaveAs("residual-mp.pdf");

    g1.SetTitle("MC integration residuals vs #points");
    g2.SetTitle("Midpoint integration residuals vs #points");

    c2.SetLogx();

    g1.Draw("AL*");
    c2.SaveAs("residual-mc-tgraph.pdf");

    g2.Draw("AL*");
    c2.SaveAs("residuals-mp-tgraph.pdf");


    // now integrate gaussian between -1 and 1

    Function* ga1 = new Gauss("g1", 0, 1);

    mci.setIntegrand(ga1);
    mi.setIntegrand(ga1);

    cout << "mc integration:" << endl;
    for (unsigned long int n = 10; n < 1e8; n *= 10) {
        mci.setNPoints(n);
        double sum = mci.integrate(-1, 1);
        cout << "# points: " << setw(10) << n << "\t Integral: " << setprecision(6) << sum << endl;
    }

    cout << "midpoint integration:" << endl;
    for (unsigned long int n = 10; n < 1e8; n *= 10) {
        mi.setNPoint(n);
        double sum = mi.integrate(-1, 1);
        cout << "# points: " << setw(10) << n << "\t Integral: " << setprecision(6) << sum << endl;
    }

    delete ga1;

    return 0;
}
