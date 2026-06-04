#pragma once

#include "../Sampler.h"

class RegularSampler: public Sampler {
public:
	RegularSampler(int numSamples, int numSets = 100);
	~RegularSampler();

	void GenerateSamples() override;

protected:
};