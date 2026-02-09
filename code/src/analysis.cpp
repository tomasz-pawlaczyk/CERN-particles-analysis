#include "analysis.h"
#include <cmath>

using namespace Pythia8;

Histograms bookHistograms() {
    Histograms h;

    h.hN_all  = new TH1F("hN_all",  "N all",  400, 0, 400);
    h.hN_ch   = new TH1F("hN_ch",   "N ch",   400, 0, 400);
    h.hN_pip  = new TH1F("hN_pip",  "N pip",  400, 0, 400);
    h.hN_pim  = new TH1F("hN_pim",  "N pim",  400, 0, 400);
    h.hN_Kp   = new TH1F("hN_Kp",   "N Kp",   400, 0, 400);
    h.hN_Km   = new TH1F("hN_Km",   "N Km",   400, 0, 400);
    h.hN_p    = new TH1F("hN_p",    "N p",    400, 0, 400);
    h.hN_pbar = new TH1F("hN_pbar", "N pbar", 400, 0, 400);

    h.hPt_all  = new TH1F("hPt_all",  "pT all",  100, 0, 10);
    h.hEta_all = new TH1F("hEta_all", "eta all", 100, -5, 5);
    h.hPhi_all = new TH1F("hPhi_all", "phi all", 64, 0, M_PI);

    h.hPt_ch  = new TH1F("hPt_ch",  "pT ch",  100, 0, 10);
    h.hEta_ch = new TH1F("hEta_ch", "eta ch", 100, -5, 5);
    h.hPhi_ch = new TH1F("hPhi_ch", "phi ch", 64, 0, M_PI);

    h.hPt_pip  = new TH1F("hPt_pip",  "pT pip",  100, 0, 10);
    h.hEta_pip = new TH1F("hEta_pip", "eta pip", 100, -5, 5);
    h.hPhi_pip = new TH1F("hPhi_pip", "phi pip", 64, 0, M_PI);

    h.hPt_pim  = new TH1F("hPt_pim",  "pT pim",  100, 0, 10);
    h.hEta_pim = new TH1F("hEta_pim", "eta pim", 100, -5, 5);
    h.hPhi_pim = new TH1F("hPhi_pim", "phi pim", 64, 0, M_PI);

    h.hPt_Kp  = new TH1F("hPt_Kp",  "pT Kp",  100, 0, 10);
    h.hEta_Kp = new TH1F("hEta_Kp", "eta Kp", 100, -5, 5);
    h.hPhi_Kp = new TH1F("hPhi_Kp", "phi Kp", 64, 0, M_PI);

    h.hPt_Km  = new TH1F("hPt_Km",  "pT Km",  100, 0, 10);
    h.hEta_Km = new TH1F("hEta_Km", "eta Km", 100, -5, 5);
    h.hPhi_Km = new TH1F("hPhi_Km", "phi Km", 64, 0, M_PI);

    h.hPt_p  = new TH1F("hPt_p",  "pT p",  100, 0, 10);
    h.hEta_p = new TH1F("hEta_p", "eta p", 100, -5, 5);
    h.hPhi_p = new TH1F("hPhi_p", "phi p", 64, 0, M_PI);

    h.hPt_pbar  = new TH1F("hPt_pbar",  "pT pbar",  100, 0, 10);
    h.hEta_pbar = new TH1F("hEta_pbar", "eta pbar", 100, -5, 5);
    h.hPhi_pbar = new TH1F("hPhi_pbar", "phi pbar", 64, 0, M_PI);

    return h;
}

void analyzeEvent(const Event& event, Histograms& h) {

    int n_all = 0, n_ch = 0, n_pip = 0, n_pim = 0, n_Kp = 0, n_Km = 0, n_p = 0, n_pbar = 0;

    for (int i = 0; i < event.size(); ++i) {
        const Particle& p = event[i];
        if (!p.isFinal()) continue;

        n_all++;

        h.hPt_all->Fill(p.pT());
        h.hEta_all->Fill(p.eta());
        h.hPhi_all->Fill(p.phi());

        int id = p.id();

        if (p.charge() != 0) {
            n_ch++;
            h.hPt_ch->Fill(p.pT());
            h.hEta_ch->Fill(p.eta());
            h.hPhi_ch->Fill(p.phi());
        }

        if (id == 211) {
            n_pip++;
            h.hPt_pip->Fill(p.pT());
            h.hEta_pip->Fill(p.eta());
            h.hPhi_pip->Fill(p.phi());
        }
        if (id == -211) {
            n_pim++;
            h.hPt_pim->Fill(p.pT());
            h.hEta_pim->Fill(p.eta());
            h.hPhi_pim->Fill(p.phi());
        }
        if (id == 321) {
            n_Kp++;
            h.hPt_Kp->Fill(p.pT());
            h.hEta_Kp->Fill(p.eta());
            h.hPhi_Kp->Fill(p.phi());
        }
        if (id == -321) {
            n_Km++;
            h.hPt_Km->Fill(p.pT());
            h.hEta_Km->Fill(p.eta());
            h.hPhi_Km->Fill(p.phi());
        }
        if (id == 2212) {
            n_p++;
            h.hPt_p->Fill(p.pT());
            h.hEta_p->Fill(p.eta());
            h.hPhi_p->Fill(p.phi());
        }
        if (id == -2212) {
            n_pbar++;
            h.hPt_pbar->Fill(p.pT());
            h.hEta_pbar->Fill(p.eta());
            h.hPhi_pbar->Fill(p.phi());
        }
    }

    h.hN_all->Fill(n_all);
    h.hN_ch->Fill(n_ch);
    h.hN_pip->Fill(n_pip);
    h.hN_pim->Fill(n_pim);
    h.hN_Kp->Fill(n_Kp);
    h.hN_Km->Fill(n_Km);
    h.hN_p->Fill(n_p);
    h.hN_pbar->Fill(n_pbar);
}
