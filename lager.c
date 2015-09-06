#include "lager.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lager.h"
#include "ware.c"
//gcc -Wall -std=c11 main.c lager.c ware.c -o main


void welcome() {
  printf("Welcome to my storage thingy...\n");
}

void menu(Ware *wares, bool *quit, int *numElm) {
  int answer = 8;
  printf("Select one alternative by entering one integer: ");
  answer = scanSingleInt();
  while (answer<0 || answer>8) {
    printf("Invalid entry.\n");
    printf("Select one alternative by entering one integer: ");
    answer = scanSingleInt();
  }
  switch (answer) {
    case 1: addWare(&wares, numElm); break;
    case 2: removeWare(); break;
  case 3: editWare(); break;
  case 4: printAll(); break;
    case 8: *quit=true; return;
    default: printf("Critical error.\n"); break;
  }
  return;
}

void addWare(Ware *wares, int *numElm) {
  printf("add ware initiated.\n");
  printf("The array is %d long. \n", *numElm);
  Ware *newArray= malloc(sizeof(Ware)*(*numElm+1));
  for (int i = 0; i<*numElm; ++i) {
    *(newArray+i)=*(wares+i);
  }
  Ware newWare;
  newWare.price=2;
  strcpy(newWare.name,"notnull");
  newArray[*numElm]=newWare;
  wares = &newArray;
  ++*numElm;
  printf("The arrat is NOW %d long. \n", *numElm);
}

void removeWare() {
  puts("Removing your butt.");
}

void editWare() {
  puts("Editing your butt.");
}

void undo () {
  puts("Undone undo.");
}

void printAll(Ware *wares, int *numElm) {
  printf("num elm is: %d\n",*numElm);
  if (*numElm<=0) {
    printf("There are no wares in the warehouse. :(\n");
  }
  /*for (int i = 0; i<*numElm; ++i) {
    //printf("Ware %d: %s, %d �re, %s.", i, (*(wares+i)).name,20,"sdjk");
    printf("Ware %d", (*(wares+1)).price);
    }*/
  

  return;
}

void maybeQuit() {

}
int scanSingleInt() {
  fflush(stdout);
  char a = getchar();
  clearInput();
  return (a-(int)'0');
}

void clearInput() {
  fflush(stdout);
  while (getchar()!='\n'){  fflush(stdout);}
  return;
}

void breakPoint() {
  puts("Breakpoint!");
  fflush(stdout);
  getchar();
  clearInput();
}
