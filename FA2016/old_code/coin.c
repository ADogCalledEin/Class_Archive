#include <FPT.h>
int main()
{
  double p,d,q,i,n,e ;
  cout << "Please Enter Number of Pennies: " ;
  cin >> p ;
  d=floor(p/100);
  q=floor((p-(d*100))/25) ;
  i=floor((p-(d*100)-(q*25))/10);
  n=floor((p-(d*100)-(q*25)-(i*10))/5);
  e=floor((p-(d*100)-(q*25)-(i*10)-(n*5))/1);


  cout << "Dollars: " << d << "\n";
	  cout << "Quarters: " << q << "\n" ;
	  cout << "Dimes: " << i << "\n" ;
	  cout << "Nickels: " << n << "\n" ;
	  cout << "Pennies: " << e << "\n" ;
}
