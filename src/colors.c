#include "colors.h"

void color(uint8_t r, uint8_t g, uint8_t b, int zindex) {
    printf("\033[%d;2;%d;%d;%dm", zindex, r, g, b);
}

void color_reset() {
    printf("\033[0m");
}
