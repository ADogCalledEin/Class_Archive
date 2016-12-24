#include <FPT.h>


//three arguements on the command line
//argc has three arguements
int main (int argc, char **argv){
	int i, k, numchars;
	numchars =0;
	for (i=0;i<argc; i++){
		k=0;
		while (argv[i][k] != '\0'){
			k++;
		}
		printf("%s is %d characters long \n", argv[i], k);
		//strlen(argv[i]) does the same thing
	}

}