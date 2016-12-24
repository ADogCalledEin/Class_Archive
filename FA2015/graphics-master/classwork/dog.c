#include <stdio.h>
#include <math.h>

void dog(int a, int b){
	a = a + 1;
	b = b * 10;
	printf("%d %d\n", a, b);
}


void horse(int z[2]){
	z[0] = z[0] + 1;
	z[1] = z[1] * 10;
	printf("%d %d\n", z[0], z[1]);
}


int main(){
	int a, q, v[2];
	a=5; q=7;

	dog(a,q);

	printf("%d %d\n", a ,q);
	v[0]=5; v[1]=7;
	horse(v);
	printf("%d %d\n", v[0],v[1]);

	return 0;

}