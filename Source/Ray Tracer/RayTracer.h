#pragma once

#include "../Math/MathInclude.h"
#include "../Sampler/SamplerManager.h"
#include "../Scene/Scene.h"

class RayTracer {
public:
	RayTracer();
	~RayTracer();

	void RayTrace(int width, int height, const SamplerManager& samplerManager, Scene& scene);

private:
	unsigned char* mColorArray = nullptr;

private:
	void ResetColorArray();
	void SetupColorArray(int width, int height);
	void CalculateRayOrigin(double x, double y, int width, int height, Point& o);
};