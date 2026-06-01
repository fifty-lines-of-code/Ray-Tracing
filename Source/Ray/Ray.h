#pragma once

#include "../Math/MathInclude.h"

class Ray {
public:
	Ray(Point origin, Vector dir);
	~Ray();

	const Point& GetOrigin() const;
	const Vector& GetDirection() const;

private:
	Vector mDirection;
	Point mOrigin;
};