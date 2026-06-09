#include "JitteredSampler.h"

#include "../SamplerHelper.h"

JitteredSampler::JitteredSampler(int numSamples, int numSets) :
    ISampler(numSamples, numSets)
{
    GenerateSamples();
}

JitteredSampler::~JitteredSampler() {}

void JitteredSampler::GenerateSamples() {
    mSamplePool.clear();
    mSamplePool.reserve(mNumSamples * mNumSets);
    int n = static_cast<int>(std::sqrt(mNumSamples));

    for (int set = 0; set < mNumSets; ++set) {
        for (int p = 0; p < n; ++p) {
            for (int q = 0; q < n; ++q) {
                float x = (Helper::rand_float() + q) / n;
                float y = (Helper::rand_float() + p) / n;
                mSamplePool.push_back(SamplerPoint2D(x, y));
            }
        }
    }

    SamplerHelper::RandomizeSamples(mSamplePool, mNumSamples, mNumSets);
}