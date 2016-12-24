#include <FPT.h>
#include <stdio.h>
#include <math.h>


void sort (double x[100], int m){
	int k, s, i;
	double temp;

	for (i=0; i<m; i++){	
		s=i;
		for (k=i+1; k<m; k++){
			if(x[k] > x[s]){
			s = k;
			} //finding which one is the smallest
		}
		temp = x[i]; x[i]=x[s]; x[s]=temp;  //swapping the smallest into the correct spot
	}
}

void printarray(double w[100], int z){
	int i;
	printf("\n");
	for (i=0; i< z; i++){
		printf("%d : %lf\n", i, w[i]);
	}

}
int main(){
	double u[100], v[100];

	u[0]=89;
	u[1]=93;
	u[2]=12;
	u[3]=17;

	sort(u, 4);
	printarray(u,4);

	v[0]=81;
	v[1]=13;
	v[2]=47;

	sort(v, 4);
	printarray(v,4);

	return 0;
}