#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lager.h"
#include "warehouse.h"

int main()
{

  int numElm = 0; //Number of element in wares.
  bool quit=false;
  
  db_t db = { .chunk = 16 };
  db_t oldDB = db;

  welcome();
  while (quit==false) { //Main loop
    menu(&db,&quit,&numElm, &oldDB);
  }
  return 0;
}

//git config credential.helper "cache"
//gcc -Wall -std=c11 main.c lager.c ware.c -o main
