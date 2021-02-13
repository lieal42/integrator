// app.cpp

#include <vector>
#include <iostream>
#include "Function.hh"
#include "Polynomial.hh"
#include "Exponential.hh"
#include "MCIntegrator.hh"
#include "MidpointIntegrator.hh"
#include "TGraph.h"
#include "TCanvas.h"
#include "TLegend.h"


int main() {
    int i, j;
    std::vector<double> coeff; // make a vector with coefficients (a0,a1,a2,...)
    coeff.push_back(1);
    coeff.push_back(3);
    coeff.push_back(2);
    coeff.push_back(6);
    Function* g = new Exponential("e", 1, 1);
    Function* f = new Polynomial("p", coeff);
    Integrator* mc = new MCIntegrator();
    Integrator* mp = new MidpointIntegrator();
    double mcintg[ 6 ], mpintg[ 6 ], mcintf[ 6 ], mpintf[ 6 ], x[ 6 ], resmcg[ 6 ], resmpg[ 6 ], resmcf[ 6 ], resmpf[ 6 ];
    double anintg = g->anIntegral(0, 1), anintf = f->anIntegral(0, 1);
    g->setIntegrator(mc);
    f->setIntegrator(mc);
    for (i = 10, j = 0;i <= 1e6;i *= 10, j++) {
        mc->setNPoints(i);
        mcintg[ j ] = g->integrate(0, 1);
        mcintf[ j ] = f->integrate(0, 1);
        resmcg[ j ] = mcintg[ j ] - anintg;
        resmcf[ j ] = mcintf[ j ] - anintf;
        x[ j ] = j + 1;
    }
    g->setIntegrator(mp);
    f->setIntegrator(mp);
    for (i = 10, j = 0;i <= 1e6;i *= 10, j++) {
        mp->setNPoints(i);
        mpintg[ j ] = g->integrate(0, 1);
        mpintf[ j ] = f->integrate(0, 1);
        resmpg[ j ] = mpintg[ j ] - anintg;
        resmpf[ j ] = mpintf[ j ] - anintf;
    }

    TGraph* gr1 = new TGraph(6, x, resmcg);
    TGraph* gr2 = new TGraph(6, x, resmpg);
    TGraph* gr3 = new TGraph(6, x, resmcf);
    TGraph* gr4 = new TGraph(6, x, resmpf);

    TLegend* l1 = new TLegend();
    TLegend* l3 = new TLegend();

    TCanvas* c1 = new TCanvas("c1", "exponential residuals", 1024, 800);
    gr1->SetTitle("Exponential Residuals;log(#points);residual");
    l1->AddEntry(gr1, "MC integration");
    gr1->Draw();

    gr2->SetLineColor(2);
    l1->AddEntry(gr2, "MP integration");
    gr2->Draw("SAME");
    l1->Draw("SAME");
    c1->SaveAs("exponential.pdf");


    TCanvas* c3 = new TCanvas("c3", "polynomial residuals", 1024, 800);
    gr3->SetTitle("Polynomial Residuals;log(#points);residual");
    l3->AddEntry(gr3, "MC integration");
    gr3->Draw();

    gr4->SetLineColor(2);
    l3->AddEntry(gr4, "MP integration");
    gr4->Draw("SAME");
    l3->Draw("SAME");
    c3->SaveAs("polynomial.pdf");

    delete g;
    delete f;
    delete c1;
    delete c3;
    delete gr1;
    delete gr2;
    delete gr3;
    delete gr4;
    delete l1;
    delete l3;

    return EXIT_SUCCESS;
}

