#pragma once

#include "../../Math/MathInclude.h"
#include "../IGeometricObject.h"

class Sphere : public IGeometricObject {
public:
	Sphere();
	Sphere(Point _p, float _r, RGBColor _c);
	~Sphere();

	bool HitTest(const Ray& ray, float& t, const float& tMin) override;

private:
	Point mCenter;
	float mRadius;
};