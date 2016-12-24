//Problem 3 on the sheet
#include <FPT.h>
int main()
{
  int i,s;
  double n, v[1000],x,t,m;
  cout << "Enter in the beginning of a sequence\n";
  cin >> n;
  i=0;
  while (n>=0){
    v[i]=n;
    i=i+1;
    cout << "Enter in more numbers in the sequence\n";
    cin >> n;
  }
  x=ceil(i/2);
  s=0; t=0;
  while (s<x){
    t=v[s]+t;
    s=s+1;
  }
  s=ceil(i/2);
  while (s<i){
    m=v[s]+m;
    s=s+1;
  }
  if (m==t){
    cout << "Both halves of the sequence are equal with the answer " << t << "\n";
}else if (m<t){
    cout << "The first half of the sequence is greater, with the answer " << t <<"\n";
  }else if (m>t){
    cout << "The second half of the sequence is greater, with the answer " << m << "\n";
  }
}
