#include "ISampler.h"


ISampler::ISampler(int numSamples, int numSets) :
    mNumSamples(numSamples),
    mNumSets(numSets)
{}

ISampler::~ISampler() {}

int ISampler::GetNumberOfSamples() const noexcept { return mNumSamples; }

SamplerPoint2D ISampler::GetSample(int pixelIndex, int sampleNum) const {
    // Kevin's trick: Shuffle sets randomly using a modulo jump so adjacent pixels look unique
    int setID = (pixelIndex * 103) % mNumSets;
    int globalIndex = (setID * mNumSamples) + sampleNum;
    return mSamplePool[globalIndex];
}