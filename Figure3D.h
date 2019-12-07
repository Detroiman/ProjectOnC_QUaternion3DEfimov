#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>
#include "Point3D.h"
#include "Angle3D.h"
#include "Quaternion3D.h"
#ifndef FIGURE3D.h
#define FIGURE3D.h

/* Задання структури Figure3D */

typedef struct Figure3D{
    int num_points;
    int num_edges;
    int **points;
    int **edges;
}figure;

/* Введення кількості точок і ребер Point3d для coord_x, coord_y, coord_z у ПДСК */

int input_figure3d(figure* f, int num_poin, int num_ed);

/* Введення ребра*/

int input_edges();

/* Введення вершини ребра*/

int input_tops();


/* Введення масиву точок і ребер */

int input_array_of_points_edges(figure* f, point* p);

/* Проекція координати x*/

int proection_on_ploskost_x(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm);

/* Проекція координати y*/

int proection_on_ploskost_y(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm);

/* Проекція координати z*/

int proection_on_ploskost_z(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm);

/* Проекця точки */

int proection_of_point(point* p, figure* f);

/* Запись в файл */

void file_write(point *p, figure *f, quaternion *q, int inf);

/* Очищення пам'яті */

int clear_all(figure* f);


#endif // FIGURE3D
