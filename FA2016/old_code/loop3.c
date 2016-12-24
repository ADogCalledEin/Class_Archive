#include <FPT.h>
int main()
{
  // Subtraction
  double a,b,q ;
  cout << "Please input a number you want to be divided\n" ;
  cin >> a ;
  cout << "\n" ;
  cout << "Now input the number you want to divide by\n" ;
  cin >> b ;
  cout << "\n" ;
  while (a>=b){
    a=a-b ;
    q=q+1 ;
  }
  cout << "The Remainder is " << a << "\n" ;
  cout << "The Quotient is " << q << "\n" ;
}
