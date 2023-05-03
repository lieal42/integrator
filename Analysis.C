#define Analysis_cxx
#include "Analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <iostream>

void Analysis::Loop() {
   //   In a ROOT session, you can do:
   //      root> .L Analysis.C
   //      root> Analysis t
   //      root> t.GetEntry(12); // Fill t data members with entry number 12
   //      root> t.Show();       // Show values of entry 12
   //      root> t.Show(16);     // Read and show values of entry 16
   //      root> t.Loop();       // Loop on all entries
   //

   //     This is the loop skeleton where:
   //    jentry is the global entry number in the chain
   //    ientry is the entry number in the current Tree
   //  Note that the argument to GetEntry must be:
   //    jentry for TChain::GetEntry
   //    ientry for TTree::GetEntry and TBranch::GetEntry
   //
   //       To read only selected branches, Insert statements like:
   // METHOD1:
   //    fChain->SetBranchStatus("*",0);  // disable all branches
   //    fChain->SetBranchStatus("branchname",1);  // activate branchname
   // METHOD2: replace line
   //    fChain->GetEntry(jentry);       //read all branches
   //by  b_branchname->GetEntry(ientry); //read only this branch
   TH1F hmassprot("h1", "p-p invariant mass", 30, 1e3, 5e4);
   TH1F hptall("h2", "pt all particles", 30, 2e2, 5e2);
   TH1F hetall("h3", "eta all particles", 20, 0, 2 * M_PI);
   TH1F hphiall("h4", "phi all particles", 20, 0, 2 * M_PI);
   TH1F hmassall("h5", "invariant mass of all particles", 20, 5e3, 15e3);
   TH1F hetaless("h6", "eta distribution fot pt < 500GeV", 20, 0, 2 * M_PI);
   TH1F hetagreater("h7", "eta ditribution for pt > 500GeV", 20, 0, 2 * M_PI);
   TCanvas c1("c1", "canvas", 1024, 800);
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry = 0; jentry < nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      // proton invariant mass
      TLorentzVector pmass(0, 0, 0, 0);
      for (int i = 0; i < nGenPart; i++) {
         if (pdgId_genPart[ i ] == 2212) {
            TLorentzVector p;
            p.SetPtEtaPhiE(pt_genPart[ i ], eta_genPart[ i ], phi_genPart[ i ], energy_genPart[ i ]);
            p.Print();
            pmass += p;
         }
      }
      pmass.Print();
      std::cout << pmass.M() << std::endl;
      hmassprot.Fill(pmass.M());


      // endproton

      // not proton
      double ptall = 0, etall = 0, phiall = 0;
      TLorentzVector mass(0, 0, 0, 0);
      for (int i = 0; i < nGenPart; i++) {
         if (pdgId_genPart[ i ] == 2212) continue;
         ptall += pt_genPart[ i ] / nGenPart;
         etall += eta_genPart[ i ] / nGenPart;
         phiall += phi_genPart[ i ] / nGenPart;
         TLorentzVector p;
         p.SetPtEtaPhiE(pt_genPart[ i ], eta_genPart[ i ], phi_genPart[ i ], energy_genPart[ i ]);

         mass += p;
      }
      hptall.Fill(ptall);
      hetall.Fill(etall);
      hphiall.Fill(phiall);
      hmassall.Fill(mass.M());

      // end not proton

      // pt < 500GeV and > 500GeV
      double etaless = 0, etagreater = 0;
      for (int i = 0;i < nGenPart;i++) {
         if (pt_genPart[ i ] < 500) {
            etaless += eta_genPart[ i ] / nGenPart;
         } else if (pdgId_genPart[ i ] != 2212) {
            etagreater += eta_genPart[ i ] / nGenPart;
         }
      }
      hetaless.Fill(etaless);
      hetagreater.Fill(etagreater);
      // end pt<500GeV>

   }
   hmassprot.GetXaxis()->SetTitle("m[GeV]");
   hmassprot.GetYaxis()->SetTitle("#entries");
   hmassprot.Draw();
   c1.SaveAs("ppmass.pdf");

   hptall.GetXaxis()->SetTitle("pt[GeV]");
   hptall.GetYaxis()->SetTitle("#entries");
   hptall.Draw();
   c1.SaveAs("ptall.pdf");
   hetall.GetXaxis()->SetTitle("eta");
   hetall.GetYaxis()->SetTitle("#entries");
   hetall.Draw();
   c1.SaveAs("etall.pdf");
   hphiall.GetXaxis()->SetTitle("phi");
   hphiall.GetYaxis()->SetTitle("#entries");
   hphiall.Draw();
   c1.SaveAs("phiall.pdf");
   hmassall.GetXaxis()->SetTitle("m[GeV]");
   hmassall.GetYaxis()->SetTitle("#entries");
   hmassall.Draw();
   c1.SaveAs("massall.pdf");
   hetaless.GetXaxis()->SetTitle("eta");
   hetaless.GetYaxis()->SetTitle("#entries");
   hetaless.Draw();
   c1.SaveAs("etaless.pdf");
   hetagreater.GetXaxis()->SetTitle("eta");
   hetagreater.GetYaxis()->SetTitle("#entries");
   hetagreater.Draw();
   c1.SaveAs("etagreater.pdf");
}
