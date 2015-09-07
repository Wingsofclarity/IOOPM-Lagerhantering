#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lager.h"
#include "ware.h"

int main()
{
  Ware *wares=0; //Array of all the wares.
  int numElm = 0;
  bool quit=false;
  welcome();
  
  while (quit==false) {
    menu(wares,&quit,&numElm);
    //    fflush(stdout);
    //printf("Value of var[%d] = %d\n", i, *numElm );
    printf("In main it is %d \n",numElm);
    //    puts("sdkj");
  }
  puts("Press enter to quit.");
  fflush(stdout);
  getchar();
  return 0;
}

//git config credential.helper "cache"
//gcc -Wall -std=c11 main.c lager.c ware.c -o main
