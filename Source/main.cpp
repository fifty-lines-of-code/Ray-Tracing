// Ray Tracking - Again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Ray Tracer/RayTracer.h"
#include "Sampler/SamplerManager.h"
#include "Scene/SceneFactory.h"

int main()
{
	Scene s;
	SceneFactory::GenerateSingleSphereAndSingleSquareScene(s);

	int noSamples = 25;
	SamplerManager sManager(noSamples);

	RayTracer r;
	r.RayTrace(640, 480, sManager, s);
}
