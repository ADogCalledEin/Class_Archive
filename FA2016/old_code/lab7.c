//find the modes of the series
//number has to occur the most, and there can be ties
#include <FPT.h>
int main()
{
  int i,s,n,x;
  double f[101],m[101],b;
  cout << "Put in a score\n";
  cin >> n;
  i=0;
  while (i<=100){
    f[i]=0;
    i=i+1;
  }
  while (n>=0){ 
  f[n]=f[n]+1;
  cout << "Enter in more scores. To end enter in -1.\n";
  cin >> n;
  }
  s=100;
  b=0;
  while (s>=0){
    if (f[s]>b){
      b=f[s];
    }
    s=s-1;
  }
  s=100;
  while (s>=0){
    if (f[s]==b){
      cout << "A mode is " << s << "\n";
    }
    s=s-1;
  }
}
