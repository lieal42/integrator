// lab6.cpp

#include <iostream>
#include <string>
#include "TH1F.h"
#include "TCanvas.h"
#include "TLorentzVector.h"
#include "TGraph.h"
#include "Particle.hh"
#include "TRandom.h"
#include <cmath>
#include <vector>
#include "CompositeParticle.hh"
#include "TLegend.h"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"

#include "Vector3D.hh"
#ifdef __MAKECINT__
#pragma link C++ class Vector3D+;
#endif

int main() {
    double mB = 5279, mpi = 140, mK = 500; // MeV
    double px = 300; // MeV
    double bx = px / sqrt(mB * mB + px * px);
    Vector3D b(bx, 0, 0);
    double pCoM = sqrt(mB * mB * mB * mB + mpi * mpi * mpi * mpi + mK * mK * mK * mK - 2 * mB * mB * mpi * mpi - 2 * mB * mB * mK * mK - 2 * mpi * mpi * mK * mK) / (2 * mB);
    double x, y, z;
    double angle;
    double ppiNew, pkNew;
    double resolution = 0.03;
    int npar = 2;
    double m[ npar ], theta[ npar ], phi[ npar ];
    Vector3D p[ npar ];
    TString rfilename("particle-tree.root");

    TFile* orootfile = new TFile(rfilename, "RECREATE");

    if (!orootfile->IsOpen()) {
        std::cout << "error in opening file. exiting..." << std::endl;
        exit(-1);
    }

    TTree* tree = new TTree("Bdatatree", "tree containing data of particles");

    tree->Branch("p_B", &b);
    tree->Branch("nDau", &npar, "nDau/I");
    tree->Branch("mass[nDau]", m, "mass[nDau]/D");
    tree->Branch("p[nDau]", p);
    tree->Branch("theta[nDau", theta, "theta[nDau]/D");
    tree->Branch("phi[nDau", phi, "phi[nDau]/D");

    TH1F trueMass("true mass", "True Mass", 100, 5278, 5280);
    TH1F openingAngle("opening angle", "Opening Angle", 100, 0, 2 * M_PI);
    TH1F measuredMass("measured mass", "Measured Mass", 100, 4580, 6000);
    TCanvas c1("c1", "True Mass", 1024, 800);
    TRandom rand = TRandom(0);
    for (int i = 0; i < 10e4;i++) {
        rand.Sphere(x, y, z, pCoM);
        Particle* pi = new Particle("pi", x, y, z, mpi);
        Particle* k = new Particle("k", -x, -y, -z, mK);
        CompositeParticle* B = new CompositeParticle("B", pi);
        B->add(k);
        B->boost(-1 * b);

        trueMass.Fill(B->mass());

        angle = scalarProduct(pi->p(), k->p()) / (pi->p().r() * k->p().r());
        openingAngle.Fill(acos(angle));

        ppiNew = rand.Gaus(pi->p().r(), pi->p().r() * resolution);
        pkNew = rand.Gaus(k->p().r(), k->p().r() * resolution);

        pi->setp(Vector3D(ppiNew, pi->p().theta(), pi->p().phi(), "polar"));
        k->setp(Vector3D(pkNew, k->p().theta(), k->p().phi(), "polar"));

        m[ 0 ] = pi->mass();
        m[ 1 ] = k->mass();
        p[ 0 ] = pi->p();
        p[ 1 ] = k->p();
        theta[ 0 ] = pi->p().theta();
        theta[ 1 ] = k->p().theta();
        phi[ 0 ] = pi->p().phi();
        phi[ 1 ] = k->p().phi();

        tree->Fill();

        measuredMass.Fill(B->mass());

        delete pi;
        delete k;
        delete B;
    }

    tree->Write();
    orootfile->Close();


    trueMass.GetXaxis()->SetTitle("m [MeV]");
    trueMass.GetYaxis()->SetTitle("#measurements");

    trueMass.Draw();

    c1.SaveAs("true-mass.pdf");

    TCanvas c2("c2", "Opening Angle", 1024, 800);

    openingAngle.GetXaxis()->SetTitle("theta [rad]");
    openingAngle.GetYaxis()->SetTitle("#measurements");

    openingAngle.Draw();

    c2.SaveAs("opening-angle.pdf");

    TCanvas c3("c3", "Measured Mass", 1024, 800);

    measuredMass.GetXaxis()->SetTitle("m [MeV]");
    measuredMass.GetYaxis()->SetTitle("#measurements");

    measuredMass.Draw();

    c3.SaveAs("measured-mass.pdf");

    TCanvas c4("c4", "invariant Mass", 1024, 800);
    TLegend l1 = TLegend();

    measuredMass.SetTitle("Invariant Mass");
    trueMass.SetTitle("Invariant Mass");
    trueMass.SetLineColor(kRed);
    measuredMass.SetStats(false);
    trueMass.SetStats(false);

    measuredMass.Draw();
    trueMass.Draw("SAME");

    l1.AddEntry(&measuredMass, "Measured Mass");
    l1.AddEntry(&trueMass, "True Mass");

    l1.Draw("SAME");

    c4.SaveAs("invariant-mass.pdf");

    TH1F h1("h1", "Different Detectors", 100, 4380, 6200), h2("h2", "", 100, 4380, 6200), h3("h3", "", 100, 4380, 6200);
    TCanvas c5("c5", "", 1024, 800);

    for (int i = 0; i < 10e4;i++) {
        rand.Sphere(x, y, z, pCoM);
        Particle* pi = new Particle("pi", x, y, z, mpi);
        Particle* k = new Particle("k", -x, -y, -z, mK);
        CompositeParticle* B = new CompositeParticle("B", pi);
        B->add(k);
        B->boost(-1 * b);

        Vector3D ppi = pi->p();
        Vector3D pk = k->p();

        ppiNew = rand.Gaus(ppi.r(), ppi.r() * 0.01);
        pkNew = rand.Gaus(pk.r(), pk.r() * 0.01);

        pi->setp(Vector3D(ppiNew, ppi.theta(), pi->p().phi(), "polar"));
        k->setp(Vector3D(pkNew, pk.theta(), k->p().phi(), "polar"));

        h1.Fill(B->mass());

        ppiNew = rand.Gaus(ppi.r(), ppi.r() * 0.05);
        pkNew = rand.Gaus(pk.r(), pk.r() * 0.05);

        pi->setp(Vector3D(ppiNew, ppi.theta(), ppi.phi(), "polar"));
        k->setp(Vector3D(pkNew, pk.theta(), pk.phi(), "polar"));

        h2.Fill(B->mass());

        ppiNew = rand.Gaus(ppi.r(), ppi.r() * 0.1);
        pkNew = rand.Gaus(pk.r(), pk.r() * 0.1);

        pi->setp(Vector3D(ppiNew, ppi.theta(), ppi.phi(), "polar"));
        k->setp(Vector3D(pkNew, pk.theta(), pk.phi(), "polar"));

        h3.Fill(B->mass());

        ppi.~Vector3D();
        pk.~Vector3D();

        delete pi;
        delete k;
        delete B;
    }

    h2.SetLineColor(kRed);
    h3.SetLineColor(kGreen);
    h1.SetStats(false);
    h2.SetStats(false);
    h3.SetStats(false);

    h1.Draw();
    h2.Draw("SAME");
    h3.Draw("SAME");

    TLegend l2 = TLegend();
    l2.AddEntry(&h1, "1% momentum resolution");
    l2.AddEntry(&h2, "5% momentum resolution");
    l2.AddEntry(&h3, "10% momentum resolution");

    l2.Draw("SAME");

    c5.SaveAs("different-detectors.pdf");

    return 0;
}