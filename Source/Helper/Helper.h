#pragma once

#include <random>

class Helper {
public:
	static inline float rand_float() {
        // static ensures the generator is initialized exactly once for performance
        static std::mt19937 generator(std::random_device{}());
        static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

        return distribution(generator);
    }
};