// prime numbers
#include <FPT.h>
int main()
{
  double a,b,x,y,z;
  cout << "Input a positive whole number\n";
  cin >> x ;
  a=0 ;
  b=0 ;
  y=x ;
  if (x==1){
    cout << "Not prime\n" ;
  }
  while (z>0){
    a=a+1 ;
    y=y-1 ;
    z=fmod(x,y) ;
  }
  if (a==(x-1)){
    cout << "Prime\n" ;
  }else if (a<(x-1)){
    cout << "Not prime\n" ;
  }

}
