#include "config/grayScaleImage.h"

// Parameters:
//   w: width of the image
//   h: height of the image
// Return value:
//   grayScale size of the image Bitmap (in bytes)
float grayScaleImage(int w, int h) {
    // Each pixel in grayscale takes 1 byte (8 bits)
    const int bytes_per_pixel = 1;

    // Calculate the image size in bytes
    long long size_in_bytes = (long long)w * h * bytes_per_pixel;

    // Return the size in bytes
    return (float)size_in_bytes;
}
