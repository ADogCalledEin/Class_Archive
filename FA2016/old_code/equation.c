#include <FPT.h>
int main ()
{
  double b,c,x;
  cout << "Enter variable b\n" ;
  cin >> b ;
  cout << "Enter variable c\n" ;
  cin >> c ;
  x=(-c)/b ;
  if (b == 0){
    cout << "Nothing Works\n" ;
  }else if (b == 0 && c == 0){
    cout << "Anything Works\n" ;
  }else{
    cout << "Answer is " << x << "\n" ;
  }
}
