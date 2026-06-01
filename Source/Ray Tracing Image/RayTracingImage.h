#pragma once

#include <windows.h>

class RayTracingImage {
public:
	RayTracingImage();
	~RayTracingImage();

	bool saveColorArrayToImage(
		const unsigned char* colorArray,
		int width,
		int height,
		const WCHAR* filename
	);

private:
	int getEncoderClsid(const WCHAR* format, CLSID* pClsid);
};