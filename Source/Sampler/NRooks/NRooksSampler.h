#pragma once

#include "../Sampler.h"

class NRooks : public Sampler {
public:
	NRooks(int numSamples, int numSets = 100);
	~NRooks();

protected:
	void GenerateSamples() override;
};