#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double h = 0.00001 ;

double deriv (double (*func) (double x),     double x)
{
  return  (func(x + h) - func(x))/ h ;
}


double mycubic (double x)
{
  return x*x*x + 4*x*x + 3*x - 6 ;
}


int main()
{
  double v ;

  v = deriv(sqrt, 16) ;
  printf("%lf\n",v) ;

  v = deriv(sin, 4) ;
  printf("%lf\n",v) ;

  v = deriv(mycubic, 2) ;
  printf("%lf\n",v) ;
}
