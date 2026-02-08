void draw_plots() {

    gROOT->SetBatch(kTRUE);

    TFile *f = TFile::Open("output/analysis.root");
    if (!f || f->IsZombie()) return;

    gStyle->SetOptStat(0);

    struct PlotDef {
        const char* name;
        const char* title;
        const char* x;
        const char* y;
        const char* out;
    };

    PlotDef plots[] = {
        {"hN_all",   "Multiplicity (all)",   "Multiplicity N", "Counts", "hN_all"},
        {"hN_ch",    "Multiplicity (charged)", "Multiplicity N", "Counts", "hN_ch"},
        {"hN_pip",   "Multiplicity #pi^{+}", "Multiplicity N", "Counts", "hN_pip"},
        {"hN_pim",   "Multiplicity #pi^{-}", "Multiplicity N", "Counts", "hN_pim"},
        {"hN_Kp",    "Multiplicity K^{+}",   "Multiplicity N", "Counts", "hN_Kp"},
        {"hN_Km",    "Multiplicity K^{-}",   "Multiplicity N", "Counts", "hN_Km"},
        {"hN_p",     "Multiplicity p",        "Multiplicity N", "Counts", "hN_p"},
        {"hN_pbar",  "Multiplicity #bar{p}",  "Multiplicity N", "Counts", "hN_pbar"},

        {"hPt_all",  "p_{T} (all)",   "p_{T} [GeV]", "Counts", "hPt_all"},
        {"hPt_ch",   "p_{T} (charged)", "p_{T} [GeV]", "Counts", "hPt_ch"},
        {"hPt_pip",  "p_{T} #pi^{+}", "p_{T} [GeV]", "Counts", "hPt_pip"},
        {"hPt_pim",  "p_{T} #pi^{-}", "p_{T} [GeV]", "Counts", "hPt_pim"},
        {"hPt_Kp",   "p_{T} K^{+}",   "p_{T} [GeV]", "Counts", "hPt_Kp"},
        {"hPt_Km",   "p_{T} K^{-}",   "p_{T} [GeV]", "Counts", "hPt_Km"},
        {"hPt_p",    "p_{T} p",       "p_{T} [GeV]", "Counts", "hPt_p"},
        {"hPt_pbar", "p_{T} #bar{p}", "p_{T} [GeV]", "Counts", "hPt_pbar"},

        {"hEta_all",  "#eta (all)",   "#eta", "Counts", "hEta_all"},
        {"hEta_ch",   "#eta (charged)", "#eta", "Counts", "hEta_ch"},
        {"hEta_pip",  "#eta #pi^{+}", "#eta", "Counts", "hEta_pip"},
        {"hEta_pim",  "#eta #pi^{-}", "#eta", "Counts", "hEta_pim"},
        {"hEta_Kp",   "#eta K^{+}",   "#eta", "Counts", "hEta_Kp"},
        {"hEta_Km",   "#eta K^{-}",   "#eta", "Counts", "hEta_Km"},
        {"hEta_p",    "#eta p",       "#eta", "Counts", "hEta_p"},
        {"hEta_pbar", "#eta #bar{p}", "#eta", "Counts", "hEta_pbar"},

        {"hPhi_all",  "#phi (all)",   "#phi [rad]", "Counts", "hPhi_all"},
        {"hPhi_ch",   "#phi (charged)", "#phi [rad]", "Counts", "hPhi_ch"},
        {"hPhi_pip",  "#phi #pi^{+}", "#phi [rad]", "Counts", "hPhi_pip"},
        {"hPhi_pim",  "#phi #pi^{-}", "#phi [rad]", "Counts", "hPhi_pim"},
        {"hPhi_Kp",   "#phi K^{+}",   "#phi [rad]", "Counts", "hPhi_Kp"},
        {"hPhi_Km",   "#phi K^{-}",   "#phi [rad]", "Counts", "hPhi_Km"},
        {"hPhi_p",    "#phi p",       "#phi [rad]", "Counts", "hPhi_p"},
        {"hPhi_pbar", "#phi #bar{p}", "#phi [rad]", "Counts", "hPhi_pbar"}
    };

    const int nPlots = sizeof(plots) / sizeof(PlotDef);

    for (int i = 0; i < nPlots; ++i) {
        TH1* h = (TH1*)f->Get(plots[i].name);
        if (!h) continue;

        TCanvas* c = new TCanvas(plots[i].out, plots[i].out, 800, 600);
        h->SetTitle(plots[i].title);
        h->GetXaxis()->SetTitle(plots[i].x);
        h->GetYaxis()->SetTitle(plots[i].y);
        h->Draw();

        c->SaveAs(Form("output/plots/png/%s.png", plots[i].out));
        c->SaveAs(Form("output/plots/pdf/%s.pdf", plots[i].out));

        delete c;
    }

    f->Close();
}
