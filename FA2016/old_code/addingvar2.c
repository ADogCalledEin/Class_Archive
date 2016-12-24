#include <FPT.h>
int main()
{
  double n,s,i;
  cout << "enter a positive whole number\n";
  cin >> n ;
  s=0 ;
  while (n>0){
    s=s+n ;
    n=n-1;
    cout << s << "\n" ;
  }



}
