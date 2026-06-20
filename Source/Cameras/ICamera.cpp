#include "ICamera.h"

ICamera::ICamera(Point eye, Point lookat) :
	mEye(eye),
	mLookAt(lookat),
	mUp(Vector(0.f, 1.f, 0.f)),
	mExposureTime(1.f)
{}

void ICamera::ComputeUV() {
	w = mEye - mLookAt;
	w.Normalize();
	u = mUp.Cross(w);
	u.Normalize();
	v = w.Cross(u);
}