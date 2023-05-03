// histo_prova.cpp

#include "TH1F.h"
#include "TCanvas.h"

int main() {
    TH1F h1("h1", "my first histogram", 100, -6, 6);
    h1.FillRandom("gaus", 10000);

    h1.GetXaxis()->SetTitle("Gaussian variable");
    h1.GetYaxis()->SetTitle("arbitrary units");

    TCanvas c1("c1", "my canvas", 1024, 800);

    h1.Draw();

    c1.SaveAs("canvas.eps");

    h1.SetFillColor(kBlue);
    h1.Draw();
    c1.SaveAs("canvas-blue.eps");
    h1.Draw("pe");

    c1.SaveAs("canvas-points.eps");
    return 0;
}