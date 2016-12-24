#include <FPT.h>
int main()
{
  double a ;
  cout << "If I'm going to date you, I need to know how old you are. Input your age please.\n" ;
  cin >> a ;
  if ((a>=18) && (a<=24)){
    cout << "Oh good, we can have some fun.\n";
  }else if (a<18){
    cout << "Get away jailbait!\n" ;
  }else {
    cout << "Sorry, you're a bit too old for me\n" ;
  }

 
}
