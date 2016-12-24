#include<FPT.h>


//three arguements on the command line
//argc has three arguements
int main (int argc, char **argv){
	int i, k, numchars;
	numchars =0;
	for (i=0;i<argc; i++){
		k=0;
		while (argv[i][k] != '\0'){
			k++;
			printf("%c\n", argv[i][k]);
		}
		printf("numchars = %d\n", k);
		numchars += k;
	}
	printf("numchars = %d\n", numchars);

}