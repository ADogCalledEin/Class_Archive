#include <FPT.h>
#include <stdio.h>
#include <math.h>


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

void sort (double x[100], int m){
	int k, s, i;
	double temp;

	for (i=0; i<m; i++){	
		s=i;
		for (k=i+1; k<m; k++){
			if(x[k] < x[s]){ s = k;} //finding which one is the smallest
		}
		temp = x[i]; x[i]=x[s]; x[s]=temp;  //swapping the smallest into the correct spot
	}
}

void printarray(double w[100], int z){
	int i;
	printf("\n");
	for (i=0; i< z; i++){
		printf("%d:%lf\n", i, w[i]);
	}

}

void myFillPolygon(double *x, double *y, int n, double height){
	int i, interlength, checkme, printChecker;
	double scan;
	double intx[1000], value;

	for (scan=0.1; scan<height; scan++){
		interlength = 0;
		for(i=0; i<n; i++){
			checkme=0;
			if (i == (n-1)){
				if ((y[i] <= scan && y[0] >= scan) || (y[i] >= scan && y[0] <= scan)) { //attempting to account for loopback
					checkme=1;
				}
				else{ 			
					checkme=0;
				}
			}else{
				if ((y[i] <= scan && y[i+1] >= scan) || (y[i] >= scan && y[i+1] <= scan)){ //check if there is an intersection with the scan line
					checkme=1;
				}
				else{ 			//else move on
					checkme=0;
				}
			}	
			if (checkme==1){

				if(i == (n-1)){
					value = x[i] + ((x[0]-x[i])/(y[0]-y[i]))*(scan-y[i]);

				}else{
					value = x[i] + ((x[i+1]-x[i])/(y[i+1]-y[i]))*(scan-y[i]);

				}
				intx[interlength]=value;		//save X where the lines intersect if they do
				interlength++;	//bump up length of the saved points array
			}	
		}
		sort(intx, interlength); //sort the saved values according to lowest x value

		for(i=0; i<(interlength-1); i=i+2){	//drawing it
			G_rgb(1,0,0);
			G_line(intx[i], scan, intx[i+1], scan);

		}
	}
}

int main(){

	double ax[100], ay[100];
  	int anum, gwidth, gheight;
  	gwidth=600;
  	gheight=600;
  	G_init_graphics(gwidth, gheight);
  	G_rgb(1,0,0);
  	G_fill_rectangle(0,0, 20, 20);
	
	anum = clickAndSave(ax, ay);
	G_rgb(0,0,0);
	G_polygon(ax, ay, anum);
	myFillPolygon(ax,ay,anum, gheight);
	G_wait_key();
	
	

	return 0;
}