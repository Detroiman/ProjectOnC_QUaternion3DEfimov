#include "../headers/Quaternion3D.h"
#include <math.h>
#include <malloc.h>
#include <conio.h>

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

int main(){
    struct Quaternion3D quaternion;
    input_quatern(&quaternion, 2,3,4,5,6,7);
 }
