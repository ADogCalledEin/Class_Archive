//Check to see if sequence is increasing
#include <FPT.h>
int main()
{
  double a,b,c,x,y,z;
  cout << "Input the beginning of a sequence\n";
  cin >> a;
  cin >> b;
  c=0;
  while (b>=0){
    if (b<=a){
      c=1;
    }
    a=b ;
    cin >>b ;
  }
  if (c==1){
    cout << "Sequence is not increasing\n";
  }else{
    cout << "Sequence is increasing\n" ;
  }
}
