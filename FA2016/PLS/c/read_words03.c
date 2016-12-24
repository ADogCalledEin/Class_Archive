#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv)
{
  char w[100] ;
  int n ;
  FILE *g ;

  g = fopen(argv[1], "r") ;
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
