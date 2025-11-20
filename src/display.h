#ifndef DISPLAY_H
#define DISPLAY_H


#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "colors.h"

void display(uint8_t* data, int width, int height, int scale, int channels);

typedef enum DisplayMethod {
    UPPER_HALF_SLAB, // "▀"
    LOWER_HALF_SLAB, // "▄"
    TWO_SPACE_PIXEL // "  "
} DisplayMethod;

extern DisplayMethod displayMethod;


#endif