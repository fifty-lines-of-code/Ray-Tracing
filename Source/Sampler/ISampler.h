#pragma once

#include "../Helper/Helper.h"
#include <vector>

struct SamplerPoint2D {
    double x, y;
    SamplerPoint2D() : x(0.f), y(0.f) {}
    SamplerPoint2D(double a) : SamplerPoint2D(a, a) {}
    SamplerPoint2D(double x, double y) : x(x), y(y) {}
};

class ISampler {

public:
    ISampler(int numSamples, int numSets);
    virtual ~ISampler();

    int GetNumberOfSamples() const noexcept;
    // Securely grab a pre-baked sample offset from the pool
    SamplerPoint2D GetSample(int pixelIndex, int sampleNum) const;
    SamplerPoint2D GetSample_Disk(int pixelIndex, int sampleNum) const;

protected:
    std::vector<SamplerPoint2D> mSamplePool;
    std::vector<SamplerPoint2D> mDiskSamplePool;
    int mNumSamples;     // e.g., 25
    int mNumSets;        // Number of pixel configurations to pre-bake

protected:
    virtual void GenerateSamples() = 0;
    void MapSamplesToUnitDisk();
};