#pragma once

#include "../Ray/Ray.h"
#include "../Math/RGB Color/RGBColor.h"

enum class GeometryType {
	Plane,
	Square,
	Sphere,
};

class IGeometricObject {
public:
	virtual ~IGeometricObject() = default;
	virtual bool HitTest(const Ray& ray, double& t, const float& tMin) = 0;

	const RGBColor& GetColor() const { return mColor; }

protected:
	RGBColor mColor;
	IGeometricObject(const RGBColor& _c);
};