#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lager.h"
#include "ware.h"

int main()
{
  Ware *wares=0; //Array of all the wares. Uninitilazed gives warning...crashes if initialzed.
  int numElm = 0; //Number of element in wares.
  bool quit=false;
  
  welcome();
  while (quit==false) { //Main loop
    menu(&wares,&quit,&numElm);
    printf("Adress of interest main: %x \n", wares);
  }
  puts("Press enter to quit.");
  fflush(stdout); 
  getchar();
  return 0;
}

//git config credential.helper "cache"
//gcc -Wall -std=c11 main.c lager.c ware.c -o main
