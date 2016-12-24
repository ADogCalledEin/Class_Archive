#include <FPT.h>
int main()
{
  double n,a ;
  cout << "Input Number Please\n" ;
  cin >> n;
  a=floor(n);
  if (a<0){
    cout << "Negative\n" ;
  }else if (a==0){
    cout << "Zero\n" ;
  }else if (a==1){
    cout << "One\n" ;
  }else if (a==2){
    cout << "Two\n" ;
  }else if (a>=3){
    cout << "Big\n" ;
  }




}
