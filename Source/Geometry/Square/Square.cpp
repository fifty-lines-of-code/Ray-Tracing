#include "Square.h"

#include <cmath>

Square::Square(const Point& _p, const Vector& _n, const RGBColor& _c, float _halfSize) :
	Plane(_p, _n, _c),
	mHalfSize(_halfSize)
{}

Square::~Square() {}

bool Square::HitTest(const Ray& _r, double& _t, const float& _tMin) {
	double incoming_T = _t;

	bool result = Plane::HitTest(_r, incoming_T, _tMin);

	if (result) {
		Point hitPoint = _r.GetOrigin() + _r.GetDirection() * incoming_T;
		if (std::abs(hitPoint.x - mCenter.x) <= mHalfSize &&
			std::abs(hitPoint.y - mCenter.y) <= mHalfSize) {
			result = true;
			_t = incoming_T;
		}
		else {
			result = false;
		}
	}

	return result;
}