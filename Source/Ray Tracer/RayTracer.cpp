#include "RayTracer.h"

#include <limits>
#include "../Ray/Ray.h"
#include "../Ray Tracing Image/RayTracingImage.h"

RayTracer::RayTracer() {}

RayTracer::~RayTracer() {}

void RayTracer::RayTrace(int width, int height, Scene& scene) {
	ResetColorArray();
	SetupColorArray(width, height);

	RGBColor c(0.f);
	float tMin = 0.001;
	Point origin;
	Vector direction = Vector(0, 0, -1).Normalize();
	float t = FLT_MAX;

	// generate ray origins
	for (int y = 0; y < height; ++y) { // vertical
		for (int x = 0; x < width; ++x) { // horizontal
			// reset color
			c = RGBColor(0.f);
			// reset t
			t = FLT_MAX;

			// calculte ray origin
			CalculateRayOrigin(x, y, width, height, origin);
			Ray ray = Ray(origin, direction);

			// run raytrace for the scene
			scene.RayTrace(ray, t, tMin, c);

			// store the color for this ray
			int index = (y * width + x) * 4;
			mColorArray[index] = (unsigned char)(c.r * 255);
			mColorArray[index+1] = (unsigned char)(c.g * 255);
			mColorArray[index+2] = (unsigned char)(c.b * 255);
			mColorArray[index+3] = 255; // Alpha

			index += 4;
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

void RayTracer::CalculateRayOrigin(int x, int y, int width, int height, Point& o) {
	o.x = x - 0.5 * (width - 1);
	o.y = 0.5 * (height - 1) - y; // gotta flip the y to ensure image is not rendered upside down
	o.z = 100.f; // always hard coded
}