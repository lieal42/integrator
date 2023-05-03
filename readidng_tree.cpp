// reading_tree.cpp

#include "TString.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "Datum.hh"
#include "TRandom.h"
#include <iostream>

int main() {
    TH1F hx1("hx1", "value", 10, -5, 5);
    TH1F hdx1("hdx1", "error", 10, -0.5, 0.5);
    TString rootfname("/tmp/dati.root");
    TFile* orootfile = new TFile(rootfname);
    if (!orootfile->IsOpen()) {
        std::cerr << "problems opening the root file. exiting..." << std::endl;
        exit(-1);
    }

    TTree* tree = (TTree*)orootfile->Get("datatree"); // Explicit casting to TTre* object
    if (!tree) {
        std::cerr << "null pointer fot TTree! exiting..." << std::endl;
        exit(-1);
    }

    double y, dy;

    tree->SetBranchAddress("value", &y);
    tree->SetBranchAddress("error", &dy);

    int nentries = tree->GetEntries();
    for (int i = 0; i < nentries; i++) {
        tree->GetEntry(i);

        hx1.Fill(y);
        hdx1.Fill(dy);
    }

}