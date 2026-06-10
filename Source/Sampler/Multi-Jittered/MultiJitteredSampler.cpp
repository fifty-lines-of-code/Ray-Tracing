#include "MultiJitteredSampler.h"

#include "../SamplerHelper.h"

MultiJitteredSampler::MultiJitteredSampler(int numSamples, int numSets) :
    ISampler(numSamples, numSets)
{
    GenerateSamples();
}

MultiJitteredSampler::~MultiJitteredSampler() {}

void MultiJitteredSampler::GenerateSamples() {
    // num_samples must be a perfect square
    int n = static_cast<int>(sqrt(mNumSamples));
    float subcell_width = 1.f / mNumSamples;

    // Fill the sample vector with initial values
    for (int p = 0; p < mNumSamples * mNumSets; p++) {
        mSamplePool.push_back(SamplerPoint2D(0.0, 0.0));
    }

    for (int j = 0; j < mNumSets; j++) {
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                mSamplePool[j * mNumSamples + p * n + q].x = (q * n + p + Helper::rand_float()) * subcell_width;
                mSamplePool[j * mNumSamples + p * n + q].y = (p * n + q + Helper::rand_float()) * subcell_width;
            }
        }
    }

    for (int j = 0; j < mNumSets; j++) {
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                int k = Helper::rand_int(q, n - 1); // Helper to get a random int between q and n-1
                double t = mSamplePool[j * mNumSamples + p * n + q].x;
                mSamplePool[j * mNumSamples + p * n + q].x = mSamplePool[j * mNumSamples + p * n + k].x;
                mSamplePool[j * mNumSamples + p * n + k].x = t;
            }
        }
    }

    for (int j = 0; j < mNumSets; j++) {
        for (int q = 0; q < n; q++) {
            for (int p = 0; p < n; p++) {
                int k = Helper::rand_int(p, n - 1); // Helper to get a random int between p and n-1
                double t = mSamplePool[j * mNumSamples + p * n + q].y;
                mSamplePool[j * mNumSamples + p * n + q].y = mSamplePool[j * mNumSamples + k * n + q].y;
                mSamplePool[j * mNumSamples + k * n + q].y = t;
            }
        }
    }

    // map to unit disk
    MapSamplesToUnitDisk();
}