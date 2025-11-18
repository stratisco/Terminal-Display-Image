#ifndef COLORS_H
#define COLORS_H


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define FOREGROUND 38
#define BACKGROUND 48

void color(uint8_t r, uint8_t g, uint8_t b, int zindex);

void color_reset();

#endif
