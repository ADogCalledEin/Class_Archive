#include <FPT.h>
int main()
{
  int i,k;
  double x,y[1000],b;
  i=0;
  cin >> x;
  while (x>=0){
    y[i]=x;
    i=i+1;
    cin >> x ;
  }
  i=i-1;
  k=0; b=0;
  while (k<i){
    if (y[k]==y[i]){
      b=1;
    }
    k=k+1;
  }
  if (b==1){
    cout << "Last one occured before.\n";
  }else{
    cout << "Last one did not occur before.\n";
  }

}
