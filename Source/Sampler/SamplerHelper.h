#pragma once

#include <chrono>
#include "Sampler.h"
#include <vector>

class SamplerHelper {
public:
	static void RandomizeSamples(std::vector<SamplerPoint2D>& samplePool, int noSamples, int noSets) {
        // randomize the samples
        unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
        std::mt19937 g(seed);

        // Shuffle each set's points individually so they lose their grid birth-order
        for (int set = 0; set < noSets; ++set) {
            auto start = samplePool.begin() + (set * noSamples);
            auto end = start + noSamples;
            std::shuffle(start, end, g);
        }
	}
};