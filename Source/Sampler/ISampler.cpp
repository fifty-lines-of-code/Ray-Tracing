#include "ISampler.h"

#include "../Helper/Constants.h"

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

SamplerPoint2D ISampler::GetSample_Disk(int pixelIndex, int sampleNum) const {
    // Kevin's trick: Shuffle sets randomly using a modulo jump so adjacent pixels look unique
    int setID = (pixelIndex * 103) % mNumSets;
    int globalIndex = (setID * mNumSamples) + sampleNum;
    return mDiskSamplePool[globalIndex];
}

void ISampler::MapSamplesToUnitDisk() {
    size_t size = mSamplePool.size();
    double r, phi; // polar coordinates
    SamplerPoint2D sp; // sample point on unit disk

    mDiskSamplePool.reserve(size);

    for (int j = 0; j < size; ++j) {
        // map sample point to [-1, 1]

        sp.x = 2.f * mSamplePool[j].x - 1.f;
        sp.y = 2.f * mSamplePool[j].y - 1.f;

        if (sp.x > -sp.y) { // sectors 1 and 2
            if (sp.x > sp.y) { // sector 1
                r = sp.x;
                phi = sp.y / sp.x;
            }
            else { // sector 2
                r = sp.y;
                phi = 2 - sp.x / sp.y;
            }
        }
        else { // sectors 3 and 4
            if (sp.x < sp.y) { // sector 3
                r = -sp.x;
                phi = 4.f + sp.y / sp.x;
            }
            else { // sector 4
                r = -sp.y;
                phi = 6 - sp.x / sp.y;
            }
        }

        phi *= Constants::PI_DIV_4;

        double diskX = r * std::cos(phi);
        double diskY = r * std::sin(phi);
        mDiskSamplePool.push_back(SamplerPoint2D(diskX, diskY));
    }
}