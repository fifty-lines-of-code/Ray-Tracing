#pragma once

#include "../IGeometricObject.h"
#include "../../Math/MathInclude.h"

class Plane : public IGeometricObject {
public:
	Plane(const Point& _p, const Vector& _n, const RGBColor& _c);
	~Plane();

	bool HitTest(const Ray& _r, double& _t, const float& _tMin) override;

protected:
	Point mCenter;
	Vector mNormal;
};