#include "Plane.h"

Plane::Plane(const Point& _p, const Vector& _n, const RGBColor& _c) :
	IGeometricObject(_c),
	mCenter(_p),
	mNormal(_n)
{
	mNormal.Normalize();
}

Plane::~Plane() {}

bool Plane::HitTest(const Ray& _r, double& _t, const float& _tMin) {
	bool result = false;

	double normalDotDirection = mNormal.Dot(_r.GetDirection());
	if (normalDotDirection != 0.f) {
		Vector rOriginToPCenter = mCenter - _r.GetOrigin();
		double normalDotOriginToCenter = mNormal.Dot(rOriginToPCenter);

		double thisT = normalDotOriginToCenter / normalDotDirection;

		if (thisT > _tMin && thisT < _t) {
			result = true;
			_t = thisT;
		}
	}

	return result;
}