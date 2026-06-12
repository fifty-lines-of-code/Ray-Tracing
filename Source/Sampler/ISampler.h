#pragma once

#include "../Helper/Helper.h"
#include <vector>

struct SamplerPoint2D {
    double x, y;
    SamplerPoint2D() : x(0.f), y(0.f) {}
    SamplerPoint2D(double a) : SamplerPoint2D(a, a) {}
    SamplerPoint2D(double _x, double _y) : x(_x), y(_y) {}
};

struct SamplerPoint3D {
    double x, y, z;
    SamplerPoint3D() : x(0.f), y(0.f), z(0.f) {}
    SamplerPoint3D(double a) : SamplerPoint3D(a, a, a) {}
    SamplerPoint3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

class ISampler {

public:
    ISampler(int numSamples, int numSets);
    virtual ~ISampler();

    int GetNumberOfSamples() const noexcept;
    // Securely grab a pre-baked sample offset from the pool
    SamplerPoint2D GetSample(int pixelIndex, int sampleNum) const;
    SamplerPoint2D GetSample_Disk(int pixelIndex, int sampleNum) const;
    SamplerPoint3D GetSample_Hemisphere(int pixelIndex, int sampleNum) const;

protected:
    std::vector<SamplerPoint2D> mSamplePool;
    std::vector<SamplerPoint2D> mDiskSamplePool;
    std::vector<SamplerPoint3D> mHemisphereSamplePool;
    int mNumSamples;     // e.g., 25
    int mNumSets;        // Number of pixel configurations to pre-bake

protected:
    virtual void GenerateSamples() = 0;
    void MapSamplesToUnitDisk();
    void MapSamplesToHemisphere(const float e);
};