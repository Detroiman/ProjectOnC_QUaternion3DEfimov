#include "../headers/Figure3D.h"
#include "../headers/Point3D.h"
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>

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
