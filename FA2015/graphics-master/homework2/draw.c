#include <FPT.h>


int main(){
	int numpoints, i, numpolys, numsides,sidecount, index;
	double x[1000], y[1000];
	double polyx[20], polyy[20];


	scanf("%d", &numpoints);
	for (i=0; i< numpoints; i++){ //scan in the points for the polygon
		scanf("%lf %lf", &x[i], &y[i]);
	
	}
	scanf("%d", &numpolys);	//get the number of polygons
	G_init_graphics(1000, 1000);
	//G_polygon(x, y, numpoints); //draw whats in the array

	for (i=0; i< numpolys; i++){	
		numsides = 0;		
		scanf("%d", &numsides); //get the number of sides
		for (sidecount=0; sidecount<numsides; sidecount++){
			scanf("%d", &index);	//scan in the index of the coordinate
			polyx[sidecount] = x[index]; 
			polyy[sidecount] = y[index];
		}
		G_rgb(drand48(), drand48(), drand48());
		G_fill_polygon(polyx, polyy, sidecount); //draw the specified shape
		sidecount=0; //reset the sidecount for the next specified shape
	}

	G_wait_key();
	return 0;
}