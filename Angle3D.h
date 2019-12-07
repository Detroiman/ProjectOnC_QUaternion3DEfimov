#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>
#include "Point3D.h"
#ifndef ANGLE3D.h
#define ANGLE3D.h

/* Задання структури Angle 3D */

typedef struct Angle3D{
    double angle;
}angle_gl;

/* Введення кута повороту*/

void input_angle(angle_gl* a, int angle);

#endif // ANGLE3D
