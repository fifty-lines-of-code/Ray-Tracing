#pragma once

#include "../Point/Point.h"

struct Vector {
public:
	double x, y, z;

	Vector();
	Vector(double _a);
	Vector(double _x, double _y, double _z);
	~Vector();

	double Dot(const Vector& _v) const;
	Vector Normalize() const;
	Vector operator*(float _s) const;

	float GetLengthSq() const;

private:
	float mLength;
	float mLengthSq;

private:
	void CalculateLength();
};