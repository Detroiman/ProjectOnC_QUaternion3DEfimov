#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>
#ifndef POINT3D.h
#define POINT3D.h
 /* Задання структури Point3d */

typedef struct Point3D{
    int cord_x;
    int cord_y;
    int cord_z;
    double radius;
    double ugol_fi;
    double ugol_teta;
    double ro;
    double ugol_fi_cil;
    int norm_vector[3];
} point;

/* Виведення структури Point3d для coord_x, coord_y, coord_z у ПДСК */

void output_point3d_in_pdsk(point* p);

/* Введення структури Point3d для coord_x, coord_y, coord_z у ПДСК */

void input_point3d_in_pdsk(point* p, int xc, int yc, int zc);

/*Перевод координат із ПДСК у сферичну систему координат*/

void from_pdsk_in_sphere(point* p);

/*Перевод координат із ПДСК у циліндричну систему координат*/

void from_pdsk_in_cilindr(point* p);

/*Множення точки на число*/

void mnozh_tochk(point* p, int sklr);

/*Функція зсуву точки на деяку координату (x,y,z)*/

void zsyv_tochok_pdsk(point* p, int cx, int cy, int cz);

#endif // POINT3D
