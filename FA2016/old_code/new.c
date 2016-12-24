#include <FPT.h>
int main()
{
  double x ;
  cout << "Please Type A Number" ;
  cin >> x ;
  x=fmod(floor(fabs(x/100)), 10) ;
  cout << x << "\n" ;




}
