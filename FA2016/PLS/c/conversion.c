//converting a word that looks like a number into a number

int getNumber(char *w, double res[1]){
  int i,c;
  res[0] = 0;
  i = 0;

  while (w[i] != '\0'){
    c = w[i];
    if (('0' <= c) && (c<= '9')){
      res[0] = (res[0]*10) + (c - '0');
    }else{
      return 0;
    }
  }
  return 1;

}

int main(){
  char w[100];
  double v[1];
  int s;
  scanf("%s",w);
  s = get_number_from_word(w,v);
}
