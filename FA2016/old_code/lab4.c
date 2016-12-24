#include <FPT.h>
int main()
{
  double a,b,c,x,y,z,gcd,lcm ;
  cout << "Please enter two variables\n" ;
  cout << "x=";
  cin >> x ;
  cout << "y=" ;
  cin >> y ;
  a=x;
  b=y;
  while (b!=0){
    z=b ;
    b=fmod(a,b) ;
    a=z ;
  }
  gcd=a;
  lcm=(x*y)/gcd;

  cout <<"The Least Common Multiple of " << x << " and " << y << " is " << lcm << "\n" ;




}
