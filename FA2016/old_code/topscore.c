//Top score
#include <FPT.h>
int main()
{
  double x,n,p,r;
  cout << "Enter in a score\n" ;
  cin >> x ;
  p=x; n=x;
  while (x>=0){
    if (x>p){
      p=x;
    }else if (x<n){
      n=x;
    }
    cout << "Enter in more scores. To end type -1.\n" ;
    cin >> x ; 
  }
  r=p-n;
  cout << "Top score is " << p << "\n";
  cout << "Lowest score is " << n << "\n";
  cout << "Range is " << r << "\n" ;

}
