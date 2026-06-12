#include "SamplerManager.h"

#include <cassert>

SamplerManager::SamplerManager(int numSamples, int numSets) {
	mMultiJitteredSampler = new MultiJitteredSampler(numSamples, numSets);
}

SamplerManager::~SamplerManager() {
	// release multi-jittered sampler.
	if (mMultiJitteredSampler != nullptr) {
		// in the real world use a unique_ptr
		// but leaving this in cause it's fun to new and delete
		delete mMultiJitteredSampler;
	}
}

const ISampler& SamplerManager::GetPixelSampler() const noexcept {
	assert(mMultiJitteredSampler != nullptr && "Multi Jittered Sampler should not be null");
	return *mMultiJitteredSampler;
}