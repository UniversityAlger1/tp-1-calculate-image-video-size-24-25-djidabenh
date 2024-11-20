#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   fps: Frames per second (fps)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value:
//   colored video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Constants for the number of bits per pixel
    const int color_bits_per_pixel = 24;  // 3 bytes (RGB)
    const int gray_bits_per_pixel = 8;    // 1 byte (Grayscale)

    // Calculate the total size in bits for the color section (movie part)
    long long color_size_in_bits = (long long)w * h * color_bits_per_pixel * fps * durationMovie;

    // Calculate the total size in bits for the grayscale section (credits part)
    long long gray_size_in_bits = (long long)w * h * gray_bits_per_pixel * fps * durationCredits;

    // Total size of the video in bits
    long long total_size_in_bits = color_size_in_bits + gray_size_in_bits;

    // Convert the size based on the specified unit
    if (strcmp(unit, "bt") == 0) {
        // Return size in bytes (8 bits = 1 byte, so we divide by 8)
        return (float)(total_size_in_bits / 8);
    } 
    else if (strcmp(unit, "ko") == 0) {
        // Return size in kilobits (1 kilobit = 1000 bits)
        return (float)(total_size_in_bits / 1000);
    } 
    else if (strcmp(unit, "mo") == 0) {
        // Return size in megabits (1 megabit = 1000000 bits)
        return (float)(total_size_in_bits / 1000000);
    } 
    else if (strcmp(unit, "go") == 0) {
        // Return size in gigabits (1 gigabit = 1000000000 bits)
        return (float)(total_size_in_bits / 1000000000);
    } 
    else {
        // If the unit is not recognized, return 0
        return 0;
    }
}
