#include "Sampler.h"


Sampler::Sampler(int numSamples) :
    mNumSamples(numSamples),
    mNumSets(100)
{
    GenerateSamples();
}

Sampler::~Sampler() {}

SamplerPoint2D Sampler::GetSample(int pixelIndex, int sampleNum) const {
    // Kevin's trick: Shuffle sets randomly using a modulo jump so adjacent pixels look unique
    int setID = (pixelIndex * 37) % mNumSets;
    int globalIndex = (setID * mNumSamples) + sampleNum;
    return mSamplePool[globalIndex];
}

void Sampler::GenerateSamples() {
    int totalPoints = mNumSamples * mNumSets;
    mSamplePool.reserve(totalPoints);

    // Get the grid size (e.g., if mNumSamples is 25, n is 5)
    int n = static_cast<int>(std::sqrt(mNumSamples));

    for (int set = 0; set < mNumSets; ++set) {
        for (int p = 0; p < n; ++p) {       // Row
            for (int q = 0; q < n; ++q) {   // Col

                // Use your Helper class to bake the jittered decimal offsets
                float jitterX = (Helper::rand_float() + q) / n;
                float jitterY = (Helper::rand_float() + p) / n;

                mSamplePool.push_back(SamplerPoint2D(jitterX, jitterY));
            }
        }
    }
}