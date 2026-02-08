#ifndef GENERATOR_H
#define GENERATOR_H

#include <Pythia8/Pythia.h>

void setupPythia(Pythia8::Pythia& pythia, int seed);
void runGeneration(Pythia8::Pythia& pythia, int nEvents);

#endif
