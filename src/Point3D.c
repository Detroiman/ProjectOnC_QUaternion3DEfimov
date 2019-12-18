#include "../headers/Point3D.h"
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <conio.h>

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

int main(){
    struct Point3D point;
    input_point3d_in_pdsk(&point, 2, 4, 5);
    output_point3d_in_pdsk(&point);
    from_pdsk_in_sphere(&point);
    from_pdsk_in_cilindr(&point);
    mnozh_tochk(&point, 5);
    zsyv_tochok_pdsk(&point, 2,2,2);
}


