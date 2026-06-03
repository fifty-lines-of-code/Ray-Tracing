#pragma once

#include "../Helper/Helper.h"
#include <vector>

struct SamplerPoint2D {
    float x, y;
    SamplerPoint2D() : x(0.f), y(0.f) {}
    SamplerPoint2D(float x, float y) : x(x), y(y) {}
};

class Sampler {
private:
    std::vector<SamplerPoint2D> mSamplePool;
    int mNumSamples;     // e.g., 25
    int mNumSets;        // Number of pixel configurations to pre-bake

public:
    Sampler(int numSamples);
    ~Sampler();

    // Securely grab a pre-baked sample offset from the pool
    SamplerPoint2D GetSample(int pixelIndex, int sampleNum) const;

private:
    void GenerateSamples();
};