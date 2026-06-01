// Ray Tracking - Again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Ray Tracer/RayTracer.h"
#include "Scene/SceneFactory.h"

int main()
{
	Scene s;
	SceneFactory::GenerateSinglePlaneAndSingleSquareScene(s);

	RayTracer r;
	r.RayTrace(640, 480, s);
}
