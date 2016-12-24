#include <FPT.h>
int main()
{
  double a,b,c,x,y,z ;
  cout << "Enter in a value\n" ;
  cin >> x;
  a=0;
  b=x+1;
  c=0;
  while (b-a>0.000001){
    c=((b-a)/2)+a;
    y=(c*c);
      if (y<x){
	a=c;
      }else if (y>x){
	b=c ;
      }
  }
  cout << "Answer is " << c << "\n" ;
}
