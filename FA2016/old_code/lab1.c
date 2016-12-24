//solve ax^2+bx+c=0 for x
#include <FPT.h>
int main()
{
  double a,b,c,x1,x2,d,rd,gd,u ;
  cout << "Input a, b, and c\n" ;
  cin >> a >> b >> c ;
  if(a == 0 && b == 0 && c == 0){
    cout << "Anything Works\n" ;
  }else if (a == 0 && b == 0) {
    cout << "Nothing Works\n" ;
  }else if (a == 0){
    x1=(-c)/b ;
    cout << "Result: " <<  x1 << "\n" ;
  }else if(b*b-4*a*c<0) {
    d=(b*b-4*a*c) ;
    rd= sqrt(fabs(d)) ;
    gd=rd/(2*a);
    u= -b/(2*a);
     cout << u << "+" << gd << "i" << " , " << u << "-" << gd << "i\n" ;
  }else{
    x1=(-b + sqrt(b*b-4*a*c))/(2*a) ;
    x2=(-b - sqrt(b*b-4*a*c))/(2*a) ;
    cout << "Results: " <<  x1 << "," <<  x2 << "\n" ;
  }
}
