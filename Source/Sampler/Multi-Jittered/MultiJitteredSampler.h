#pragma once

#include "../Sampler.h"

class MultiJitteredSampler : public Sampler {
public:
	MultiJitteredSampler(int numSamples, int numSets = 100);
	~MultiJitteredSampler();

protected:
	void GenerateSamples() override;

};