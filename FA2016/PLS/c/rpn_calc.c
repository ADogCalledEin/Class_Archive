#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int max_size = 100;
double stack[100];
int top = -1;

//is it empty?
int isEmpty(){
  if (top == -1){
    return 1;
  }else{
    return 0;
  }
}

//is it full?
int isFull(){
  if (top == max_size-1){
    return 1;
  }else{
    return 0;
  }
}

//whats on top?
double peek(){
  return stack[top];
}

//take the top value
double pop(){
  double data;

  if(!isEmpty()){
    data = stack[top];
    top = top - 1;
  }else{
    printf("Stack empty. Nothing to pop.\n");
  }
  return(data);
}

//push on a new value
void push(double data){
  if (!isFull()){
    stack[top + 1] = data;
    top++;
  }else{
    printf("Stack is full. Cannot push.\n");
  }
}

//print the stack as it is
void pstack(){
  int i;
  for(i=top; i>-1; i = i - 1){
    printf("%lf\n", stack[i]);
  }
}

//MATHEMATICAL STACK OPERATIONS BELOW HERE

void add(){
  double b = pop();
  double a = pop();
  push(a + b);
}

void sub(){
  double b = pop();
  double a = pop();
  push(a - b);
}

void mul(){
  double b = pop();
  double a = pop();
  push(a * b);
}

void p_div(){
  double b = pop();
  double a = pop();
  push(a / b);
}

//kinda integer division (simulates the always round down of PS)
void idiv(){
  double b = pop();
  double a = pop();
  double c = floor(a / b);
  push(c);
}

void mod(){
  double b = pop();
  double a = pop();
  push(fmod(a,b));
}

void p_sqrt(){
  double a = pop();
  push(sqrt(a));
}

void p_sin(){
  double a = pop();
  push(sin(a));
}

void p_cos(){
  double a = pop();
  push(cos(a));
}

//NOW INTO STACK MANIPULATION

void dup(){
  double a = pop();
  double data = a;
  push(a);
  push(data);
}

void exch(){
  double a = pop();
  double b = pop();
  push(a);
  push(b);
}

void p_index(){
  double in = pop();
  int out = top - in;
  double data = stack[out];
  push(data);
}

void copy(){
  double dep = pop();
  printf("Depth is %lf\n", dep);
  // int i;
  // double new[depth];
  // for(i = top; i >= depth; i--){
  //   new[i] = stack[i];
  // }
  // for (i = 0; i < depth; i++){
  //   push(new[i]);
  // }
}

// void roll(){
//   int amount = pop();
//   int depth = pop();
//   double move[depth];
//   double stay[top-depth];
//   int i;
//   for(i=top; i<=depth; i--){
//     move[i] = stack[i];
//   }
//   for(i=0; i<depth; i++){
//     stay[i] = stack[i];
//   }
//   if (amount < 0){
//     for(i=0; i<amount; i++){
//       stack[i] = move[i];
//     }
//     for(i=amount; i<top; i++){
//       stack[i] = stay[i];
//     }
//   }else{
//     for(i=)
//   }
//
// }



int main(){
  push(21);
  push(4);
  push(10);
  push(2);
  pstack();
  copy();
  pstack();



}
