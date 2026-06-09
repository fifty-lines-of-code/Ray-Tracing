#include "RayTracer.h"

#include <cmath>
#include "../Helper/Helper.h"
#include "../Ray/Ray.h"
#include "../Ray Tracing Image/RayTracingImage.h"
#include <limits>

RayTracer::RayTracer() {}

RayTracer::~RayTracer() {}

void RayTracer::RayTrace(int width, int height, Sampler& sampler, Scene& scene) {
	ResetColorArray();
	SetupColorArray(width, height);

	float tMin = 0.001f;
	Point origin;
	Vector direction = Vector(0, 0, -1).Normalize();
	int noSamples = sampler.GetNumberOfSamples();

	// generate ray origins
	for (int y = 0; y < height; ++y) { // vertical
		for (int x = 0; x < width; ++x) { // horizontal

			RGBColor accumulatedColor(0.f);
			int pixelIndex = y * width + x;

			// fire a ray per sample
			for (int i = 0; i < noSamples; ++i) {
				// reset color
				RGBColor sampleColor(0.f);
				// reset t
				float t = FLT_MAX;

				// calculate subpixel x, y
				SamplerPoint2D offset = sampler.GetSample(pixelIndex, i);

				float subPixelX = x + offset.x;
				float subPixelY = y + offset.y;

				// calculte ray origin
				CalculateRayOrigin(subPixelX, subPixelY, width, height, origin);
				Ray ray = Ray(origin, direction);

				// run raytrace for the scene
				scene.RayTrace(ray, t, tMin, sampleColor);

				accumulatedColor += sampleColor;
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