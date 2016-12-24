#include <stdio.h>
#include <math.h>



int fac(int n){ //takes one argument
	int fact=1, count;
	for (count = 1; count <= n; count++){ //actual factorial function
		fact = fact * count;
	}
	
	return fact; //returns the factorial of the input
}

int choose(int n, int k){ //two inputs
	int a,b,c,r;
	a = fac(n); //factorial of the first input
	b = fac(k); //factorial of the second input
	c = fac(n-k); //factorial of the comp
	r = a/(b*c);
	return r;

}


int main(){
	int jf,ji,j,sf,si,s;
	scanf("%d %d", &jf, &ji);
	scanf("%d %d", &sf, &si);

	j = choose(jf,ji);
	s = choose(sf,si);

	printf("%d %d\n", j, s);
	if (j>s){ printf("jeff\n");}
	if (s>j){ printf("sally\n");}
	else {printf("tie\n");}

	return 0;
}