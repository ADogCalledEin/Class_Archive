#include <FPT.h>
int main()
{
  double x,y,a,b ;
  cout << "Please enter two whole numbers\n" ;
  cin >> a >> b ;
  cout << "\n" ;
  x=0;
  y=1;
  while (y<=fabs(a)){
    x=x+b ;
    y=y+1 ;
  }
  if (a<0){
    cout << -x << "\n" ;
  }else{
    cout << x << "\n";
  }

}
