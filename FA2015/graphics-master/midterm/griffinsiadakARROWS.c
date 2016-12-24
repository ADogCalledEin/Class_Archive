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
int numpoints = 4;
double center = 350;


double tran[3][3], rot[3][3], sca[3][3];


void rotate(){ 
  double m[3][3], minv[3][3];
  D2d_make_identity(m);
  D2d_make_identity(minv);

  D2d_translate(m,minv, -center, -center); //move to origin
  D2d_rotate(m, minv, M_PI/6);             //rotate
  D2d_translate(m,minv,center,center);     //move back to center
  D2d_copy_mat(rot, m);

}

void translate(){
  double m[3][3], minv[3][3];
  D2d_make_identity(m);
  D2d_make_identity(minv);

  D2d_translate(m, minv, 100, 0);          //move out radius of circle
  D2d_copy_mat(tran, m);
}

void scale(){
  double m[3][3], minv[3][3];
  D2d_make_identity(m);
  D2d_make_identity(minv);

  D2d_translate(m ,minv, -center, -center); //move to origin
  D2d_scale(m ,minv, 1.01,1.01);            //scale up a tiny bit per cycle
  D2d_translate(m,minv, center,center);     //move back to center
  D2d_copy_mat(sca, m);
}

int main()
{
  double mat[3][3], inv[3][3];
  int q,i,j,count;
  double red = 0.0;

  G_init_graphics(700,700) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(1,1,1) ;
  G_draw_string("Press and hold the spacebar.", 10,10) ;
  G_wait_key() ;


  D2d_make_identity(mat) ;
  D2d_make_identity(inv) ;
  D2d_translate(mat, inv, center,center) ;            //initial move to center
  D2d_mat_mult_points(ax,ay,  mat, ax,ay,numpoints) ;
  translate();                                        //move out radius of circle
  D2d_mat_mult_points(ax, ay, tran, ax, ay, numpoints);
  

  while (1 == 1) { 
    G_rgb(0,0,0) ;
    G_clear() ;
    scale();
    D2d_mat_mult_points(ax, ay, sca, ax , ay, numpoints); //scale in the continuous loop
    for (i=0; i<13; i++){
      rotate();                                           //rotate in the draw loop
      D2d_mat_mult_points(ax, ay, rot, ax, ay, numpoints);
      G_rgb(red,0,1) ;  
      G_fill_polygon(ax,ay,numpoints) ;   
    }
    count++;
    red += 0.011;     //increment color a bit to get the gradient
    if(count == 106){ //sloppy way of stopping the draw at the window edge
      break;
    }
    q = G_wait_key() ; 
  }
  while(q != 'q'){    //hang until user hits q to quit
  q = G_wait_key() ;
  }
}
