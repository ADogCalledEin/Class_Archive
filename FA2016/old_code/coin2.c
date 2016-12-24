#include <FPT.h>
int main()
{
  double p,d,q,i,n ;
  cout << "Input Number of Pennies: " ;
  cin >> p;
  d=floor(p/100);
  cout << "Dollars: " << d << "\n" ;
  p=fmod(p, 100);
    q=floor(p/25);
    cout << "Quarters: " << q << "\n" ;
    p=fmod(p, 25);
    i=floor(p/10);
    cout << "Dimes: " << i << "\n" ;
    p=fmod(p, 10);
    n=floor(p/5);
    cout << "Nickels: " << n << "\n" ;
    p=fmod(p, 5);
    cout << "Cents: " << p << "\n";






}
