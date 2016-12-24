/*Screen 600X600
click around graphics window for points
connect the points into a polygon
???
profit
*/

#include <stdio.h>
#include <FPT.h>
#include <math.h>
#include <stdlib.h>

double r2(){
  return (double)rand() / (double)RAND_MAX;
}

int clickAndSave(double x[100], double y[100]){
  double p[2];
  int count;
  double x1, y1;
  count = 0;
  G_wait_click(p);
  x1= p[0]; y1=p[1];
  G_fill_circle(x1, y1, 2);
  x[count] = x1;
  y[count] = y1;
  count++;

  while(x1 >= 20 && y1 >= 20){
    G_wait_click(p);
    x1 = p[0] ; y1 = p[1];
    G_fill_circle(x1, y1, 2);
    if (x1 <=20 && y1 <=20){
      break;
    }
    x[count] = x1;
    y[count] = y1;
    count++;
  }
  return count;
}

void mypolygon(double x[100], double y[100], int n){
  int count;
  for (count = 0; count < n; count++){
    if(count == n-1){
      G_line (x[count], y[count], x[0], y[0]);
      break;
    }
    G_line(x[count], y[count], x[count+1], y[count+1]);
  }
  G_rgb(r2(),r2(),r2());
  G_fill_polygon(x,y,n);
}

int main(){
  double ax[100], ay[100], bx[100], by[100];
  int anum, bnum;
  G_init_graphics(600, 600);
  G_rgb(1,0,0);
  G_fill_rectangle(0,0, 20, 20);

  anum = clickAndSave(ax, ay);
  mypolygon(ax,ay,anum);
  G_rgb(1,0,0);
  bnum = clickAndSave(bx, by);
  mypolygon(bx, by, bnum);

  

  G_wait_key();
  return 0;
}
