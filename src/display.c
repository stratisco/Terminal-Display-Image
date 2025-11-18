#include "display.h"


DisplayMethod displayMethod = UPPER_HALF_SLAB;


// prints a 2d array of rgb values.
// in the following format:
//    r1, g1, b1, r2, g2, b2...
void display(uint8_t* data, int width, int height, int scale, int channels) {
    for (int y = 0; y < height ;y += scale) {
        for (int x = 0; x < width; x += scale) {
            
            uint8_t* data_ptr = data + (y * width + x) * channels;

            if (displayMethod == UPPER_HALF_SLAB) {
                color(*data_ptr, *(data_ptr+1), *(data_ptr+2), FOREGROUND);

                data_ptr = data + ((y+1) * width + x) * channels;
                color(*data_ptr, *(data_ptr+1), *(data_ptr+2), BACKGROUND);

                printf("▀");
            } else if (displayMethod == LOWER_HALF_SLAB) {
                color(*data_ptr, *(data_ptr+1), *(data_ptr+2), BACKGROUND);

                data_ptr = data + ((y+1) * width + x) * channels;
                color(*data_ptr, *(data_ptr+1), *(data_ptr+2), FOREGROUND);
                
                printf("▄");
            } else {
                color(*data_ptr, *(data_ptr+1), *(data_ptr+2), BACKGROUND);

                printf("  ");
            }

        }
        color_reset();
        printf("\n");

        if (displayMethod == UPPER_HALF_SLAB || displayMethod == LOWER_HALF_SLAB) {
            y += scale;
        }
    }
}