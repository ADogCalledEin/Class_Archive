/*Screen 600X600
input whole number
split circle into parts that are input by user
challenge: fill parts with different colors <- solved using G_fill_sector(x,y,radius, ang1,ang2)
*/

#include <stdio.h>
#include <FPT.h>
#include <math.h>
#include <stdlib.h>

double r2(){
  return (double)rand() / (double)RAND_MAX;
}

int main(){
  double i,t,x,y,a,b,v;
  int num;
  printf("Please put in a number:\n");
  scanf("%d", &num);

  G_init_graphics(600, 600);
  G_circle(300,300,200);
  i=0; t =0; v=0;
  while (i<num){
    t=(i*2*M_PI)/num;
    v=((i+1)*2*M_PI)/num;
    x=200*cos(t)+300; //finding the x and y coordinates using radians
    y=200*sin(t)+300; //to define the sectors
    G_line(300,300,x,y); //drawing the line
    G_rgb(r2(), r2(), r2());
    G_fill_sector(300,300, 200, t, v); //filling in the sector using xcen, ycen, radius, angle1, angle 2
    i++;
  }
  G_wait_key();
  return 0;
}
