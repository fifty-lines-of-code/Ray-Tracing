#pragma once

#include "../Sampler.h"

class JitteredSampler : public Sampler {
public:
	JitteredSampler(int numSamples, int numSets = 100);
	~JitteredSampler();

protected:
	void GenerateSamples() override;
};