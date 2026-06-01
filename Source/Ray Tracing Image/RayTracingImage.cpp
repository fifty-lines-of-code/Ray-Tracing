#include "RayTracingImage.h"

#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

using namespace Gdiplus;

RayTracingImage::RayTracingImage() {}

RayTracingImage::~RayTracingImage() {}

bool RayTracingImage::saveColorArrayToImage(
    const unsigned char* colorArray,
    int width,
    int height,
    const WCHAR* filename
) {
    // Initialize GDI+
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    bool success = true;
    // this additional scope is required to ensure Bitmap gets dealloc'd before Gdiplus
    {
        // Create a bitmap
        Bitmap bitmap(width, height, PixelFormat32bppARGB);

        // Lock bitmap data
        BitmapData bitmapData;
        Rect rect(0, 0, width, height);
        bitmap.LockBits(&rect, ImageLockModeWrite, PixelFormat32bppARGB, &bitmapData);

        // Copy color array to bitmap data
        unsigned char* bitmapPixels = static_cast<unsigned char*>(bitmapData.Scan0);
        int stride = bitmapData.Stride;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int index = (y * width + x) * 4; // Assuming 4 bytes per pixel (RGBA)
                int bitmapIndex = y * stride + x * 4;

                bitmapPixels[bitmapIndex] = colorArray[index + 2];     // B
                bitmapPixels[bitmapIndex + 1] = colorArray[index + 1]; // G
                bitmapPixels[bitmapIndex + 2] = colorArray[index];     // R
                bitmapPixels[bitmapIndex + 3] = colorArray[index + 3]; // A
            }
        }

        // Unlock bitmap data
        bitmap.UnlockBits(&bitmapData);

        // Save the bitmap to a file
        CLSID pngClsid;
        // Get the CLSID for PNG encoder
        if (getEncoderClsid(L"image/png", &pngClsid) < 0) {
            GdiplusShutdown(gdiplusToken);
            return false;
        }

        Gdiplus::Status result = bitmap.Save(filename, &pngClsid, NULL);

        if (result != Gdiplus::Ok) {
            success = false;
        }
    }

    // Shutdown GDI+
    GdiplusShutdown(gdiplusToken);
    return success;
}

int RayTracingImage::getEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
    UINT numEncoders;
    UINT size;

    ImageCodecInfo* imageCodecInfo = NULL;

    GetImageEncodersSize(&numEncoders, &size);
    if (size == 0)
        return -1;

    imageCodecInfo = (ImageCodecInfo*)(malloc(size));
    if (imageCodecInfo == NULL)
        return -1;

    GetImageEncoders(numEncoders, size, imageCodecInfo);

    for (UINT j = 0; j < numEncoders; ++j)
    {
        if (wcscmp(imageCodecInfo[j].MimeType, format) == 0)
        {
            *pClsid = imageCodecInfo[j].Clsid;
            free(imageCodecInfo);
            return j;
        }
    }

    free(imageCodecInfo);
    return -1;
}  