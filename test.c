#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>
#include "headers/Angle3D.h"
#include "headers/Figure3D.h"
#include "headers/Point3D.h"
#include "headers/Quaternion3D.h"

/* Задання структури Quaternion */

typedef struct Quaternion{
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
};

/* Введення x1,x2,y1,y2,z1,z2 в структурі Quaternion*/

void input_quatern(quaternion* q, int x1, int y1, int z1, int x2, int y2, int z2){
    q->x1 = x1;
    q->y1 = y1;
    q->z1 = z1;
    q->x2 = x2;
    q->y2 = y2;
    q->z2 = z2;
}

/* Додавання 2 веторів структури Quaternion */

void quater_sum(quaternion* q){
 double corx,cory,corz;
 corx = q->y1 * q->z2 - q->z1 * q->y2;
 cory = q->x1 * q->z2 - q->z1 * q->x2;
 corz = q->x1 * q->y2 - q->y1 * q->x2;
 printf("(%lf,%lf,%lf)\n",corx,cory,corz);
 }

 /* Множення 2 веторів структури Quaternion */

void quater_mnozh(quaternion* q){
 double corx,cory,corz;
 corx = q->x1 * q->x2;
 cory = q->y1 * q->y2;
 corz = q->z1 * q->z2;
 printf("(%lf,%lf,%lf)\n",corx,cory,corz);
 }

 /* Віднімання 2 веторів структури Quaternion */

void quater_vidnimannya(quaternion* q){
 double corx,cory,corz;
 corx = q->x1 - q->x2;
 cory = q->y1 - q->y2;
 corz = q->z1 - q->z2;
 printf("(%lf,%lf,%lf)\n",corx,cory,corz);
 }

/* Виведення структури Point3d для coord_x, coord_y, coord_z у ПДСК */

void output_point3d_in_pdsk(point* p){
    printf("Your coordinate is: (%i; %i; %i)\n", p->cord_x,p->cord_y,p->cord_z);
}

/* Введення структури Point3d для coord_x, coord_y, coord_z у ПДСК */

void input_point3d_in_pdsk(point* p, int xc, int yc, int zc){
    p->cord_x = xc;
    p->cord_y = yc;
    p->cord_z = zc;
    output_point3d_in_pdsk(p);
}

/*Перевод координат із ПДСК у сферичну систему координат*/

void from_pdsk_in_sphere(point* p){
    p->radius = sqrt(pow(p->cord_x, 2)+pow(p->cord_y, 2)+pow(p->cord_z, 2));
    p->ugol_teta = acos(p->cord_z/p->radius);
    p->ugol_fi = atan(p->cord_y/p->cord_x);
}

/*Перевод координат із ПДСК у циліндричну систему координат*/

void from_pdsk_in_cilindr(point* p){
    p->ro = sqrt(pow(p->cord_x, 2)+pow(p->cord_y, 2));
    p->ugol_fi_cil = atan(p->cord_y/p->cord_x);
}

/*Множення точки на число*/

void mnozh_tochk(point* p, int sklr){
    printf("Your multiplication points on sklr: \n");
    p->cord_x *= sklr;
    p->cord_y *= sklr;
    p->cord_z *= sklr;
}

/*Функція зсуву точки на деяку координату (x,y,z)*/

void zsyv_tochok_pdsk(point* p, int cx, int cy, int cz){
    p->cord_x += cx;
    p->cord_y += cy;
    p->cord_z += cz;
}

/* Введення кількості точок і ребер Point3d для coord_x, coord_y, coord_z у ПДСК */

int input_figure3d(figure* f, int num_poin, int num_ed){
    f->num_points = num_poin;
    f->num_edges = num_ed;
    return 0;
}

/* Введення ребра*/

int input_edges(){
    int ed;
    ed = rand();
    return ed;
}

/* Введення вершини ребра*/

int input_tops(){
    int tp;
    tp = rand();
    return tp;
}


/* Введення масиву точок і ребер */

int input_array_of_points_edges(figure* f, point* p){
    int i,j;
    f->points = (int**)malloc(f->num_points * sizeof(int*));
    for (i=0;i<f->num_points;i++){
        f->points[i] = (int*)malloc(4*sizeof(int));
    }
    printf("Enter array of points:\n");
    for (i=0;i<f->num_points;i++){
        input_point3d_in_pdsk(p, i+rand(), i+87, i-93);
        for (j=0;j<4;j++){
            if (j==0){
                f->points[i][j]= i+1;
            }
            else if (j==1){
                f->points[i][j]= p->cord_x;
            }
            else if (j==2){
                f->points[i][j]= p->cord_y;
            }
            else if (j==3){
                f->points[i][j]= p->cord_z;
            }
        }
    }
    printf("Your points is:\n");
    for (i=0;i<f->num_points;i++){
        for (j=0;j<4;j++){
            printf("%i ", f->points[i][j]);
        }
        printf("\n");
    }
    f->edges = (int**)malloc(f->num_edges * sizeof(int*));
    for (i=0;i<f->num_edges;i++){
        f->edges[i] = (int*)malloc(3*sizeof(int));
    }
    for (i=0;i<f->num_edges;i++){
        for (j=0;j<3;j++){
            if (j==0){
                f->edges[i][j] = input_tops();
            }
            else if (j==1){
                f->edges[i][j] = input_tops();
            }
            else if (j==2){
                f->edges[i][j] = input_edges();
            }
        }
    }
    printf("Your edges is: \n");
    for (i=0;i<f->num_edges;i++){
        for (j=0;j<3;j++){
        printf("%d ", f->edges[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/* Введення кута повороту*/

void input_angle(angle_gl* a, int angle){
    a->angle = angle;
}

/* Проекція координати x*/

int proection_on_ploskost_x(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm){
    int te, prx;
    te = (cx*cord_x_norm+cy*cord_y_norm+cz*cord_z_norm)/(pow(cord_x_norm,2)+pow(cord_y_norm,2)+pow(cord_z_norm,2));
    prx = cord_x_norm*te+cx;
    return prx;
}

/* Проекція координати y*/

int proection_on_ploskost_y(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm){
    int te, pry;
    te = (cx*cord_x_norm+cy*cord_y_norm+cz*cord_z_norm)/(pow(cord_x_norm,2)+pow(cord_y_norm,2)+pow(cord_z_norm,2));
    pry = cord_y_norm*te+cy;
    return pry;
}

/* Проекція координати z*/

int proection_on_ploskost_z(int cx, int cy, int cz, int cord_x_norm, int cord_y_norm, int cord_z_norm){
    int te, prz;
    te = (cx*cord_x_norm+cy*cord_y_norm+cz*cord_z_norm)/(pow(cord_x_norm,2)+pow(cord_y_norm,2)+pow(cord_z_norm,2));
    prz = cord_z_norm*te+cz;
    return prz;
}

/* Проекця точки */

int proection_of_point(point* p, figure* f){
    int i,j;
    input_point3d_in_pdsk(p, i+10, i+20, i+30);
    for (i=0;i<3;i++){
        if (i==0){
        p->norm_vector[i]= p->cord_x;
        }
        else if (i==1){
        p->norm_vector[i]= p->cord_y;
        }
        else if (i==0){
        p->norm_vector[i]= p->cord_z;
        }

    }
    for (i=0;i<f->num_points;i++){
        for (j=0;j<4;j++){
            if (j==0){
                f->points[i][j]= i+1;
            }
            else if (j==1){
                f->points[i][j]= proection_on_ploskost_x(f->points[i][j], f->points[i][j+1], f->points[i][j+2], p->norm_vector[0], p->norm_vector[1], p->norm_vector[2]);
            }
            else if (j==2){
                f->points[i][j]= proection_on_ploskost_x(f->points[i][j-1], f->points[i][j], f->points[i][j+1], p->norm_vector[0], p->norm_vector[1], p->norm_vector[2]);
            }
            else if (j==3){
                f->points[i][j]= proection_on_ploskost_x(f->points[i][j-2], f->points[i][j-1], f->points[i][j], p->norm_vector[0], p->norm_vector[1], p->norm_vector[2]);
            }
        }
    }
    for (i=0;i<f->num_points;i++){
        for (j=0;j<4;j++){
            printf("%i ", f->points[i][j]);
        }
        printf("\n");
    }
}

/* Запись в файл */

void file_write(point *p, figure *f, quaternion *q, int inf){
    FILE *file;
    file = fopen("result_quaternion.txt", "rw");
    fscanf(file, "%i \n", inf);
    fclose(file);
}

/* Очищення пам'яті */

int clear_all(figure* f){
    for(int i=0;i<4;i++) free(f->points[i]);
    free(f->points);
    for(int i=0;i<3;i++) free(f->edges[i]);
    free(f->edges);
}

int main(){
    struct Point3D point;
    input_point3d_in_pdsk(&point, 1,5,8);
    from_pdsk_in_sphere(&point);
    from_pdsk_in_cilindr(&point);
    printf("In spherical coordinate your point has: ");
    printf("\nRadius %lf, Angle fi %lf, Angle teta %lf\n", point.radius, point.ugol_fi, point.ugol_teta);
    printf("In cylindrical coordinate your point has: ");
    printf("\nRo %lf, Angle fi %lf\n", point.ro, point.ugol_fi_cil);
    printf("Multiplication on number :\n");
    mnozh_tochk(&point, 100);
    output_point3d_in_pdsk(&point);
    printf("Shift of point: \n");
    zsyv_tochok_pdsk(&point, 2, 3, 4);
    output_point3d_in_pdsk(&point);
    struct Quaternion quaternion;
    input_quatern(&quaternion, 1, 2, 3, 3, 2, 1);
    printf("Vector Multiplication: \n");
    quater_mnozh(&quaternion);
    struct Figure3D figure;
    input_figure3d(&figure, 5, 6);
    input_array_of_points_edges(&figure, &point);
    printf("Proection figure on surface: \n");
    proection_of_point(&point, &figure);
    file_write(&point, &figure, &quaternion, point.cord_x);
    file_write(&point, &figure, &quaternion, point.cord_y);
    file_write(&point, &figure, &quaternion, point.cord_z);
    clear_all(&figure);
    return 0;
}


