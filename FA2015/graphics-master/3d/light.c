
// read the data from multiple xy files and display all of the objects

#include <FPT.h>
#include <D3d_matrix.h>
#include <math.h>
     // problems if forget to include D3d_matrix.h

typedef
struct {
  int objnum ;
  int polynum ;
  double dist ;
}
THING ;

THING allpolys[10000];

int numpoints[10], numpolys[10];
double x[10][10000], y[10][10000], z[10][10000]; //array for each object
int psize[10][5000];
int con[10][8000][3000];
int numobjects, vector_sign = 0;
double xlow[10], xhigh[10], ylow[10], yhigh[10], zlow[10], zhigh[10];
double xcen[10], ycen[10], zcen[10];
double xscale[10], yscale[10],zscale[10];
double lightx, lighty, lightz, ambientcon, diffusepro, specpow, ired, igrn, iblu;
double color[3];


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

int compare (const void *p, const void *q)
{
  THING *a, *b ;

  a = (THING*)p ;
  b = (THING*)q ;

  if  (((*a).dist) > ((*b).dist)) return -1 ;
  else if (((*a).dist) < ((*b).dist)) return 1 ;
  else return 0 ;
}

void createUnitVector(double *input, double output[3]){
  double total = (input[0]*input[0]) + (input[1]*input[1]) + (input[2]*input[2]);
  double divide = sqrt(total);
  output[0] = (input[0]/divide);
  output[1] = (input[1]/divide);
  output[2] = (input[2]/divide);
}

double intensity(double *polyx, double *polyy, double *polyz){
  double v[3],w[3],e[3],l[3],norm[3],reflect[3],angle, specularity;

  v[0] = polyx[1] - polyx[0];
  v[1] = polyy[1] - polyy[0];
  v[2] = polyz[1] - polyz[0];  

  w[0] = polyx[2] - polyx[0];
  w[1] = polyy[2] - polyy[0];
  w[2] = polyz[2] - polyz[0];

  l[0] = lightx - polyx[0];
  l[1] = lighty - polyy[0];
  l[2] = lightz - polyz[0];

  e[0] = 0 - polyx[0];
  e[1] = 0 - polyy[0];
  e[2] = 0 - polyz[0];


  D3d_x_product(norm,v,w);
  createUnitVector(e,e);
  createUnitVector(norm, norm);
  createUnitVector(l, l);
  angle = D3d_dot_product(norm, l);

  if (angle < 0){
    norm[0] = -norm[0];
    norm[1] = -norm[1];
    norm[2] = -norm[2];
    angle = D3d_dot_product(norm, l);
  }



  double edotn = D3d_dot_product(e, norm);
  if (edotn < 0) { return ambientcon ; }



  double diffuse = angle*diffusepro;

  //2(angle)norm-l
  reflect[0]=(2*angle)*norm[0] - l[0];
  reflect[1]=(2*angle)*norm[1] - l[1];
  reflect[2]=(2*angle)*norm[2] - l[2];

  createUnitVector(reflect, reflect);

  double edotr = D3d_dot_product(e, reflect);

  if(edotr < 0){
    specularity = 0;
  }else{
    specularity = (1 - ambientcon - diffusepro)*(pow(edotr,specpow));
  }
  double inten = ambientcon + diffuse + specularity;
return inten;
}

void colored(double red, double blu, double grn, double intensity){
  double ratio;
  color[0] = red;
  color[1] = grn;
  color[2] = blu;  

  double ambfuse = ambientcon + diffusepro;
  if (intensity < ambfuse){
    ratio = intensity / ambfuse;
    color[0] = red * ratio;
    color[1] = grn * ratio;
    color[2] = blu * ratio;
  } else if (intensity > ambfuse){
    ratio = (intensity - ambfuse)/(1-ambfuse);
    color[0] = red + (1-red)* ratio;
    color[1] = grn + (1-grn)* ratio;
    color[2] = blu + (1-blu)* ratio;
  }


}

void draw_all_objects(THING *allpolys, int numthings){
  int i,j, onum, polyn;
  double v[3],w[3],e[3], xprime[20], yprime[20];
  double halfangle = (300/(tan(M_PI/3)));
  double xb, yb, norm[3];

  qsort(allpolys, numthings, sizeof(THING), compare ) ;
  
  for (i=0; i < numthings; i++){
    onum = allpolys[i].objnum;
    polyn = allpolys[i].polynum;
    int size = psize[onum][polyn];
    double polyx[size], polyy[size], polyz[size];
    for(j=0; j < size; j++){
      int side = con[onum][polyn][j];
      polyx[j]= x[onum][side];
      polyy[j]= y[onum][side];
      polyz[j]= z[onum][side];
    }
    for (j = 0; j< size; j++){
      xb = polyx[j]/polyz[j];
      yb = polyy[j]/polyz[j];
    
      xprime[j] = (halfangle*xb) + 300;
      yprime[j] = (halfangle*yb) + 300;
    }
    double lmodel = intensity(polyx, polyy, polyz);

    colored(ired, igrn, iblu, lmodel);

    G_rgb(color[0],color[1],color[2]);
    G_fill_polygon(xprime, yprime, size);
    //G_rgb(0,0,0);
    //G_polygon(xprime, yprime, size);
  }
}

void init_array(){
  int i,numthings,counter, j;
  counter = 0 ;
  for (i=0; i<numobjects; i++){
    counter += numpolys[i];
  }
  numthings = counter;
  counter = 0;
  for (i=0; i < numobjects; i++){
    for (j=0;j < numpolys[i]; j++){
      allpolys[counter].objnum = i;
      allpolys[counter].polynum = j;
      allpolys[counter].dist = z[i][con[i][j][0]];
      counter++;
    }
  }
  draw_all_objects(allpolys, numthings);
}

int main (int argc, char **argv)
{
  int i; FILE*g;

  if (argc == 1){
    printf("Usage: pgm_name file1.xyz file2.xyz.....\n"); //telling the user how to use the program then exiting
    exit(1);
  }

  numobjects = argc - 1;
  printf("numobjects: %d\n", numobjects);

  for(i=0; i < numobjects; i++){
    g = fopen(argv[i+1], "r");
    if (g == NULL){
      printf("Can't open file %s\n", argv[i+1]);
      exit(1);
    }
    readObject(g,i);
  }
  /*printf("What color do want? Enter in like: r g b with numbers between or equal to 0 and 1\n");
  scanf("%lf %lf %lf", &ired, &igrn, &iblu);
  printf("Please input the location of the light like so: x y z\n");
  scanf("%lf %lf %lf", &lightx, &lighty, &lightz);
  printf("Please enter in the ambient constant\n");
  scanf("%lf", &ambientcon);
  printf("Now for the diffuse proportion\n");
  scanf("%lf", &diffusepro);
  printf("And for the specular power\n");
  scanf("%lf", &specpow);*/
  lightx = 100;
  lighty = 200;
  lightz = -50;
  ired = 1; igrn = 0; iblu = 0;
  ambientcon = 0.2;
  diffusepro = 0.5;
  specpow = 50;

 // printf("lx:%lf ly:%lf lz:%lf\n ambient: %lf diffuse:%lf\n specular: %lf\n", lightx, lighty, lightz, ambientcon, diffusepro, specpow);

  double V[4][4], Vi[4][4], toscale;
  int q, onum, key,p;
  G_init_graphics(600,600);

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
      for (i=0; i< numobjects; i++){
        boundingBox(i);
        D3d_make_identity(V) ;
        D3d_make_identity(Vi) ;
        toscale = scaleFactor(i);
        D3d_scale(V,Vi,toscale,toscale,toscale);
        D3d_mat_mult_points (x[i],y[i],z[i],  V,  x[i],y[i],z[i],numpoints[i]) ;
      }
      q = key;
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

      G_rgb(1,1,1) ; 
      G_clear() ;
      init_array();

    }

}

