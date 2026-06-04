#include "Sampler.h"


Sampler::Sampler(int numSamples, int numSets) :
    mNumSamples(numSamples),
    mNumSets(numSets)
{}

Sampler::~Sampler() {}

int Sampler::GetNumberOfSamples() const noexcept { return mNumSamples; }

SamplerPoint2D Sampler::GetSample(int pixelIndex, int sampleNum) const {
    // Kevin's trick: Shuffle sets randomly using a modulo jump so adjacent pixels look unique
    int setID = (pixelIndex * 37) % mNumSets;
    int globalIndex = (setID * mNumSamples) + sampleNum;
    return mSamplePool[globalIndex];
}