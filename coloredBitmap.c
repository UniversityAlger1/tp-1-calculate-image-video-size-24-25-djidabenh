#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
long long sizeInBits = (long long)w * h * 3 * 8; // 3 bytes per pixel, converted to bits

   if (strcmp(unit, "bt") == 0) {
       return (float)sizeInBits; // Size in bits
   } else if (strcmp(unit, "ko") == 0) {
       return sizeInBits / 1024.0; // Size in kilobits
   } else if (strcmp(unit, "mo") == 0) {
       return sizeInBits / (1024.0 * 1024); // Size in megabits
   } else if (strcmp(unit, "go") == 0) {
       return sizeInBits / (1024.0 * 1024 * 1024); // Size in gigabits
   }
   // YOUR CODE HERE - END
   return 0;
}