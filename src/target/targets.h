/*
 * targets.h
 *
 * Contains macros and definitions for target types
 */


#ifndef TARGETS_H
#define TARGETS_H 1

/* target type definitions */
#define RedTargetType 1
#define BlueTargetType 7
#define WhiteTargetType 2
#define GreenTargetType 3
#define PurpleTargetType 9
#define CircleTargetType 10
#define SquareTargetType 11

#define TARGET_RGB(r, g, b) ( (r)*256*256 + (g)*256 + (b) )

/* standard color definitions */
#define COLOR_RED TARGET_RGB(255,0,0)
#define COLOR_BLUE TARGET_RGB(0,0,255)
#define COLOR_GREEN TARGET_RGB(0,255,0)

/* target display macros */
/* #define DrawCircleTarget(output, centerX, centerY, radius, color) \ */

void drawRectTarget(real_T *output, int index, real_T *location, int type) {
	output[0 + index*5] = (real_T)type;
	output[1 + index*5] = location[0];
	output[2 + index*5] = location[1];
	output[3 + index*5] = location[2];
	output[4 + index*5] = location[3];
}

void drawSquareTarget(real_T *output, int index, real_T *location, real_T *target_color) {
	output[0 + index*5] = SquareTargetType;
	output[1 + index*5] = location[0]+abs(location[0]-location[2])/2;
	output[2 + index*5] = location[1]-abs(location[0]-location[2])/2;
	output[3 + index*5] = abs(location[0]-location[2]);
	output[4 + index*5] = target_color;
}

#endif /* TARGETS_H */
