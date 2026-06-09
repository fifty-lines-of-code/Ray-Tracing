#include "RegularSampler.h"

RegularSampler::RegularSampler(int numSamples, int numSets) :
    ISampler(numSamples, numSets) 
{
    GenerateSamples();
}

RegularSampler::~RegularSampler() {}

void RegularSampler::GenerateSamples() {
    mSamplePool.clear();
    mSamplePool.reserve(mNumSamples * mNumSets);
    int n = static_cast<int>(std::sqrt(mNumSamples));

    for (int set = 0; set < mNumSets; ++set) {
        for (int p = 0; p < n; ++p) {
            for (int q = 0; q < n; ++q) {
                float x = (q + 0.5f) / n;
                float y = (p + 0.5f) / n;
                mSamplePool.push_back(SamplerPoint2D(x, y));
            }
        }
    }
}