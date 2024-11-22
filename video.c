#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
       long long colorFrameSizeBits = (long long)w * h * 3 * 8; // Colored frame size in bits
   long long grayscaleFrameSizeBits = (long long)w * h * 8; // Grayscale frame size in bits

   long long totalBits = (long long)fps * durationMovie * colorFrameSizeBits + 
                         (long long)fps * durationCredits * grayscaleFrameSizeBits;

   if (strcmp(unit, "bt") == 0) {
       return (float)totalBits; // Return size in bits
   } else if (strcmp(unit, "ko") == 0) {
       return totalBits / 1024.0; // Return size in kilobits
   } else if (strcmp(unit, "mo") == 0) {
       return totalBits / (1024.0 * 1024); // Return size in megabits
   } else if (strcmp(unit, "go") == 0) {
       return totalBits / (1024.0 * 1024 * 1024); // Return size in gigabits
   }

   // YOUR CODE HERE - END
   return 0;
}