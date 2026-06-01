#include "Point.h"

#include "../Vector/Vector.h"

Point::Point() : Point(0) {}

Point::Point(double _a) : x(_a), y(_a), z(_a) {}

Point::Point(double _x, double _y, double _z) :
	x(_x), y(_y), z(_z)
{}

Point::Point(const Point& _p) :
	x(_p.x), y(_p.y), z(_p.z)
{}

Point::~Point() {}

Vector Point::operator-(const Point& _p) const {;
	return Vector(x - _p.x, y - _p.y, z - _p.z);
}

Point Point::operator+(const Vector& _v) const {
	return Point(x + _v.x, y + _v.y, z + _v.z);
}