#pragma once

#include "../ISampler.h"

class MultiJitteredSampler : public ISampler {
public:
	MultiJitteredSampler(int numSamples, int numSets = 100);
	~MultiJitteredSampler();

protected:
	void GenerateSamples() override;

};