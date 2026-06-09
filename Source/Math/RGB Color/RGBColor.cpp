#include "RGBColor.h"

RGBColor::RGBColor(float _a) : RGBColor(_a, _a, _a) {}

RGBColor::RGBColor(float _r, float _g, float _b) :
	r(_r), g(_g), b(_b)
{}

RGBColor::RGBColor(const RGBColor& c) :
	r(c.r), g(c.g), b(c.b)
{}

RGBColor& RGBColor::operator=(const RGBColor& rhs) {
    // 1. Check for self-assignment
    if (this == &rhs) {
        return *this;
    }

    // 2. Copy the data across
    r = rhs.r;
    g = rhs.g;
    b = rhs.b;

    // 3. Return a reference to the current object
    return *this;
}

RGBColor& RGBColor::operator+=(const RGBColor& rhs) {
    r += rhs.r;
    g += rhs.g;
    b += rhs.b;

    return *this;
}

RGBColor& RGBColor::operator/=(float scalar) {
    if (scalar > 0) {
        float invScalar = 1 / scalar;
        r *= invScalar;
        g *= invScalar;
        b *= invScalar;
    }

    return *this;
}

RGBColor::~RGBColor() {}