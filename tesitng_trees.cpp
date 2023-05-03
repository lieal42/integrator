// tesiting_trees.cpp

#include "TString.h"
#include "TTree.h"
#include "TFile.h"
#include "Datum.hh"
#include "TRandom.h"
#include <iostream>

int main() {
    TRandom* rand = new TRandom();
    rand->SetSeed(0);
    std::vector<Datum> dati;
    for (int i = 0;i < 100;i++) {
        dati.push_back(Datum(rand->Gaus(), rand->Gaus(1, 0.1)));
    }
    TString rootfname("/tmp/dati.root");
    TFile* orootfile = new TFile(rootfname, "RECREATE");
    if (!orootfile->IsOpen()) {
        std::cerr << "problems creating root file. exiting..." << std::endl;
        exit(-1);
    }
    std::cerr << "storing file in root file " << rootfname << std::endl;

    TTree* tree = new TTree("datatree", "tree containing our data");

    std::cerr << "Created the tree" << std::endl;

    // In the TFile the object of a TTree are stored with the tree root name "datatree"
    // and not with the C++ name "tree"

    double x, dx;

    tree->Branch("value", &x, "value/D");
    tree->Branch("error", &dx, "error/D");

    std::cout << "Defined the tree branches" << std::endl;

    for (Datum i : dati) {
        x = i.value();
        dx = i.error();

        tree->Fill();
    }

    std::cout << "Filled the tree" << std::endl;

    tree->Write();

    std::cout << "Wrote the file" << std::endl;

    orootfile->Close();

    std::cout << "Done!" << std::endl;

    /*delete tree;
    delete orootfile;
    delete rand;*/

    return 0;
}