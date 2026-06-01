#pragma once

#include "Scene.h"
#include "SceneGeometryFactory.h"

class SceneFactory {
public:
	static void GenerateSinglePlaneScene(Scene& scene) {
		Plane* p = SceneGeometryFactory::GeneratePlane(
			Point(0, 0, -10), 
			Vector(0, 0, 1),
			RGBColor(0, 0, 1)
		);
		scene.AddGeometry(p);
	}

	static void GenerateSingleSquareScene(Scene& scene) {
		Square* s = SceneGeometryFactory::GenerateSquare(
			Point(0, 0, -8),
			Vector(0, 0, 1),
			RGBColor(0, 1, 0),
			100
		);
		scene.AddGeometry(s);
	}

	static void GenerateSinglePlaneAndSingleSquareScene(Scene& scene) {
		Plane* p = SceneGeometryFactory::GeneratePlane(
			Point(0, 0, -10),
			Vector(0, 0, 1),
			RGBColor(0, 0, 1)
		);

		Square* s = SceneGeometryFactory::GenerateSquare(
			Point(0, 0, -8),
			Vector(0, 0, 1),
			RGBColor(0, 1, 0),
			100
		);

		// set the order here
		scene.AddGeometry(p);
		scene.AddGeometry(s);
	}

	static void GenerateSingleSphereScene(Scene& scene) {
		Sphere* s = SceneGeometryFactory::GenerateSphere(
			Point(0, 0, -8),
			RGBColor(1, 0, 0),
			100
		);
		scene.AddGeometry(s);
	}

	static void GenerateSingleSphereAndSingleSquareScene(Scene& scene) {
		Sphere* sp = SceneGeometryFactory::GenerateSphere(
			Point(0, 0, -8),
			RGBColor(1, 0, 0),
			100
		);

		Square* sq = SceneGeometryFactory::GenerateSquare(
			Point(0, 0, -10),
			Vector(0, 0, 1),
			RGBColor(0, 1, 0),
			100
		);

		scene.AddGeometry(sp);
		scene.AddGeometry(sq);
	}
};