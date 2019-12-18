#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>
#ifndef POINT3D.h
#define POINT3D.h
 /* ������� ��������� Point3d */

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

/* ��������� ��������� Point3d ��� coord_x, coord_y, coord_z � ���� */

void output_point3d_in_pdsk(point* p);

/* �������� ��������� Point3d ��� coord_x, coord_y, coord_z � ���� */

void input_point3d_in_pdsk(point* p, int xc, int yc, int zc);

/*������� ��������� �� ���� � �������� ������� ���������*/

void from_pdsk_in_sphere(point* p);

/*������� ��������� �� ���� � ���������� ������� ���������*/

void from_pdsk_in_cilindr(point* p);

/*�������� ����� �� �����*/

void mnozh_tochk(point* p, int sklr);

/*������� ����� ����� �� ����� ���������� (x,y,z)*/

void zsyv_tochok_pdsk(point* p, int cx, int cy, int cz);

#endif // POINT3D
