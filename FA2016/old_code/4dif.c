#include <FPT.h>
int main ()
{
  double a,b,c,d ;
  cout << "Please Input 4 Numbers\n" ;
  cin >> a >> b >> c >> d ;
  if ((a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d )){
    cout << "They are all Distinct\n" ;
  }else{
    cout << "They are not all Distinct\n" ;

  }


}
