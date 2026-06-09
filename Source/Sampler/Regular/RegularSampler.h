#pragma once

#include "../ISampler.h"

class RegularSampler: public ISampler {
public:
	RegularSampler(int numSamples, int numSets = 100);
	~RegularSampler();

	void GenerateSamples() override;

protected:
};