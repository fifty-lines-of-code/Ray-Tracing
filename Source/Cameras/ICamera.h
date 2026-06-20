#pragma once

#include "../Math/MathInclude.h"

class ICamera {
public:
	ICamera(
		Point eye = Point(0.f, 0.f, 1.f),
		Point lookat = Point(0.f, 0.f, -1.f)
	);
	virtual ~ICamera() = default;

	void ComputeUV();

protected:
	Point mEye;
	Point mLookAt;
	Vector mUp;
	Vector u, v, w;
	float mExposureTime;

private:

};