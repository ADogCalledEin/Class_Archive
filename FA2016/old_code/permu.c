//factorial
#include <FPT.h>
int main()
{
  double a,b,c ;
  cout << "Please Enter a Number to find the factorial\n" ;
  cin >> a ;
  cout << "\n" ;
  if (a==0){
    cout << "The factorial of 0 is 0.\n\n" ; 
  }else if (a<0){
      cout <<  "Factorial cannot work on negative numbers.\n\n";
    }else{
  b=1 ;
  c=2 ;
  //starting from the bottom instead of the top seems to work
    while (c<=a){
     b=b*c;
     c=c+1;
     cout << b << "\n";
   }
  cout << "The factorial of " << a << " is " << b << "\n" ;
 }
}
