#pragma once

#include "../Plane/Plane.h"
#include "../../Math/MathInclude.h"

class Square : public Plane {
public:
	Square(const Point& _p, const Vector& _n, const RGBColor& _c, float _halfSize);
	~Square();

	bool HitTest(const Ray& _r, double& _t, const float& _tMin) override;

private:
	float mHalfSize;
};