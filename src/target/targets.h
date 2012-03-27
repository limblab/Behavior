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

/* target display macros */
/* #define DrawCircleTarget(output, centerX, centerY, radius, color) \ */

void drawRectTarget(float *output, int index, float *location, int type) {
	output[0 + index*5*sizeof(float)] = type;
	output[1 + index*5*sizeof(float)] = location[0];
	output[2 + index*5*sizeof(float)] = location[1];
	output[3 + index*5*sizeof(float)] = location[2];
	output[4 + index*5*sizeof(float)] = location[3];
}

#endif /* TARGETS_H */
