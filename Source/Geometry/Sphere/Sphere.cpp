#include "Sphere.h"

Sphere::Sphere() : Sphere(Point(0, 0, 0), 10.f, RGBColor(1.f, 0.f, 0.f)) {}

Sphere::Sphere(Point _p, float _r, RGBColor _c) :
	IGeometricObject(_c),
	mCenter(_p),
	mRadius(_r)
{}

Sphere::~Sphere() {}

bool Sphere::HitTest(const Ray& ray, float& t, const float& tMin) {
	bool result = false;

	// todo

	return result;
}