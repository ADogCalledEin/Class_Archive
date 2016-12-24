//Entering in scores to see if there are more odds than evens
#include <FPT.h>
int main()
{
  double a,b,c,x,y,z;
  cout << "Enter in a score\n" ;
  cin >> x ;
  a=0;
  b=0;
  if (floor(x)==x){
   while (x>=0){
    y=fmod(x,2);
    if (y==0){
      a=a+1;
    }else if (y!=0){
      b=b+1;
    }
    cout << "Enter more scores. To end enter -1.\n" ;
    cin >> x ;
   }
  }else{
    cout << "No decimals\n" ; 
  }
  if (a>b){
    cout << "There are more even scores than odds.\n" ;
  }else if (b>a){
    cout << "There are more odd scores than evens.\n";
  }else if (a==b){
    cout << "There are equal numbers of odds and evens.\n" ;
  }

}
