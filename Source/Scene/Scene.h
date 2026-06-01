#pragma once

#include "SceneGeometryFactory.h"
#include <vector>

class Scene {
public:
	Scene();
	~Scene();

	void AddGeometry(IGeometricObject* _geometry);
	void RayTrace(const Ray& ray, float& t, const float& tMin, RGBColor& c);

private:
	std::vector<IGeometricObject*> mGeometries;
};