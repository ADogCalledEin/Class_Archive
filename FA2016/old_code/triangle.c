#include <FPT.h>
int main()
{
  double n,l,w,x,y,z;
  cout << "Input the number of triangles\n";
  cin >> n ;
  cout << "How long is the length of the triangle?\n";
  cin >> l ;
  cout << "Whats the width?\n" ;
  cin >> w ;
  cout << "\n" ;
  x=0;
  y=0;
  z=0;
    while (x<n){
      x=x+1;
      y=y+(l*w)/2 ;
      l=sqrt((w*w)+(l*l));
     
    }
 cout << "The area is " <<  y << "\n" ;
}
