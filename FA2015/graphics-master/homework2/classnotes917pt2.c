#include <FPT.h>

	int numpoints[10], numpolys[10];
	double x[10][12000], y[10][12000]; //array for each object
	int psize[10][8000];
	int con[10][8000];
	int numobjects;

	double red[10][8000];
	double grn[10][8000];
	double blu[10][8000];



void rotate(){

}

void display(){

}

void scaleAndFitObject(){
	
}


void readObject(GFILE*g, int onum){
	int k;
	fscanf(g, "%d", &numpoints[onum]); //file scanning using fscanf()

	for (k = 0; k < numpoints[onum]; ++k){
		fscanf(g, "%lf %lf", &x[onum][k], &y[onum][k]);
	}

	fscanf(g, "%d", &numpolys[onum])

	for (int i = 0; i < count; ++i){
		/* code */
	}


}

int main(int argc, char **argv){
	int i, numobjects; FILE*g;

	if (argc == 1){
		printf("Usage: pgm_name file1.xy file2.xy.....\n"); //telling the user how to use the program then exiting
		exit(1);
	}

	numobjects = argc -1;

	for(i=1; i< argc; i++){
		g =fopen(argv[i], "r");
		if (g == NULL){
			printf("Can't open file %s\n", argv[i+1]);
			exit(1);
		}
		readObject(g,i);
		scaleAndFitObject(i); //we have to write that
	}

	int q, onum;
	G_init_graphics(600,600);
	
	while (0==0){
		q = G_wait_key();
	
		if (("0" <= q) && (q <= "9")){
			onum=q-48;
			rotate(q);
			display(q);
		}else if (q == "q"){
			exit(1);
		}
	}
}