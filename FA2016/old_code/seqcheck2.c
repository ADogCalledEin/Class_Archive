//Check to see if last value matches any other value
#include <FPT.h>
int main()
{
  int i,k;
  double x,v[1000],z,a,b,c,y;
  cout << "Input a number\n" ;
  cin >> x ;
  i=0;
  while (x>=0){
    v[i]=x;
    i=i+1;
    cout << "Put in some more numbers\n";
    cin >> x ;
  }
  i=i-1;
  a=0;
  k=0;
  while (k<i){
    v[i]=z;   
    if (x[k]==x[i]){
      a=1 ;
    }
    k=k+1;
  }
  if (a==1){
    cout << "Last Number matches a previous number\n" ;
  }else{
    cout << "Last Number does not match a previous number\n" ;
  }

}
