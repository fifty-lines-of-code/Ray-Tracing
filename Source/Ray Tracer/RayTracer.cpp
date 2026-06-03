#include "RayTracer.h"

#include <cmath>
#include "../Ray/Ray.h"
#include "../Ray Tracing Image/RayTracingImage.h"
#include <limits>

RayTracer::RayTracer() {}

RayTracer::~RayTracer() {}

void RayTracer::RayTrace(int width, int height, int noSamples, Scene& scene) {
	ResetColorArray();
	SetupColorArray(width, height);

	float tMin = 0.001;
	Point origin;
	Vector direction = Vector(0, 0, -1).Normalize();
	int n = (int)std::sqrt(noSamples);

	// generate ray origins
	for (int y = 0; y < height; ++y) { // vertical
		for (int x = 0; x < width; ++x) { // horizontal

			RGBColor accumulatedColor(0.f);

			for (int p = 0; p < n; ++p) { // subpixel row
				for (int q = 0; q < n; ++q) { // subpixel col
					// reset color
					RGBColor sampleColor(0.f);
					// reset t
					float t = FLT_MAX;

					// calculte ray origin
					float subPixelX = x + (0.5f + q) / n;
					float subPixelY = y + (0.5f + p) / n;
					CalculateRayOrigin(subPixelX, subPixelY, width, height, origin);
					Ray ray = Ray(origin, direction);

					// run raytrace for the scene
					scene.RayTrace(ray, t, tMin, sampleColor);

					accumulatedColor += sampleColor;
				}
			}

			accumulatedColor /= (float)noSamples;

			// store the color for this ray
			int index = (y * width + x) * 4;
			mColorArray[index] = (unsigned char)(accumulatedColor.r * 255);
			mColorArray[index + 1] = (unsigned char)(accumulatedColor.g * 255);
			mColorArray[index + 2] = (unsigned char)(accumulatedColor.b * 255);
			mColorArray[index + 3] = 255; // Alpha
		}
	}

	RayTracingImage image;
	image.saveColorArrayToImage(
		mColorArray,
		width,
		height,
		L"ray_traced.png"
	);
}

void RayTracer::ResetColorArray() {
	if (mColorArray != nullptr) {
		delete[] mColorArray;
	}

	mColorArray = nullptr;
}

void RayTracer::SetupColorArray(int width, int height) {
	// 4 because for each pixel we have to store rgba
	mColorArray = new unsigned char[4 * width * height];
}

void RayTracer::CalculateRayOrigin(float x, float y, int width, int height, Point& o) {
	o.x = x - 0.5 * (width - 1);
	o.y = 0.5 * (height - 1) - y; // gotta flip the y to ensure image is not rendered upside down
	o.z = 100.f; // always hard coded
}