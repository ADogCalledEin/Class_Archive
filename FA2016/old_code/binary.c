//enter a whole number, spit out binary form
#include <FPT.h>
int main()
{
  int i;
  double n,r, m[1000];
  cout << "Enter in a positive whole number\n";
  cin >> n;
  i=0;
  if (n==0){
    cout << "0";
  }
  while ((n/2)>0){
    r=fmod(n,2);
    m[i]=r;
    i=i+1;
    n=floor(n/2);
  }
  i=i-1;
  while (i>=0){
    cout << m[i];
    i=i-1;
  }
  cout << "\n";
}
