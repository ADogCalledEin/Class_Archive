void readobject(FILE *g, int onum){
  int k;

  //read first number in file and store in numpoints[onum]
  //file 0 has 7 coordinates, numpoints[0] = 7
  fscanf(g, "%d", &numpoints[onum]); 

  for(k = 0; k < numpoints[onum]; k++){
    //loop through and initialize all x and y coordinates in file
    fscanf(g, "%lf %lf", &x[onum][k], &y[onum][k]);
  }

  //set how many polyons are being drawn from this file
  //file 0 has 6 polygons, numpolys[0] = 6
  fscanf(g, "%d", &numpolys[onum]);
  //printf("numpolys: %d \n", numpolys[onum]);
  int c, p;
  for(k = 0; k < numpolys[onum]; k++){
    fscanf(g, "%d", &psize[onum][k]);
    for(p = 0; p < psize[onum][k]; p++){
      fscanf(g, "%d", &con[onum][k][p]);
      //printf("%d ", con[onum][k][p]);
    }
 
    //printf("psize: %d \n", psize[onum][0]);
  } 

  //get color values
  for(k = 0; k < numpolys[onum]; k ++){
    fscanf(g, "%lf %lf %lf", &red[onum][k], &grn[onum][k], &blu[onum][k]);
    //printf("colors: %lf %lf %lf \n", red[onum][0], grn[onum][0], blu[onum][0]);
  }
 
  
}