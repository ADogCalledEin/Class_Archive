#include <FPT.h>
int main ()
{
  double x,x1,x2,p,n;
  p=0;
  cout << "Put in a grade.\n" ;
  cin >> x ;
  x1=0;
  while (x>=0){
    p=p+1 ;
    x2=x1+x;
    cout << "Enter more grades. To end program enter -1.\n";
    cin >> x ;
    x1=x2;
  }
  if (p==0){
    cout << "No data\n" ;
  }else{
  n=(x2/p);
  cout << "The class average is " << n << "\n" ;
  }
}
