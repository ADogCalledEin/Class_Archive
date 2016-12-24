
// read the data from multiple xy files and display all of the objects

#include <FPT.h>
#include <D3d_matrix.h>
#include <math.h>
     // problems if forget to include D3d_matrix.h
int numpoints[10], numpolys[10];
double x[10][10000], y[10][10000], z[10][10000]; //array for each object
int psize[10][5000];
int con[10][8000][3000];
int numobjects, vector_sign = 0;
double xlow[10], xhigh[10], ylow[10], yhigh[10], zlow[10], zhigh[10];
double xcen[10], ycen[10], zcen[10];
double xscale[10], yscale[10],zscale[10];

void boundingBox(int onum){
  int i;

  xlow[onum] = x[onum][0];
  xhigh[onum] = x[onum][0];
  ylow[onum] = y[onum][0];
  yhigh[onum] = y[onum][0];
  zlow[onum] = z[onum][0];
  zhigh[onum] = z[onum][0];

  for (i=0; i < numpoints[onum]; i++){
    if (x[onum][i] <= xlow[onum]){
      xlow[onum] = x[onum][i];
    }
    if (y[onum][i] <= ylow[onum]){
      ylow[onum] = y[onum][i];
    }
    if (z[onum][i] <= zlow[onum]){
      zlow[onum] = z[onum][i];
    }
    if(x[onum][i] >= xhigh[onum]){
      xhigh[onum] = x[onum][i];
    }
    if(y[onum][i] >= yhigh[onum]){
      yhigh[onum] = y[onum][i];
    }
    if(z[onum][i] >= zhigh[onum]){
      zhigh[onum] = z[onum][i];
    }
  }
  xcen[onum] = (xhigh[onum] + xlow[onum])/2;
  ycen[onum] = (yhigh[onum] + ylow[onum])/2;
  zcen[onum] = (zhigh[onum] + zlow[onum])/2;

}

double scaleFactor(int onum){
  double scale;
  double radiusx = (xhigh[onum]-xlow[onum]);
  double radiusy = (yhigh[onum]-ylow[onum]); //finding the radius of the shape
  double radiusz = (zhigh[onum]-zlow[onum]);

  if (radiusx >= radiusy && radiusx >= radiusz){
    scale = radiusx;
  }else if (radiusy >= radiusx && radiusy >= radiusz){
    scale = radiusy;
  }else{
    scale = radiusz;
  }
  xscale[onum] = 600/scale;
  yscale[onum] = 600/scale;
  zscale[onum] = 600/scale;

  return (2/(scale));
}


void readObject(FILE *g, int onum){
  int k, i, count;
  fscanf(g, "%d", &numpoints[onum]); //file scanning using fscanf()

  for (k = 0; k < numpoints[onum]; k++){
    fscanf(g, "%lf %lf %lf", &x[onum][k], &y[onum][k], &z[onum][k]); //scanning in the coordinates
  }

  fscanf(g, "%d", &numpolys[onum]); //scanning the number of polygons

  for (i = 0; i < numpolys[onum]; i++){  //getting the coordinates for the polygons
    fscanf(g, "%d", &psize[onum][i]); //number of the points in the polygon
    for (count = 0; count < psize[onum][i]; count++){
      fscanf(g, "%d", &con[onum][i][count]); //scanning in the coords of the polygon
    } 
  }
}




void draw_all_objects(int onum){
  int i,j;
  double v[3],w[3],e[3], xprime[20], yprime[20];
  double halfangle = (300/(tan(M_PI/3)));
  double xb, yb, cross[3];

  for (i=0; i < numpolys[onum]; i++){
    int size = psize[onum][i];
    double polyx[size], polyy[size], polyz[size];
    for(j=0; j < size; j++){
      int side = con[onum][i][j];
      polyx[j]= x[onum][side];
      polyy[j]= y[onum][side];
      polyz[j]= z[onum][side];
    }
    v[0] = polyx[1] - polyx[0];
    v[1] = polyy[1] - polyy[0];
    v[2] = polyz[1] - polyz[0];  

    w[0] = polyx[2] - polyx[0];
    w[1] = polyy[2] - polyy[0];
    w[2] = polyz[2] - polyz[0];

    e[0] = 0 - polyx[0];
    e[1] = 0 - polyy[0];
    e[2] = 0 - polyz[0];

    D3d_x_product(cross,v,w);
    double prod = D3d_dot_product(cross,e);

    if (prod >= 0 && vector_sign == 0){
      for (j = 0; j< size; j++){
        xb = polyx[j]/polyz[j];
        yb = polyy[j]/polyz[j];
      
        xprime[j] = (halfangle*xb) + 300;
        yprime[j] = (halfangle*yb) + 300;
      }
      G_polygon(xprime, yprime, size);
    }else if (prod <=0 && vector_sign == 1){
      for (j = 0; j< size; j++){
        xb = polyx[j]/polyz[j];
        yb = polyy[j]/polyz[j];
      
        xprime[j] = (halfangle*xb) + 300;
        yprime[j] = (halfangle*yb) + 300;
      }
      G_polygon(xprime, yprime, size);
    }
    
  }
}

int main (int argc, char **argv)
{
  int i, numobjects; FILE*g;

  if (argc == 1){
    printf("Usage: pgm_name file1.xyz file2.xyz.....\n"); //telling the user how to use the program then exiting
    exit(1);
  }

  numobjects = argc - 1;

  for(i=0; i < numobjects; i++){
    g = fopen(argv[i+1], "r");
    if (g == NULL){
      printf("Can't open file %s\n", argv[i+1]);
      exit(1);
    }
    readObject(g,i);
    printf("read it\n");
    //scaleAndFitObject(i);
    //printf("scaled it\n"); 
  }
  double V[4][4], Vi[4][4], toscale;
  int q, onum, key,p;
  G_init_graphics(600,600);
  // lots of stuff here 

  //  Half_angle_degrees ... I think you have 40 degrees as the default
  int h = 0 ;
  int k; // h marks the current object
  int sign = 1 ;
  char action = 't' ;


  while (1){
      key = G_wait_key() ;
  
      if(('0' <= key) && (key <= '9')){
        G_rgb(0,0,0);
        G_clear();
        p = key - 48;
      }
      boundingBox(p);
      D3d_make_identity (V) ;
      D3d_make_identity (Vi) ;
      toscale = scaleFactor(p);
      D3d_scale(V,Vi,toscale,toscale,toscale);
      D3d_translate(V,Vi,0,0,2);
      D3d_mat_mult_points (x[p],y[p],z[p],  V,  x[p],y[p],z[p],numpoints[p]) ;
      draw_all_objects(p);
  
      while (1) {
        q = G_wait_key();
        if (q == 'q') {
          exit(0) ;
  
        } else if (q == 'c') {
          sign = -sign ;
  
        } else if (q == 't') {
          action = q ;
  
        } else if (q == 'S') {
          action = q ;
  
        } else if (q == 'r') {
          action = q ;

        } else if (q == 'v') {
          if (vector_sign == 0){
            vector_sign = 1;
          }else{
            vector_sign = 0;
          }
  
        } else if (('0' <= q) && (q <= '9')) {
          k = q - '0' ;  
          if (h < numobjects) h = k ;
  
        } else if ((q == 'x') && (action == 't')) {
          D3d_make_identity (V) ;
          D3d_make_identity (Vi) ;
          D3d_translate(V,Vi,(0.2*sign),0,0);
          D3d_mat_mult_points (x[h],y[h],z[h],  V,  x[h],y[h],z[h],numpoints[h]) ;
  
        } else if ((q == 'y') && (action == 't')) {
          D3d_make_identity (V) ;
          D3d_make_identity (Vi) ;
          D3d_translate(V,Vi,0,(0.2*sign),0);
          D3d_mat_mult_points (x[h],y[h],z[h],  V,  x[h],y[h],z[h],numpoints[h]) ;
  
        } else if ((q == 'z') && (action == 't')) {
          D3d_make_identity (V) ;
          D3d_make_identity (Vi) ;
          D3d_translate(V,Vi,0,0,(0.2*sign));
          D3d_mat_mult_points (x[h],y[h],z[h],  V,  x[h],y[h],z[h],numpoints[h]) ;
  
        } else if ((q == 'x') && (action == 'r')) {
          D3d_make_identity (V) ;
          D3d_make_identity (Vi) ;
          boundingBox(h);
          D3d_translate(V, Vi, -xcen[h], -ycen[h], -zcen[h]);
          D3d_rotate_x(V, Vi, (M_PI/40*sign));
          D3d_translate(V, Vi, xcen[h], ycen[h], zcen[h]);
          D3d_mat_mult_points (x[h],y[h],z[h],  V,  x[h],y[h],z[h],numpoints[h]) ;
  
        } else if ((q == 'y') && (action == 'r')) {
          D3d_make_identity (V) ;
          D3d_make_identity (Vi) ;
          boundingBox(h);
          D3d_translate(V, Vi, -xcen[h], -ycen[h], -zcen[h]);
          D3d_rotate_y(V, Vi, (M_PI/40*sign));
          D3d_translate(V, Vi, xcen[h], ycen[h], zcen[h]);
          D3d_mat_mult_points (x[h],y[h],z[h],  V,  x[h],y[h],z[h],numpoints[h]) ;
  
        } else if ((q == 'z') && (action == 'r')) {
          D3d_make_identity (V) ;
          D3d_make_identity (Vi) ;
          boundingBox(h);
          D3d_translate(V, Vi, -xcen[h], -ycen[h], -zcen[h]);
          D3d_rotate_z(V, Vi, (M_PI/40*sign));
          D3d_translate(V, Vi, xcen[h], ycen[h], zcen[h]);
          D3d_mat_mult_points (x[h],y[h],z[h],  V,  x[h],y[h],z[h],numpoints[h]) ;
  
        } else {
          printf("no action\n") ;
        }

        G_rgb(0,0,0) ; 
        G_clear() ;
        G_rgb(0,0,1) ;
        draw_all_objects(h) ;
  
    }
}

}

