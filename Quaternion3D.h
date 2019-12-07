#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>
#ifndef QUATERNION3D.h
#define QUATERNION3D.h

/* ������� ��������� Quaternion */

typedef struct Quaternion3D{
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
}quaternion;

/* �������� x1,x2,y1,y2,z1,z2 � �������� Quaternion*/

void input_quatern(quaternion* q, int x1, int y1, int z1, int x2, int y2, int z2);

/* ��������� 2 ������ ��������� Quaternion */

void quater_sum(quaternion* q);

 /* �������� 2 ������ ��������� Quaternion */

void quater_mnozh(quaternion* q);

 /* ³������� 2 ������ ��������� Quaternion */

void quater_vidnimannya(quaternion* q);

#endif // QUATERNION3D
