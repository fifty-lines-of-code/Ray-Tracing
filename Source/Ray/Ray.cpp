#include "Ray.h"

Ray::Ray(Point origin, Vector direction) : 
	mOrigin(origin),
	mDirection(direction)
{}

Ray::~Ray() {}

const Point& Ray::GetOrigin() const { return mOrigin; }

const Vector& Ray::GetDirection() const { return mDirection; }