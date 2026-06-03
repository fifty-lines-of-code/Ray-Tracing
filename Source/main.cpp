// Ray Tracking - Again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Ray Tracer/RayTracer.h"
#include "Scene/SceneFactory.h"

int main()
{
	Scene s;
	SceneFactory::GenerateSingleSphereAndSingleSquareScene(s);

	int noSamples = 25;

	RayTracer r;
	r.RayTrace(640, 480, noSamples, s);
}
