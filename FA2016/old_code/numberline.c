#include <FPT.h>
int main()
{
  double n ;
  cout << "Input Number Please\n" ;
  cin >> n ;
  if (n<0){
    cout << "Negative\n" ;
  }else if (n>=0 && n<1){
    cout << "Zero\n" ;
  }else if (n>=1 && n<2){
    cout << "One\n" ;
  }else if (n>=2 && n<3){
    cout << "Two\n" ;
  }else if (n>=3){
    cout << "Big\n" ;
  }


}
