#include <Pythia8/Pythia.h>
#include <TFile.h>

#include "generator.h"
#include "analysis.h"

#include <filesystem>




int main() {
    std::filesystem::create_directories("../output/plots/png");
    std::filesystem::create_directories("../output/plots/pdf");

    const int nEvents = 100000;
    const int seed = 12345;

    Pythia8::Pythia pythia;
    setupPythia(pythia, seed);

    Histograms hists = bookHistograms();

    for (int i = 0; i < nEvents; ++i) {
        if (!pythia.next()) continue;
        analyzeEvent(pythia.event, hists);
    }

    pythia.stat();

    TFile out("../output/analysis.root", "RECREATE");

    hists.hN_all->Write();
    hists.hN_ch->Write();
    hists.hN_pip->Write();
    hists.hN_pim->Write();
    hists.hN_Kp->Write();
    hists.hN_Km->Write();
    hists.hN_p->Write();
    hists.hN_pbar->Write();

    hists.hPt_all->Write();
    hists.hEta_all->Write();
    hists.hPhi_all->Write();

    hists.hPt_ch->Write();
    hists.hEta_ch->Write();
    hists.hPhi_ch->Write();

    hists.hPt_pip->Write();
    hists.hEta_pip->Write();
    hists.hPhi_pip->Write();

    hists.hPt_pim->Write();
    hists.hEta_pim->Write();
    hists.hPhi_pim->Write();

    hists.hPt_Kp->Write();
    hists.hEta_Kp->Write();
    hists.hPhi_Kp->Write();

    hists.hPt_Km->Write();
    hists.hEta_Km->Write();
    hists.hPhi_Km->Write();

    hists.hPt_p->Write();
    hists.hEta_p->Write();
    hists.hPhi_p->Write();

    hists.hPt_pbar->Write();
    hists.hEta_pbar->Write();
    hists.hPhi_pbar->Write();

    out.cd();
    out.Write();
    out.Close();

    return 0;
}
