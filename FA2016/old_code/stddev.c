#include <FPT.h>
int main()
{
  //standard deviation
  int a,k;
  double b,c,x,y,z,data[10000],std,x1,x2,d;
  cout << "Type the beginning of a sequence.\n";
  cin >> x;
  a=0;
  x1=0;
  while (x>=0){
    a=a+1;
    data[a]=x;
    x2=x1+x;
    cout << "Enter in more numbers. To end program enter -1.\n";
    cin >> x;
    x1=x2;
  }
  if (a==0){
    cout << "No data.\n";
  }else{
    k=0;
    b=x2/a;
    y=0;
    cout << "The class average is " << b << "\n" ;
    while (k<a){
      k=k+1;
      d=data[k]-b;
      y=y+(d*d);
    }
    std=sqrt(y/a);
    cout << "Standard deviation is " << std << "\n";

  }


}
