#include "Vector.h"

#include <cmath>

Vector::Vector() : Vector(0.f, 0.f, 0.f) {}

Vector::Vector(double _a) : Vector(_a, _a, _a) {}

Vector::Vector(double _x, double _y, double _z) :
	x(_x), 
	y(_y), 
	z(_z)
{
	CalculateLength();
}

Vector::~Vector() {}

Vector Vector::Normalize() const {
	if (mLength > 0) {
		return Vector(x / mLength, y / mLength, z / mLength);
	}

	return Vector(0.f);
}

Vector Vector::operator*(float _s) const {
	return Vector(x * _s, y * _s, z * _s);
}

float Vector::GetLengthSq() const {
	return mLengthSq;
}

double Vector::Dot(const Vector& _v) const {
	return x * _v.x + y * _v.y + z * _v.z;
}

void Vector::CalculateLength() {
	mLengthSq = x * x + y * y + z * z;
	mLength = sqrt(mLengthSq);
}