#pragma once

#include "../Math/MathInclude.h"
#include "../Geometry/Plane/Plane.h"
#include "../Geometry/Sphere/Sphere.h"
#include "../Geometry/Square/Square.h"

class SceneGeometryFactory {
public:
	static Plane* GeneratePlane(Point _p, Vector _n, RGBColor _c) {
		return new Plane(_p, _n, _c);
	}

	static Square* GenerateSquare(Point _p, Vector _n, RGBColor _c, float _hs) {
		return new Square(_p, _n, _c, _hs);
	}

	static Sphere* GenerateSphere(Point _p, Vector _n, RGBColor _c, float _hs) {
		// todo
		return new Sphere();
	}
};