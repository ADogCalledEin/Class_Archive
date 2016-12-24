//equation for pi
#include <FPT.h>
int main()
{
  double a,b,c,x,y,z,n ;
  cout << "Input an odd whole number\n" ;
  cin >> n ;
  a=2+(n*n);
  while (n>3){
    n=n-2;
    a=2+((n*n)/a);
  }
  z=4/(1+1/a);
  cout << z << "\n";





}
