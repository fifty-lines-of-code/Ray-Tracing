#pragma once

#include "../ISampler.h"

class NRooks : public ISampler {
public:
	NRooks(int numSamples, int numSets = 100);
	~NRooks();

protected:
	void GenerateSamples() override;
};