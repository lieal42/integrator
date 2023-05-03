#include "TString.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "Datum.hh"
#include "TRandom.h"
#include <iostream>
#include <cmath>

#ifdef __MAKECINT__
#pragma link C++ class Datum+;
#endif

int main() {
    TTree* tree = new TTree("datatree", "tree containing our data");

    TString rootfname("/tmp/custom-object.root");
    TFile* orootfile = new TFile(rootfname, "RECREATE");
    if (!orootfile->IsOpen()) {
        std::cerr << "file not opened. exiting..." << std::endl;
        exit(-1);
    }

    int nmeas = 100;
    double x0, x1 = 0.9, x2 = 1.1;
    double resol = 0.10;

    TRandom* gen = new TRandom();
    gen->SetSeed(0);

    Datum dato;

    tree->Branch("datum", &dato);


    for (int i = 0;i < nmeas;i++) {
        double x0 = x1 + gen->Uniform(x2 - x1);
        double x = gen->Gaus(x0, x0 * resol);
        double err = (x2 - x1) / sqrt(12);
        dato = Datum(x, gen->Gaus(err, err * 0.10));

        tree->Fill();
    }

    tree->Write();
    orootfile->Close();

    return 0;
}
