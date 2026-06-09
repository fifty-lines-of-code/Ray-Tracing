#include "NRooksSampler.h"

NRooks::NRooks(int numSamples, int numSets) :
	Sampler(numSamples, numSets) 
{}

NRooks::~NRooks() {}

void NRooks::GenerateSamples() {
    int totalPoints = mNumSamples * mNumSets;
    mSamplePool.clear();

    // Step 1: Pre-allocate the entire vector with default points
    // This allows us to use direct array indexing safely during shuffles
    mSamplePool.resize(totalPoints, SamplerPoint2D(0.0f, 0.0f));

    float cellWidth = 1.0f / mNumSamples;

    // Loop over every independent set
    for (int set = 0; set < mNumSets; ++set) {
        int setOffset = set * mNumSamples;

        // PHASE 1 & 2: Set up points on the main diagonal + Add 2D Jitter
        for (int i = 0; i < mNumSamples; ++i) {
            int targetIndex = setOffset + i;

            // Placing points on the diagonal: cell 'i' for X and cell 'i' for Y
            float x = (i + Helper::rand_float()) * cellWidth;
            float y = (i + Helper::rand_float()) * cellWidth;

            mSamplePool[targetIndex] = SamplerPoint2D(x, y);
        }

        // PHASE 3: Global Y-Shuffle (Shatters the diagonal correlation)
        for (int i = 0; i < mNumSamples; ++i) {
            // Pick a random target index 'k' from 'i' to the end of this set
            int k = Helper::rand_int(i, mNumSamples - 1);

            int idx1 = setOffset + i;
            int idx2 = setOffset + k;

            // Swap ONLY the Y coordinates. 
            // X coordinates stay fixed in their unique columns.
            std::swap(mSamplePool[idx1].y, mSamplePool[idx2].y);
        }
    }
}