#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <Pythia8/Pythia.h>
#include <TH1F.h>

struct Histograms {

    TH1F* hN_all;
    TH1F* hN_ch;
    TH1F* hN_pip;
    TH1F* hN_pim;
    TH1F* hN_Kp;
    TH1F* hN_Km;
    TH1F* hN_p;
    TH1F* hN_pbar;

    TH1F* hPt_all;
    TH1F* hPt_ch;
    TH1F* hPt_pip;
    TH1F* hPt_pim;
    TH1F* hPt_Kp;
    TH1F* hPt_Km;
    TH1F* hPt_p;
    TH1F* hPt_pbar;

    TH1F* hEta_all;
    TH1F* hEta_ch;
    TH1F* hEta_pip;
    TH1F* hEta_pim;
    TH1F* hEta_Kp;
    TH1F* hEta_Km;
    TH1F* hEta_p;
    TH1F* hEta_pbar;

    TH1F* hPhi_all;
    TH1F* hPhi_ch;
    TH1F* hPhi_pip;
    TH1F* hPhi_pim;
    TH1F* hPhi_Kp;
    TH1F* hPhi_Km;
    TH1F* hPhi_p;
    TH1F* hPhi_pbar;
};

Histograms bookHistograms();
void analyzeEvent(const Pythia8::Event& event, Histograms& h);

#endif
