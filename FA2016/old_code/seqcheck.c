//Check to see if first value matches any other value
#include <FPT.h>
int main()
{
  double a,b,c,x,y,z;
  cout << "Input the beginning of a sequence\n";
  cin >> b;
  x=0;
  c=0;
  while (x>=0){
    if (x==b){
      c=1;
    }
    cout << "Input more numbers\n" ;
    cin >> x ;
  }
  if (c==1){
    cout << "Sequence does have a repeating first value\n";
  }else if (c==0){
    cout << "Sequence does not have a repeating first value\n" ;
  }
}
