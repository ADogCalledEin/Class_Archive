
#include <D2d_matrix.h>
#include <math.h>



/*

 ( x')          (x)
 ( y')  =   M * (y)  
 ( 1 )          (1)

instead of (x',y',1) = (x,y,1) * M  

*/

int D2d_mat_mult(double result[3][3], double a[3][3], double b[3][3]){
  int i,row, col;
  double temp[3][3], res =0;
  for (col=0; col<3; col++){
    for (row=0; row<3; row++){
      res =0;
      for (i =0; i<3; i++){
        res += a[row][i]*b[i][col];
      }
      temp[row][col]= res;
    }
  }
  D2d_copy_mat(result, temp);
  return 1;
}


int D2d_print_mat (double a[3][3])
{
  int r,c ;
  for (r = 0 ; r < 3 ; r++ ) {
      for (c = 0 ; c < 3 ; c++ ) {
           printf(" %12.4lf ",a[r][c]) ;
      }
      printf("\n") ;
  }

  return 1 ;
} 




int D2d_copy_mat (double a[3][3], double b[3][3])
// a = b
{
  int r,c ;
  for (r = 0 ; r < 3 ; r++ ) {
      for (c = 0 ; c < 3 ; c++ ) {
           a[r][c] = b[r][c] ;
      }
  }

  return 1 ;
} 

int D2d_scale (double a[3][3], double b[3][3], double sx, double sy){
  double scale[3][3];
  D2d_make_identity(scale);
  scale[0][0] = sx;
  scale[1][1] = sy;

  D2d_mat_mult(a, scale, a);

  //inverse
  scale[0][0] = 1/sx;
  scale[1][1] = 1/sy;

  D2d_mat_mult(b, b, scale);

  return 1;

}

int D2d_rotate (double a[3][3], double b[3][3], double radians){
	//set up the rotation arrays
  double rotate[3][3];
  D2d_make_identity(rotate);
  rotate[0][0] = cos(radians);
  rotate[0][1] = -sin(radians);
  rotate[1][0] = sin(radians);
  rotate[1][1] = cos(radians);
  rotate[2][2] = 1;

  D2d_mat_mult(a, rotate, a);

  //inverse
  rotate[0][0] = cos(-radians);
  rotate[0][1] = -sin(-radians);
  rotate[1][0] = sin(-radians);
  rotate[1][1] = cos(-radians);
  rotate[2][2] = 1;

  D2d_mat_mult(b,b,rotate);
  return 1;
}

int D2d_negate_x (double a[3][3], double b[3][3]){
  D2d_scale(a,b,-1,1);
  return 1;

}
int D2d_negate_y (double a[3][3], double b[3][3]){
	//essentially scaling over the x axis
  D2d_scale(a,b,1,-1);
  return 1;
}

int D2d_mat_mult_points (double *X, double *Y,
                         double m[3][3],
                         double *x, double *y, int numpoints){
  int i, col, row;
  double data[3][numpoints], temp[3][numpoints], res;

  double tempx, tempy;

  for(i=0; i<numpoints; i++){
    tempx = m[0][0]*x[i] + m[0][1]*y[i] + m[0][2]*1;
    tempy = m[1][0]*x[i] + m[1][1]*y[i] + m[1][2]*1;
    X[i]=tempx;
    Y[i]=tempy;
  }

  /*
  //setting up the main matrix for the multiplcation
  for(i=0; i<numpoints; i++){   
  	data[0][i]=x[i];
  }
  for(i=0; i<numpoints; i++){
  	data[1][i]=y[i];
  }
  for(i=0; i<numpoints; i++){
  	data[2][i]=1;
  }
  //adapting mat_mult for being dynamic
  for (col=0; col<numpoints; col++){
    for (row=0; row<3; row++){
      res = 0;
      for (i =0; i<numpoints; i++){
        res += m[row][i]*data[i][col];
      }
      temp[row][col]= res;
    }
  }
  //shoving the results into their respective arrays
  for(i=0; i<numpoints; i++){
  	X[i] = temp[0][i];
  }
  for(i=0; i<numpoints; i++){
  	Y[i] = temp[1][i];
  }*/
}
// |X0 X1 X2 ...|       |x0 x1 x2 ...|
// |Y0 Y1 Y2 ...| = m * |y0 y1 y2 ...|
// | 1  1  1 ...|       | 1  1  1 ...|

// SAFE, user may make a call like D2d_mat_mult_points (x,y, m, x,y, n) ;



int D2d_make_identity (double a[3][3])
// a = I
{
  int r,c ;
  for (r = 0 ; r < 3 ; r++ ) {
      for (c = 0 ; c < 3 ; c++ ) {
           if (r == c) a[r][c] = 1.0 ;
               else    a[r][c] = 0.0 ;
      }
  }

  return 1 ;
} 






/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


int D2d_translate (double a[3][3], double b[3][3], double dx, double dy)
// a = translation*a  
// b = b*translation_inverse  
{
  double t[3][3] ;

  D2d_make_identity(t) ;

  t[0][2] =  dx ;  t[1][2] = dy ;  
  D2d_mat_mult(a,  t,a) ;

  t[0][2] = -dx ;  t[1][2] = -dy ;
  D2d_mat_mult(b,  b,t) ;

  return 1 ;
}