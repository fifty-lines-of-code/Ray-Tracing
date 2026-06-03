#pragma once

struct RGBColor {
	float r, g, b;

	RGBColor(float _a);
	RGBColor(float _r, float _g, float _b);
	RGBColor(const RGBColor& c);
	RGBColor& operator=(const RGBColor& rhs);
	RGBColor& operator+=(const RGBColor& rhs);
	RGBColor& operator/=(float scalar);

	~RGBColor();
};