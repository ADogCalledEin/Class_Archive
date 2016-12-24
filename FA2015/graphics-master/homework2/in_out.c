#include <FPT.h>

int swidth, sheight ;

int click_and_save (double *x, double *y)
{
  int n ;
  double P[2] ;

  G_rgb(0,1,0.5) ;
  G_fill_rectangle(0,0,swidth,20) ;

  G_rgb(1,0,0) ;
  G_wait_click(P);

  n = 0 ;
  while (P[1] > 20) {
    x[n] = P[0] ;
    y[n] = P[1] ;
    G_circle(x[n],y[n],2) ;
    if (n > 0) { G_line(x[n-1],y[n-1], x[n],y[n]) ;}
    n++ ;
    G_wait_click(P) ;
  }

  return n ;
}



int in_out (double *x, double *y, int n, double P[2])
// return 1 if point P is inside the convex polygon
// else return 0
{
  int i,j,flag ;
  double Q[2],dx,dy,a,b,c,u,v ;

  // find center of mass of convex polygon (clipping window)
  Q[0] = Q[1] = 0 ;
  for (i = 0 ; i < n ; i++) {
    Q[0] += x[i] ;
    Q[1] += y[i] ;
  }
  Q[0] /= n ;  Q[1] /= n ;


  flag = 1 ; // initial belief of inside
  for (i = 0 ; i < n ; i++) {
    j = (i+1) % n ; //neat way to account for loopback

    // 0 = ax + by + c (computing equation of the infinite line)
    dx = x[j] - x[i] ; //run
    dy = y[j] - y[i] ; //rise
    a = dy ;
    b = -dx ;
    c = dx*y[i] - dy*x[i] ; //rise over run

    //Plugging p and q into the equation
    u = a*P[0] + b*P[1] + c ;
    v = a*Q[0] + b*Q[1] + c ;

    if (u*v < 0) { //if the value is larger than one, the point is on the wrong side of the line
      flag = 0 ; 
      break ; 
    }
  }

  return flag ;
}



int main()
{
  double xp[1000],yp[1000] ;
  int n,q ;
  double P[2] ;
  int f ;

  swidth = 700 ; sheight = 700 ;
  G_init_graphics(swidth, sheight) ;
  G_rgb(0,0,0) ;
  G_clear() ;

  G_rgb(1,0,0) ;
  n = click_and_save(xp,yp) ;
  G_rgb(0,1,0) ;
  G_fill_polygon(xp,yp,n) ;

  while (1) {

    G_wait_click(P) ;
    if (P[1] < 20) { break ; }
    G_rgb(0,0,1) ;
    G_fill_circle(P[0],P[1],2) ;

    f = in_out(xp,yp,n,P) ;
    if (f == 0) {
      G_rgb(1,1,0) ;
    } else {
      G_rgb(0,0,1) ;
    }

    G_fill_circle(P[0],P[1],4) ;

  }

}
