
#include <FPT.h>




double intersection(double ax, double ay, double ax2, double ay2,
                    double bx, double by, double bx2, double by2){
  double m1 = (ay2 - ay)/(ax2 - ax);
  double m2 = (by2 - by)/(bx2 - bx);

  double x = ((m1*ax) - (m2*ax2) - ay + by)/(m1 * m2);
  printf("%lf\n", x);



}

int Clip_Polygon_Against_Convex_Window(double *px, double *py, int pn,
                                       double *wx, double *wy, int wn){
  int i,j,j2,t;
  double mass[2],dx,dy,a,b,c,u,v,gx,gy;

  mass[0] = mass[1] = 0;
  for (i=0;i<wn; i++){
    //find center of mass of convex polygon (clipping window)
    mass[0] += px[i];
    mass[1] += py[i];
  }

  mass[0] /= wn; mass[1] /= wn;

  for(t=0; t < wn; t++){
  int in = 1 ; // initial belief of inside
    for (i = 0 ; i < pn ; i++) {
      j = (i+1) % wn ; //neat way to account for loopback
 
      // 0 = ax + by + c (computing equation of the infinite line)
      dx = wx[j] - wx[i] ; //run
      dy = wy[j] - wy[i] ; //rise
      a = dy ;
      b = -dx ;
      c = dx*wy[i] - dy*wx[i] ; //rise over run
 
      //Plugging p and q into the equation
      u = a*px[0] + b*py[i] + c ; //point being tested
      v = a*mass[0] + b*mass[1] + c ; //center
 
      if (u*v < 0) { //if the value is larger than one, the point is on the wrong side of the line
        in = 0 ; 
        break ; 
      }
    }

    if (in == 0){
      intersection(wx[t],wy[t],wx[t+1],wy[t+1], //finding the intersection of the lines
                   px[t],py[t],px[t+1],py[t+1]);  
      
    }
  }







  return pn;
}


int main()
// this tests clipping of polygon to convex window
{
  int pn, wn ;
  double pt[2],u,v,q ;

  double px[100] = {  70,460,400} ;
  double py[100] = { 350, 25,550} ;
  pn = 3 ;

  double wx[100] = { 100,600,550,150} ;
  double wy[100] = { 150,200,450,500} ;
  wn = 4 ;

  srand48(100) ;

  G_init_graphics (700, 700) ;
  G_rgb (0,0,0) ;
  G_clear() ;

  G_rgb (1,0,0) ;
  G_polygon(wx,wy,wn) ;

  G_rgb (0,0,1) ;
  G_polygon(px,py,pn) ;


  q = G_wait_key() ;


  pn =  Clip_Polygon_Against_Convex_Window (px, py, pn,
                                            wx, wy, wn) ;  

  G_rgb (1,1,0) ;
  G_fill_polygon(px,py,pn) ;
  q = G_wait_key() ;
}




