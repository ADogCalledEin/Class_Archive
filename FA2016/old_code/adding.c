
#include <FPT.h>
int main()
{
  double a,b,c ;
  cout << "Please Enter a Number\n" ;
  cin >> a ;
  cout << "\n" ;
  if (a==0){
    cout << "Its zero.\n\n" ; 
  }else if (a<0){
      cout <<  "NO NEGATIVES!!\n\n";
    }else{
  b=0 ;
  c=1 ;
  //starting from the bottom instead of the top seems to work
    while (c<=a){
     b=b+c;
     c=c+1;
     cout << b << "\n";
   }
  cout << "The answer is " << b << "\n\n" ;
 }
}
