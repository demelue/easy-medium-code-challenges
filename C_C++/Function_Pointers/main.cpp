#include <stdlib.h>
#include <stdio.h>

typedef int (*Function_Pointer)(int,int);
typedef unsigned int byte;

int func(int a, int b)
{
  return (a+b);
}

int calculate(Function_Pointer input_func)
{
  int a = 9;
  return (*input_func)(a,a);
}

int main(int argc, char const *argv[]) {
  // int (*func_ptr)(int, int) = &func; //Defining a function pointer
  // printf("%d\n",(*func_ptr)(1,2)); //calling a function via function pointer
  Function_Pointer input_func = &func;
  byte value = 20;
  printf("Test typedef %d\n", value);
  printf("sum: %d\n", calculate(input_func));

  // int a = 5;
  // int b = 7;
  // int c = a+++b;
  // printf("%d, %d, %d\n", a,b,c);

  return 0;
}
