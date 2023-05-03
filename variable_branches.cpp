// vaariable_brtanches.cpp

#include "TString.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "Datum.hh"
#include "TRandom.h"
#include <iostream>

int main() {
    double x1 = 0.9, x2 = 1.1;
    double resol = 0.10;
    const int nMeasMax = 200; // maximum size of static array per event
    double x0, x[ nMeasMax ], dx[ nMeasMax ];
    int nmeas;

    TString rootfname("/tmp/variable-size.root");
    TFile* orootfile = new TFile(rootfname, "RECREATE");
    if (!orootfile->IsOpen()) {
        std::cerr << "file not opened. exiting..." << std::endl;
        exit(-1);
    }


    TTree* tree = new TTree("datatree", "tree containing our data");
    tree->Branch("nmeas", &nmeas, "nmeas/I");
    tree->Branch("value", x, "value[nmeas]/D");
    tree->Branch("error", &dx, "error[nmeas]/D");

    // # measurements
    int nMeasAvg = 50;
    int nexp = 1000;

    TRandom* gen = new TRandom;
    gen->SetSeed(0);

    for (int iexp = 0; iexp < nexp; iexp++) {
        nmeas = gen->Poisson(nMeasAvg);

        if (nmeas > nMeasMax) {
            std::cerr << "WARNING: nmeas >" << nMeasMax << " yout TTree will be corrupted" << std::endl;
        }

        for (int i = 0; i < nmeas; i++) {
            // generate true value
            x0 = x1 + gen->Uniform(x2 - x1);

            // generate measured value based on the tre value and resolution
            x[ i ] = gen->Gaus(x0, x0 * resol);

            // generate an uncertainty based on the resolution
            dx[ i ] = x[ i ] * resol;
        }

        tree->Fill(); // write the data from memoru to the file at the end of each experiment
    } // end of the experiment

    tree->Write();

    orootfile->Close();


    /*delete orootfile;
    delete tree;*/

    return 0;
}