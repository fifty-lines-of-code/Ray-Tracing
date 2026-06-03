#pragma once

#include "../Math/MathInclude.h"
#include "../Scene/Scene.h"

class RayTracer {
public:
	RayTracer();
	~RayTracer();

	void RayTrace(int width, int height,int noSamples, Scene& scene);

private:
	unsigned char* mColorArray = nullptr;

private:
	void ResetColorArray();
	void SetupColorArray(int width, int height);
	void CalculateRayOrigin(float x, float y, int width, int height, Point& o);
	void SubPixelXY_RegularSampling(const int x, const int y, const int p, const int q, const int n, float& subPixelX, float& subPixelY);
	void SubPixelXY_Jittered_Sampling(const int x, const int y, const int p, const int q, const int n, float& subPixelX, float& subPixelY);
};