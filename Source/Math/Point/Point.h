#pragma once

struct Vector;

struct Point {
	double x;
	double y;
	double z;

	Point();
	Point(double _a);
	Point(double _x, double _y, double _z);
	Point(const Point& _p);
	~Point();

	Vector operator-(const Point& _p) const;
	Point operator+(const Vector& v) const;
};