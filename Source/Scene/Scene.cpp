#include "Scene.h"

Scene::Scene() {}

Scene::~Scene() {
	for (int i = 0; i < mGeometries.size(); ++i) {
		delete mGeometries[i];
		mGeometries[i] = nullptr;
	}
 }

void Scene::AddGeometry(IGeometricObject* _geometry) {
	mGeometries.push_back(_geometry);
}

void Scene::RayTrace(const Ray& ray, float& t, const float& tMin, RGBColor& c) {
	RGBColor color = c;

	for (auto* geometry : mGeometries) {
		bool result = geometry->HitTest(ray, t, tMin);
		// todo
		if (result) {
			color = geometry->GetColor();
		}
	}
	c = color;
}