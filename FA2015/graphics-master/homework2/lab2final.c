#include <FPT.h>


  //Global variables
  int numobjects;
  int numpoints[10]; //array of number of points in each file
  double x[10][12000], y[10][12000]; //array for each object
  int numpolys[10];
  int psize[10][8000];
  int con [10][8000][20];
  double red[10][8000];
  double grn[10][8000];
  double blu[10][8000];
  double xcen;
  double ycen;

double findmin(double test[10][12000], int size, int onum){
  int c;
  double minimum = test[onum][0];
  for ( c = 1 ; c < size ; c++ ) {
    //printf("x: %f \n", test[onum][c]);
        if ( test[onum][c] < minimum ) 
        {
           minimum = test[onum][c];
        }
    } 
  //printf("size: %d",size);
 return minimum;
}

double findmax(double test[10][12000], int size, int onum){

  int c;
  double max = test[onum][0];
  for ( c = 1 ; c < size ; c++ ) {
    //printf("x: %f \n", test[onum][c]);
        if ( test[onum][c] > max ) 
        {
           max = test[onum][c];
        }
    } 
  //printf("size: %d",size);
 return max;
}


void printarray(double  w[100], int z) {
	int i;
	for (i = 0; i < z; i++) {
		printf("%d : %f\n", i, w[i]);

	}
	printf("\n");
}
void scaleandfitobject(int onum){
 //move to 0,0
 // enlarge
 //center at 300, 300

  double xmin = findmin(x, numpoints[onum], onum);
  double xmax = findmax(x,numpoints[onum], onum);
  double ymin = findmin(y, numpoints[onum], onum);
  double ymax = findmax(y,numpoints[onum], onum);

  /* printf("xminumum: %f \n", xmin );
  printf("xmax: %f \n", xmax );
  printf("yminumum: %f \n", ymin );
  printf("ymax: %f \n", ymax );*/

  xcen = (xmin+xmax) / 2;
  ycen = (ymin+ymax)/ 2;
  // printf("xcen: %f \n", xcen );
  // printf("ycen: %f \n", ycen );
  int i;

  //move to 0,0
  for(i = 0; i < numpoints[onum]; i ++){
    x[onum][i] = x[onum][i] - xcen;
    y[onum][i] = y[onum][i] - ycen;
  }
    
  //enlarge
  double radius = (xmax - xmin) /2;
  printf("radius: %f", radius);
  double tempr = 150/radius;

  for(i = 0; i < numpoints[onum]; i ++){

    if(radius <= 1){
     x[onum][i] = x[onum][i] * tempr;
     y[onum][i] = y[onum][i] * tempr;
    }if(radius >= 300 ){
     x[onum][i] = x[onum][i] * tempr;
     y[onum][i] = y[onum][i] * tempr;
    }else{
    x[onum][i] = x[onum][i] * .75;
    y[onum][i] = y[onum][i] * .75;
    }
  }

  //center at 300,300

 for(i = 0; i < numpoints[onum]; i ++){
    x[onum][i] = x[onum][i] + 300;
    y[onum][i] = y[onum][i] + 300;
  }
}

void rotate(onum){
  
  int i;
  double x1, y1, temp_x1, temp_y1;

  for( i = 0; i < numpoints[onum]; i ++){
    x1 = x[onum][i];
    y1 = y[onum][i];

    x[onum][i] = (300 + ((x1 - 300) * cos(-.05)) - ((y1 - 300) * sin(-.05)));
    y[onum][i]= (300 + ((x1 - 300) * sin(-.05)) + ((y1- 300) * cos(-.05)));

    // x[onum][i] = x1 * cos(90) - y1 * sin(90);
    // y[onum][i] = x1* sin(90) + y1 * cos(90);

     }

}

void display(int onum){
  double tempx[100];
  double tempy[100];
  int i;
  int j;
  int holder;

  for(i = 0; i < numpolys[onum]; i++){

    for(j = 0; j < psize[onum][i]; j++){
      holder =  con[onum][i][j];
      tempx[j] = x[onum][holder];
      tempy[j] = y[onum][holder];      
    }
    G_rgb(red[onum][i], grn[onum][i], blu[onum][i]);
    G_fill_polygon(tempx, tempy, psize[onum][i]);
    //printarray(tempx, j);
  }

}

void readobject(FILE *g, int onum){
  int k;

  //read first number in file and store in numpoints[onum]
  //file 0 has 7 coordinates, numpoints[0] = 7
  fscanf(g, "%d", &numpoints[onum]); 

  for(k = 0; k < numpoints[onum]; k++){
    //loop through and initialize all x and y coordinates in file
    fscanf(g, "%lf %lf", &x[onum][k], &y[onum][k]);
  }

  //set how many polyons are being drawn from this file
  //file 0 has 6 polygons, numpolys[0] = 6
  fscanf(g, "%d", &numpolys[onum]);
  //printf("numpolys: %d \n", numpolys[onum]);
  int c, p;
  for(k = 0; k < numpolys[onum]; k++){
    fscanf(g, "%d", &psize[onum][k]);
    for(p = 0; p < psize[onum][k]; p++){
      fscanf(g, "%d", &con[onum][k][p]);
      //printf("%d ", con[onum][k][p]);
    }
 
    //printf("psize: %d \n", psize[onum][0]);
  } 

  //get color values
  for(k = 0; k < numpolys[onum]; k ++){
    fscanf(g, "%lf %lf %lf", &red[onum][k], &grn[onum][k], &blu[onum][k]);
    //printf("colors: %lf %lf %lf \n", red[onum][0], grn[onum][0], blu[onum][0]);
  }
 
  
}

int main(int argc, char **argv){
  
  if(argc == 1){
    printf("usage: pgm_name file1.xy file2.xy...");
    exit(1);
  }

  int i; FILE *g;

  numobjects = argc - 1;

  for(i = 0; i < numobjects; i ++){
    g = fopen(argv[i + 1], "r"); //opening a file

    if(g == 'NULL') {
      printf("Can't open file %s \n", argv[i+1]); exit(1);
    }
    //G_init_graphics(600,600);
    readobject(g, i); //read object i
    scaleandfitobject(i); //scale object i to fit screen
    //display(i);
  }

  int onum, q;
  G_init_graphics(600,600);
 

  while(0 == 0){

  q = G_wait_key();

  if(('0' <= q) && (q <= '9')){
    G_rgb(0,0,0);
    G_clear() ; 
    onum = q - 48;
    rotate(onum);
    display(onum);

  }else if(q == 'q'){
    exit(1);
  }
 
  
 
  }

}


