#include "generator.h"
#include <iostream>

using namespace Pythia8;

void setupPythia(Pythia& pythia, int seed) {

    pythia.readString("Beams:idA = 2212");
    pythia.readString("Beams:idB = 2212");
    pythia.readString("Beams:eCM = 13600.");

    pythia.readString("SoftQCD:all = on");

    pythia.readString("Random:setSeed = on");
    pythia.readString("Random:seed = " + std::to_string(seed));

    // WYCISZENIE OUTPUTU
    pythia.readString("Init:showChangedSettings = off");
    pythia.readString("Init:showChangedParticleData = off");
    pythia.readString("Next:numberShowEvent = 0");
    pythia.readString("Init:showProcesses = off");
    pythia.readString("Init:showAllSettings = off");
    pythia.readString("Stat:showPartonLevel = off");
    pythia.readString("Stat:showProcessLevel = on");



    pythia.init();
}

void runGeneration(Pythia& pythia, int nEvents) {

    for (int iEvent = 0; iEvent < nEvents; ++iEvent) {
        if (!pythia.next()) continue;
    }

    pythia.stat();
}
