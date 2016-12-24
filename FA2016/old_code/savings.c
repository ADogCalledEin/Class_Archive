//savings account, open with a grand, 12 percent per year
//compounded monthly, also adding $400 each month
//how much money will we have at the end of twenty years?
#include <FPT.h>
int main()
{
  double a,b,c,d,e,i ;
  cout << "Please put in how much you are starting with\n" ;
  cout << "$" ;
  cin >> a ;
  cout << "How many months are you keeping it in?\n" ;
  cin >> d ;
  cout << "Do you plan on adding any monthly amount? If so, how much? If none,enter a zero.\n" ;
  cin >> e ;
  cout << "What type of interest rate are we talking about per month?\n" ;
  cin >> i ;
  b=0 ;
  while (b<d){
    a=a+(a*i)+400 ;
    b=b+1 ;
    cout << "After " << b << " months, the total is " << "$" << a << "\n" ;
  }
  cout << "The total after that time is $" << a << "\n" ;
  // how much did the bank give me
  c= a-(d*400)-1000 ;
  cout << "The bank gave you $" << c << "\n" ;
}
