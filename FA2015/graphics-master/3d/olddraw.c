#include <FPT.h>
#include <stdlib.h>
#include <stdio.h>
#include <D3d_matrix.h>


	int numpoints[10], numpolys[10];
	double x[10][50000], y[10][50000], z[10][50000]; //array for each object
	int psize[10][15000];
	int con[10][15000][8000];
	int numobjects;
	double xcenter, ycenter. zcenter;

	double red[10][15000];
	double grn[10][15000];
	double blu[10][15000];

double max(double temp[10][50000], int size, int onum){ //generalized for finding the max of a shape
	int i;												//for the scaling
	double max = temp[onum][0];
	for (i=1; i<size; i++){	
		if(temp[onum][i] > max){
		max = temp[onum][i];
		}
	}
	return max;
}

double min(double temp[10][50000], int size, int onum){ //generalized for finding the min of a shape
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
	double m[4][4], minv[4][4];
	D3d_make_identity(m);
	D3d_make_identity(minv);

	int i;
  	double x1, y1;
  	D3d_translate(m,minv, -300,-300,-300);
  	D3d_rotate(m, minv, M_PI/40);
  	D3d_translate(m,minv,300,300,300);
  	D3d_mat_mult_points(x[onum], y[onum], z[onum], m , x[onum], y[onum], z[onum], numpoints[onum]);
  
}

void display(int onum){
	double tempx[10000], tempy[10000], tempz[10000];
	int f, j,i;
	int temp;
	for (f=0; f<numpolys[onum]; f++){
		for(j=0; j<psize[onum][f]; j++){
			temp = con[onum][f][j];
			tempx[j] = x[onum][temp]; 
			tempy[j] = y[onum][temp];
			tempz[j] = z[onum][temp];
		}

		G_rgb(red[onum][f], grn[onum][f], blu[onum][f]);
		G_fill_polygon(tempx, tempy, psize[onum][f]);

	}
}

void scaleAndFitObject(int onum){
	double m[4][4], minv[4][4];
	D3d_make_identity(m);
	D3d_make_identity(minv);

	int i;

	double xmax = max(x, numpoints[onum], onum); //finding the min and max of the shape
	double xmin = min(x, numpoints[onum], onum);
	double ymax = max(y, numpoints[onum], onum);
	double ymin = min(y, numpoints[onum], onum);
	double zmax = max(z, numpoints[onum], onum);
	double zmin = min(z, numpoints[onum], onum);

	xcenter = (xmin + xmax) / 2;	//finding the center
	ycenter = (ymin + ymax) / 2;
	zcenter = (zmin + zmax) / 2;

	D3d_translate(m, minv, -xcenter, -ycenter, -zcenter);

	double radius = (xmax-xmin) / 2; //finding the radius of the shape

	double resize = 150/radius; //to resize 

	D3d_scale(m, minv, resize, resize, resize);

	D3d_translate(m, minv, 300, 300, 300);
	D3d_mat_mult_points(x[onum], y[onum], z[onum], m, x[onum], y[onum], z[onum], numpoints[onum]);
	

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

int main(int argc, char **argv){

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
		scaleAndFitObject(i); 
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
			
			display(onum);
			
		}else if (q == 'q'){
			
			exit(1);
		}
	}
}