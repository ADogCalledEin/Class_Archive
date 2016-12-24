#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  char w[100] ;
  int n ;
  FILE *g ;
  char fname[100] ;

  printf("what is the name of the file you wish to read? ") ;
  scanf("%s", fname) ;

  g = fopen(fname, "r") ;
  if (g == NULL) {
    printf("can't open file\n") ;
    exit(1) ;
  }



  while (0 == 0) {
    n = fscanf(g, "%s",w) ;
    if (n != 1) { break ; }
    printf("%s  %d\n",w,n) ;
  }


}
