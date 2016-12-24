//compute y=x^n, where x is any number and n is any whole number
#include <FPT.h>
int main()
{
  double x1,x,x2,n,a;
  cout<< "Enter a whole number\n" ;
  cin >> x ;
  cout << "Input the exponent (must be a whole number)\n" ;
  cin >> n ;
  if (x==0 && n==0){
    cout << "Does not exist\n" ;
  }else if (x==0 && n<0){
    cout << "Answer does not exist\n" ;
  }else  if (x==0){
    cout << "Answer is 0\n" ;
  }else if (n==0){
    cout << "Answer is 1\n" ;
  }else if (x>0 && n>0){
    a=1 ;
    x2=x ;
    while (a<n){
      a=a+1 ;
      x1=x2*x ;
      x=x1 ;
    }
    cout << "Answer is " <<  x1 << "\n" ;
  }else if (x<0 && n<0){
    a=1 ;
    x2=(1/x) ;
    while (a<(abs(n))){
      x1=(1/x)*x2 ;
    x2=x1 ;
    a=a+1 ;
  }
    cout << "Answer is " << x1 << "\n" ;

  }else if (x<0){
    a=1 ;
    x2= abs(x);
    while (a<n){
      a=a+1 ;
      x1=x2*x ;
      x=x1 ;
    }
    cout << "Answer is " << x1 << "\n" ;
  }else if(n<0){
    a=1 ;
    x2=(1/x) ;
    while (a<(abs(n))){
      x1=(1/x)*x2 ;
    x2=x1 ;
    a=a+1 ;
  }
    cout << "Answer is " << x1 << "\n" ;
  }
}
