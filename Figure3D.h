#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>
#include "Point3D.h"
#include "Angle3D.h"
#include "Quaternion3D.h"
#ifndef FIGURE3D.h
#define FIGURE3D.h

/* ������� ��������� Figure3D */

typedef struct Figure3D{
    int num_points;
    int num_edges;
    int **points;
    int **edges;
}figure;

/* �������� ������� ����� � ����� Point3d ��� coord_x, coord_y, coord_z � ���� */

int input_figure3d(figure* f, int num_poin, int num_ed);

/* �������� �����*/

int input_edges();

/* �������� ������� �����*/

int input_tops();


/* �������� ������ ����� � ����� */

int input_array_of_points_edges(figure* f, point* p);

/* �������� ���������� x*/

int proection_on_ploskost_x(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm);

/* �������� ���������� y*/

int proection_on_ploskost_y(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm);

/* �������� ���������� z*/

int proection_on_ploskost_z(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm);

/* ������� ����� */

int proection_of_point(point* p, figure* f);

/* ������ � ���� */

void file_write(point *p, figure *f, quaternion *q, int inf);

/* �������� ���'�� */

int clear_all(figure* f);


#endif // FIGURE3D
