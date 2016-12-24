#include <stdio.h>
#include <math.h>


int main(){
	int number, count = 1, fact = 1;
	printf("Enter number:\n"); //entering in a number
	scanf("%d", &number);
	
	while (count <= number){
		fact = fact * count;
		count++;
	}

	printf("Factorial of %d is: %d\n", number, fact);

	return 0;
}