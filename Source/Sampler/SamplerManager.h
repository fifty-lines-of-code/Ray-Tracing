#pragma once

#include "Multi-Jittered/MultiJitteredSampler.h"

class SamplerManager {
public:
	SamplerManager(int numSamples, int numSets = 100);
	~SamplerManager();

	SamplerManager(const SamplerManager&) = delete;
	SamplerManager& operator=(const SamplerManager&) = delete;

	const ISampler& GetPixelSampler() const noexcept;

private:
	MultiJitteredSampler* mMultiJitteredSampler = nullptr;
};