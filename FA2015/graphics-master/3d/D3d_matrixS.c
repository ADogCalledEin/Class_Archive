
#include <D3d_matrix.h>
#include <math.h>


int D3d_mat_mult(double result[4][4], double a[4][4], double b[4][4]){
  int i,row, col;
  double temp[4][4], res =0;
  for (col=0; col<4; col++){
    for (row=0; row<4; row++){
      res =0;
      for (i =0; i<4; i++){
        res += a[row][i]*b[i][col];
      }
      temp[row][col]= res;
    }
  }
  D3d_copy_mat(result, temp);
  return 1;
}


int D3d_print_mat (double a[4][4])
{
  int r,c ;
  for (r = 0 ; r < 4 ; r++ ) {
      for (c = 0 ; c < 4 ; c++ ) {
           printf(" %12.4lf ",a[r][c]) ;
      }
      printf("\n") ;
  }

  return 1 ;
} 




int D3d_copy_mat (double a[4][4], double b[4][4])
// a = b
{
  int r,c ;
  for (r = 0 ; r < 4 ; r++ ) {
      for (c = 0 ; c < 4 ; c++ ) {
           a[r][c] = b[r][c] ;
      }
  }

  return 1 ;
} 

int D3d_scale (double a[4][4], double b[4][4], double sx, double sy, double sz){
  double scale[4][4];
  D3d_make_identity(scale);
  scale[0][0] = sx;
  scale[1][1] = sy;
  scale[2][2] = sz;

  D3d_mat_mult(a, scale, a);

  //inverse
  scale[0][0] = 1/sx;
  scale[1][1] = 1/sy;
  scale[2][2] = 1/sz;

  D3d_mat_mult(b, b, scale);

  return 1;

}

int D3d_rotate_x(double a[4][4], double b[4][4], double radians){
  double rotate[4][4];
  D3d_make_identity(rotate);
  rotate[1][1] = cos(radians);
  rotate[1][2] = -sin(radians);
  rotate[2][1] = sin(radians);
  rotate[2][2] = cos(radians);

  D3d_mat_mult(a, rotate, a);
//inverse
  rotate[1][1] = cos(-radians);
  rotate[1][2] = -sin(-radians);
  rotate[2][1] = sin(-radians);
  rotate[2][2] = cos(-radians);

  D3d_mat_mult(b,b,rotate);
}

int D3d_rotate_y(double a[4][4], double b[4][4], double radians){
  double rotate[4][4];
  D3d_make_identity(rotate);
  rotate[0][0] = cos(radians);
  rotate[2][0] = -sin(radians);
  rotate[0][2] = sin(radians);
  rotate[2][2] = cos(radians);

  D3d_mat_mult(a, rotate, a);
//inverse
  rotate[0][0] = cos(-radians);
  rotate[2][0] = -sin(-radians);
  rotate[0][2] = sin(-radians);
  rotate[2][2] = cos(-radians);

  D3d_mat_mult(b,b,rotate);
}

int D3d_rotate_z(double a[4][4], double b[4][4], double radians){
  double rotate[4][4];
  D3d_make_identity(rotate);
  rotate[0][0] = cos(radians);
  rotate[0][1] = -sin(radians);
  rotate[1][0] = sin(radians);
  rotate[1][1] = cos(radians);

  D3d_mat_mult(a, rotate, a);
//inverse
  rotate[0][0] = cos(-radians);
  rotate[0][1] = -sin(-radians);
  rotate[1][0] = sin(-radians);
  rotate[1][1] = cos(-radians);

  D3d_mat_mult(b,b,rotate);
}

int D3d_cs_rotate_x (double a[4][4], double b[4][4], double cs, double sn){
  double rotate[4][4];
  D3d_make_identity(rotate);

  rotate[1][1] = cs;
  rotate[1][2] = -sn;
  rotate[2][1] = sn;
  rotate[2][2] = cs;

  D3d_mat_mult(a,rotate, a);
//inverse
  rotate[1][1] = 1/cs;
  rotate[1][2] = 1/-sn;
  rotate[2][1] = 1/sn;
  rotate[2][2] = 1/cs;

  D3d_mat_mult(b,b,rotate);

}



int D3d_cs_rotate_y (double a[4][4], double b[4][4], double cs, double sn){
  double rotate[4][4];
  D3d_make_identity(rotate);

  rotate[0][0] = cs;
  rotate[2][0] = -sn;
  rotate[0][2] = sn;
  rotate[2][2] = cs;

  D3d_mat_mult(a,rotate, a);
//inverse
  rotate[0][0] = 1/cs;
  rotate[2][0] = 1/-sn;
  rotate[0][2] = 1/sn;
  rotate[2][2] = 1/cs;

  D3d_mat_mult(b,b,rotate);
}

int D3d_cs_rotate_z (double a[4][4], double b[4][4], double cs, double sn){
  double rotate[4][4];
  D3d_make_identity(rotate);

  rotate[0][0] = cs;
  rotate[0][1] = -sn;
  rotate[1][0] = sn;
  rotate[1][1] = cs;

  D3d_mat_mult(a,rotate, a);
//inverse
  rotate[0][0] = 1/cs;
  rotate[0][1] = 1/-sn;
  rotate[1][0] = 1/sn;
  rotate[1][1] = 1/cs;

  D3d_mat_mult(b,b,rotate);
}

int D3d_negate_x (double a[4][4], double b[4][4]){
  D3d_scale(a,b,-1,1,1);
  return 1;

}
int D3d_negate_y (double a[4][4], double b[4][4]){
	//essentially scaling over the x axis
  D3d_scale(a,b,1,-1,1);
  return 1;
}

int D3d_negate_z (double a[4][4], double b[4][4]){
  //essentially scaling over the x axis
  D3d_scale(a,b,1,1,-1);
  return 1;
}

int D3d_mat_mult_points (double *X, double *Y, double *Z,
                         double m[4][4],
                         double *x, double *y, double *z, int numpoints){
  int i;

  double tempx, tempy, tempz;

  for(i=0; i<numpoints; i++){
    tempx = m[0][0]*x[i] + m[0][1]*y[i] + m[0][2]*z[i] + m[0][3]*1;
    tempy = m[1][0]*x[i] + m[1][1]*y[i] + m[1][2]*z[i] + m[1][3]*1;
    tempz = m[2][0]*x[i] + m[2][1]*y[i] + m[2][2]*z[i] + m[2][3]*1;
    X[i]=tempx;
    Y[i]=tempy;
    Z[i]=tempz;
  }
  return 1;
}
// |X0 X1 X2 ...|       |x0 x1 x2 ...|
// |Y0 Y1 Y2 ...| = m * |y0 y1 y2 ...|
// |Z0 Z1 Z2 ...|       |z0 z1 z2 ...|
// | 1  1  1 ...|       | 1  1  1 ...|

// SAFE, user may make a call like D3d_mat_mult_points (x,y,z, m, x,y,z, n) ;
int D3d_mat_mult_pt (double P[3],
                     double m[4][4],
                     double Q[3]){
  P[0] = m[0][0]*Q[0] + m[0][1]*Q[1] + m[0][2]*Q[2] + m[0][3]*1;
  P[1] = m[1][0]*Q[0] + m[1][1]*Q[1] + m[1][2]*Q[2] + m[1][3]*1;
  P[2] = m[2][0]*Q[0] + m[2][1]*Q[1] + m[2][2]*Q[2] + m[2][3]*1;

  return 1;
}
// multiplies a SINGLE point by a matrix
// | P[0] |       | Q[0] |
// | P[1] | = m * | Q[1] |
// | P[2] |       | Q[2] |
// |  1   |       |  1   |

// SAFE, user may make a call like 
// D3d_mat_mult_pt (q,  m,q) ;


int D3d_make_identity (double a[4][4])
// a = I
{
  int r,c ;
  for (r = 0 ; r < 4 ; r++ ) {
      for (c = 0 ; c < 4 ; c++ ) {
           if (r == c) a[r][c] = 1.0 ;
               else    a[r][c] = 0.0 ;
      }
  }

  return 1 ;
} 

int D3d_x_product (double res[3], double a[3], double b[3]){
  res[0] = (a[1]*b[2]) - (b[1]*a[2]);
  res[1] = -((a[0]*b[2]) - (b[0]*a[2]));
  res[2] = (a[0]*b[1]) - (b[0]*a[1]);

  return 1;
}

double D3d_dot_product(double a[3], double b[3]){
  double res = (a[0]*b[0]) + (a[1]*b[1]) + (a[2]*b[2]);

  return res;
}

int D3d_vec_scalar(double a[3], double res[3], double num){
  res[0] = a[0]*num;
  res[1] = a[1]*num;
  res[2] = a[2]*num;

  return 1;
}

int D3d_vec_subtract(double a[3], double b[3], double res[3]){
  res[0]=a[0]-b[0];
  res[1]=a[1]-b[1];
  res[2]=a[2]-b[2];

  return 1;
}

int D3d_view (double view[4][4],  double view_inverse[4][4],
              double eye_x, double eye_y, double eye_z ,
              double coi_x, double coi_y, double coi_z ,
              double up_x,  double up_y,  double up_z ){

}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


int D3d_translate (double a[4][4], double b[4][4], double dx, double dy, double dz)
// a = translation*a  
// b = b*translation_inverse  
{
  double t[4][4] ;

  D3d_make_identity(t) ;

  t[0][3] =  dx ;  t[1][3] = dy ;  t[2][3] = dz ;
  D3d_mat_mult(a,  t,a) ;

  t[0][3] = -dx ;  t[1][3] = -dy ; t[2][3] = dz ;
  D3d_mat_mult(b,  b,t) ;

  return 1 ;
}