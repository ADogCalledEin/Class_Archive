/*

1. Download the following :

     sftp  student@simpson1
     mget  arrows3.exe
     mget  arrows3student.c   (which is an electronic version of this file)
     mget  D2d_matrix.h  
     mget  D2d_matrixJeff.c  (if you don't trust your own)
     quit


2. Run the downloaded executable, via : 

     ./arrows3.exe

Press and hold the spacebar to see how the program behaves.


3. Your task is to enhance this file, using the matrix tools in 
D2d_matrix, with an eye to duplicating the behavior of the executable,
arrows3.exe.  For full credit, aim for run-time efficiency
by judicious use of the matrix tools.


4. In order for Jeff to grade this, before you start working, close
this file (if you are in emacs) and rename it from the command line
to a name that reflects your name :

   mv arrows3student.c     yournameARROWS.c

Make sure the ARROWS is captialized.

5. To compile your code :

   acom -I.  D2d_matrixJeff.c   yournameARROWS.c 

(assuming you use Jeff's D2d_matrix file)

*/

#include <FPT.h>
#include <D2d_matrix.h>

//arrow
double ax[4] = {0,  -20,  20, -20} ;
double ay[4] = {0,  -15,   0,  15} ;


int main()
{
  double mat[3][3], inv[3][3] ;
  int q ;

  G_init_graphics(700,700) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(1,1,1) ;
  G_draw_string("Press and hold the spacebar.", 10,10) ;
  G_wait_key() ;

  D2d_make_identity(mat) ;
  D2d_make_identity(inv) ;
  D2d_translate(mat, inv, 350,350) ;
  D2d_mat_mult_points(ax,ay,  mat, ax,ay,4) ; 
  G_rgb(1,1,1) ;  G_fill_polygon(ax,ay,4) ;  q = G_wait_key() ;



  while (q != 'q') { q = G_wait_key() ; }

}
