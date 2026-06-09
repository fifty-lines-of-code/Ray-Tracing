#pragma once

#include "../ISampler.h"

class JitteredSampler : public ISampler {
public:
	JitteredSampler(int numSamples, int numSets = 100);
	~JitteredSampler();

protected:
	void GenerateSamples() override;
};