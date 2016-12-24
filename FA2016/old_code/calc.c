#include <FPT.h>
int main()
{
  double a,b,c ;
  cout << "Type Any Number Your Mother Can Dream Of\n" ;
  cin >> a ;
  c=fabs(a);
  b=floor(fmod(c, 1000)/100) ;
  cout << b << "\n" ;



}
