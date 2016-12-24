#include <FPT.h>
#include <stdlib.h>
#include <stdio.h>

	int numpoints[10], numpolys[10];
	double x[10][12000], y[10][12000]; //array for each object
	int psize[10][8000];
	int con[10][8000][20];
	int numobjects;
	double xcenter, ycenter;

	double red[10][8000];
	double grn[10][8000];
	double blu[10][8000];

double max(double temp[10][12000], int size, int onum){ //generalized for finding the max of a shape
	int i;												//for the scaling
	double max = temp[onum][0];
	for (i=1; i<size; i++){	
		if(temp[onum][i] > max){
		max = temp[onum][i];
		}
	}
	return max;
}

double min(double temp[10][12000], int size, int onum){ //generalized for finding the min of a shape
	int i;												//for the scaling
	double min = temp[onum][0];
	for (i=1; i<size; i++){	
		if(temp[onum][i] < min){
		min = temp[onum][i];
		}
	}
	return min;
}

void rotate(int onum){ //rotating the shape

	int i;
  	double x1, y1;

  	for( i = 0; i < numpoints[onum]; i ++){
    	x1 = x[onum][i];
    	y1 = y[onum][i];

    	x[onum][i] = (300 + ((x1 - 300) * cos(-.05)) - ((y1 - 300) * sin(-.05)));
    	y[onum][i]= (300 + ((x1 - 300) * sin(-.05)) + ((y1- 300) * cos(-.05)));

     }

}

void display(int onum){
	double tempx[100], tempy[100];
	int f, j,i;
	int temp;
	for (f=0; f<numpolys[onum]; f++){
		printf("shape coords\n");
		for(j=0; j<psize[onum][f]; j++){
			temp = con[onum][f][j];
			printf("index:%d\n", con[onum][f][j]);
			tempx[j] = x[onum][temp]; 
			tempy[j] = y[onum][temp];
			printf("x:%lf y:%lf\n", tempx[j], tempy[j]);
		}

		G_rgb(red[onum][f], grn[onum][f], blu[onum][f]);
		printf("red:%lf grn:%lf blu:%lf\n", red[onum][f], grn[onum][f], blu[onum][f] );
		G_fill_polygon(tempx, tempy, psize[onum][f]);
		printf("drew shape %d\n",f );
		/*printf("poly size: %d\n", psize[onum][f]);
		for (i=0;i<psize[onum][f];i++){
			printf("x:%lf y:%lf\n", tempx[i], tempy[i]);
		}*/

	//G_clear(0,0,0);
	}
}

void scaleAndFitObject(int onum){

	int i;

	double xmax = max(x, numpoints[onum], onum); //finding the min and max of the shape
	double xmin = min(x, numpoints[onum], onum);
	double ymax = max(y, numpoints[onum], onum);
	double ymin = min(y, numpoints[onum], onum);

	xcenter = (xmin + xmax) / 2;	//finding the center
	ycenter = (ymin + ymax) / 2;

	for (i=0; i<numpoints[onum]; i++){  //brings it to the origin
		x[onum][i] = x[onum][i] - xcenter;
		y[onum][i] = y[onum][i] - ycenter;
	}

	double radius = (xmax-xmin) / 2; //finding the radius of the shape

	double sizer = 150/radius; //to enlarge if necessary

	for(i=0; i<numpoints[onum]; i++){
		if (radius <= 1){
			x[onum][i] = x[onum][i] * sizer;
			y[onum][i] = y[onum][i] * sizer; //enlarge if necessary
		}if (radius >= 300){
			x[onum][i] = x[onum][i] * sizer;
			y[onum][i] = y[onum][i] * sizer; //enlarge if necessary
		}else{
			x[onum][i] = x[onum][i] * .75; //resize to what we want
			y[onum][i] = y[onum][i] * .75; //which is .75
		}
	}

	for (i=0; i<numpoints[onum]; i++){
		x[onum][i] = x[onum][i] + 300; //bring it back to the center
		y[onum][i] = y[onum][i] + 300;
	}

	for(i=0; i< numpoints[onum]; i++){
		printf("index:%d x:%lf y:%lf\n",i,x[onum][i], y[onum][i]);
	}

}

void readObject(FILE *g, int onum){
	int k, i, count;
	fscanf(g, "%d", &numpoints[onum]); //file scanning using fscanf()

	for (k = 0; k < numpoints[onum]; k++){
		fscanf(g, "%lf %lf", &x[onum][k], &y[onum][k]); //scanning in the coordinates
	}
	printf("onum: %d\n", onum);
	for (k=0; k<numpoints[onum]; k++){
		printf("index:%d x:%lf  y:%lf\n",k, x[onum][k],y[onum][k]);
	}

	fscanf(g, "%d", &numpolys[onum]); //scanning the number of polygons
	printf("%d\n", numpolys[onum]);

	for (i = 0; i < numpolys[onum]; i++){  //getting the coordinates for the polygons
		fscanf(g, "%d", &psize[onum][i]); //number of the points in the polygon
		//printf("points: %d\n", psize[onum][i]);
		for (count = 0; count < psize[onum][i]; count++){
			fscanf(g, "%d", &con[onum][i][count]); //scanning in the coords of the polygon
		}
		/*printf("Polypoints:\n");
		for (count =0; count < psize[onum][i]; count++){
			printf("%d\n", con[onum][count][i]);
		}*/
	}

	for (i = 0; i < numpolys[onum]; i++){	//get the color values
		fscanf(g, "%lf %lf %lf", &red[onum][i], &grn[onum][i], &blu[onum][i]);
	}


}

int main(int argc, char **argv){
	int i, numobjects; FILE*g;

	if (argc == 1){
		printf("Usage: pgm_name file1.xy file2.xy.....\n"); //telling the user how to use the program then exiting
		exit(1);
	}

	numobjects = argc - 1;

	for(i=0; i < numobjects; i++){
		g = fopen(argv[i+1], "r");
		printf("got past step 1\n");
		if (g == NULL){
			printf("Can't open file %s\n", argv[i+1]);
			exit(1);
		}
		readObject(g,i);
		printf("read it in\n");
		scaleAndFitObject(i); 
		printf("scaled it\n");
	}

	int q, onum;
	G_init_graphics(600,600);
	
	while (0==0){
		q = G_wait_key();
	
		if (('0' <= q) && (q <= '9')){
			G_rgb(1,1,1);
			G_clear();
			onum=q-48;
			rotate(onum);
			printf("rotated it\n");
			display(onum);
			printf("displayed it, or tried to\n");
		}else if (q == 'q'){
			printf("done\n");
			exit(1);
		}
	}
}