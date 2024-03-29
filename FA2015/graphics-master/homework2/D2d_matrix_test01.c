#include <D2d_matrix.h>

double q[3][3] = { { 2.0,  3.0,  4.0},
                   {-5.0,  7.0, -8.0},
                   { 1.5, -2.5,  8.5} } ;

double r[3][3] = { { 5.5,  1.5,  6.0},
                   {-3.5,  4.5, -2.5},
                   { 4.0,  3.5,  1.5} } ;


int main()
{
  double p[3][3], pinv[3][3], v[3][3] ;

  printf("\n") ;

  D2d_make_identity(p) ;
  printf("p = \n") ;
  D2d_print_mat(p) ;
  printf("+++++++++++++++++++++++++++++++++++++++++\n") ;

  D2d_copy_mat (p,q) ;
  printf("p = \n") ;
  D2d_print_mat(p) ;
  printf("+++++++++++++++++++++++++++++++++++++++++\n") ;

  D2d_mat_mult (p,q,r) ;
  printf("p = \n") ;
  D2d_print_mat(p) ;
  printf("+++++++++++++++++++++++++++++++++++++++++\n") ;


  D2d_make_identity(p) ;
  D2d_make_identity(pinv) ;
  D2d_scale(p,pinv, 2.0, 0.5) ;
  D2d_rotate(p,pinv, M_PI/2) ;
  D2d_translate(p,pinv, 100, 50) ;
  D2d_negate_x(p,pinv) ;
  D2d_negate_y(p,pinv) ;
  printf("p = \n") ;
  D2d_print_mat(p) ;
  printf("-----------------------------------------\n") ;
  printf("pinv = \n") ;
  D2d_print_mat(pinv) ;
  printf("+++++++++++++++++++++++++++++++++++++++++\n") ;


  D2d_mat_mult (v,  p,pinv) ;
  printf("p*pinv = \n") ;
  D2d_print_mat(v) ;
  printf("+++++++++++++++++++++++++++++++++++++++++\n") ;


  

  // space for a quadrilateral
  double Ax[4], Ay[4] ;
  // space for another quadrilateral
  double Bx[4], By[4] ;
  // space for yet another quadrilateral
  double Cx[4], Cy[4] ;


  Ax[0] = 0 ; Ax[1] = 10 ; Ax[2] = 30 ; Ax[3] =  0 ;
  Ay[0] = 0 ; Ay[1] =  0 ; Ay[2] = 40 ; Ay[3] = 20 ;

  D2d_mat_mult_points (Bx,By,   p,      Ax,Ay,4) ; // B = p*A
  D2d_mat_mult_points (Cx,Cy,   pinv,   Bx,By,4) ; // C = pinv*B

  printf("The four A points are :\n") ;
  printf("%12.4lf %12.4lf %12.4lf %12.4lf\n",Ax[0],Ax[1],Ax[2],Ax[3]) ;
  printf("%12.4lf %12.4lf %12.4lf %12.4lf\n",Ay[0],Ay[1],Ay[2],Ay[3]) ;

  printf("The four B points are :\n") ;
  printf("%12.4lf %12.4lf %12.4lf %12.4lf\n",Bx[0],Bx[1],Bx[2],Bx[3]) ;
  printf("%12.4lf %12.4lf %12.4lf %12.4lf\n",By[0],By[1],By[2],By[3]) ;

  printf("The four C points are :\n") ;
  printf("%12.4lf %12.4lf %12.4lf %12.4lf\n",Cx[0],Cx[1],Cx[2],Cx[3]) ;
  printf("%12.4lf %12.4lf %12.4lf %12.4lf\n",Cy[0],Cy[1],Cy[2],Cy[3]) ;


}

