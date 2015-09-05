#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lager.h"
#include "ware.c"

int main()
{
  Ware *wares = 0; //Array of all the wares.
  bool quit=false;
  
  welcome();

  while (quit==false) {
    menu(wares,&quit);
  }
  puts("Press enter to quit.");
  fflush(stdout);
  getchar();
  return 0;
}

//git config credential.helper "cache"
//gcc -Wall -std=c11 main.c lager.c ware.c -o main
