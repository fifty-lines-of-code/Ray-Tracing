#include "Sphere.h"

#include <algorithm>
#include <cmath>

Sphere::Sphere() : Sphere(Point(0, 0, 0), RGBColor(0.f, 1.f, 1.f), 10.f) {}

Sphere::Sphere(Point _p, RGBColor _c, float _r) :
	IGeometricObject(_c),
	mCenter(_p),
	mRadius(_r)
{}

Sphere::~Sphere() {}

bool Sphere::HitTest(const Ray& _r, double& _t, const float& _tMin) {

	// geometric solution
	Vector centerMinusOrigin = mCenter - _r.GetOrigin();
	double tCa = centerMinusOrigin.Dot(_r.GetDirection());
	if (tCa < 0) { return false; }

	double d2 = centerMinusOrigin.Dot(centerMinusOrigin) - tCa * tCa;
	if (d2 < 0 || d2 > (mRadius * mRadius)) { return false; }

	double tHc = std::sqrt(mRadius * mRadius - d2);
	double t0 = tCa - tHc;
	double t1 = tCa + tHc;

	if (t0 > t1) { std::swap(t0, t1); }

	if (t0 < _tMin) {
		t0 = t1;
	}

	if (t0 > _tMin && t0 < _t) {
		_t = t0;
		return true;
	}


	return false;
}