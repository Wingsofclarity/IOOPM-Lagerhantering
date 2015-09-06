#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include "point.h"
//gcc -Wall point.c -o main

void f(int **a) {
  int *b = malloc(sizeof(int));
  *b = 1;
  *a=b;
  return;
}

int main () {
  int a=0;
  int b=1;
  int *ptr=&a;
  printf("%d \n", a);
  printf("%d \n", *ptr);
  f(&ptr);
  printf("%d \n", a);
  printf("%d \n", *ptr);
  return 0;
}

