#include <FPT.h>
int main ()
{
  double u,p,d,q,i,n,e,t,f ;
  cout << "US Dollars(1) or CA Dollars(2)? [Input the Number of Your Choice]\n" ;
  cin >> u ;
  if (u==1) {
    cout << "Please Enter Number of Pennies\n" ;
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
  } else {
    cout << "Please Enter Number of Pennies\n" ;
    cin >> p ;
            t=floor(p/200);
            d=floor((p-(t*200))/100);
	    f=floor((p-(t*200)-(d*100))/50) ;
	    q=floor((p-(t*200)-(d*100)-(f*50))/25) ;
	    i=floor((p-(t*200)-(d*100)-(f*50)-(q*25))/10);
	    n=floor((p-(t*200)-(d*100)-(f*50)-(q*25)-(i*10))/5);
	    e=floor((p-(t*200)-(d*100)-(f*50)-(q*25)-(i*10)-(n*5))/1);

	    cout << "Toonies: " << t << "\n" ;
	    cout << "Loonies: " << d << "\n" ;
	    cout << "50 Cent Pieces: " << f << "\n" ;
	    cout << "Quarters: " << q << "\n" ;
	    cout << "Dimes: " << i << "\n" ;
	    cout << "Nickels: " << n << "\n" ;
	    cout << "Pennies: " << e << "\n" ;
  }

}
