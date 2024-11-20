#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value:
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Each pixel in a colored image (RGB) takes 24 bits (3 bytes)
    const int bits_per_pixel = 24;

    // Calculate the size of the image in bits
    long long size_in_bits = (long long)w * h * bits_per_pixel;

    // Convert the size based on the specified unit
    if (strcmp(unit, "bt") == 0) {
        // Return the size in bits
        return (float)size_in_bits;
    } 
    else if (strcmp(unit, "ko") == 0) {
        // Return the size in kilobits (1 kilobit = 1000 bits)
        return (float)size_in_bits / 1000;
    } 
    else if (strcmp(unit, "mo") == 0) {
        // Return the size in megabits (1 megabit = 1000000 bits)
        return (float)size_in_bits / 1000000;
    } 
    else if (strcmp(unit, "go") == 0) {
        // Return the size in gigabits (1 gigabit = 1000000000 bits)
        return (float)size_in_bits / 1000000000;
    } 
    else {
        // If the unit is not recognized, return 0
        return 0;
    }
}
