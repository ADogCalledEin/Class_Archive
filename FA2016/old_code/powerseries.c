#include <FPT.h>
int main ()
{
  double n,s,i ;
  cout << "Enter a number to find the series answer\n" ;
  cin >> n ;
  i=1 ;
  s=0 ;
  while (i<=n){
    if (fmod(i,2)==0){
      s=s-(i*i*i) ;
    }else{
      s=s+(i*i*i) ;
    }
    i=i+1 ;
    cout << s << "\n" ;
  }

}
