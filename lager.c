#include "lager.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lager.h"
#include "ware.c"


void welcome() {
  printf("Welcome to my storage thingy...\n");
}

void menu(Ware *wares, bool *quit) {
  int answer = 8;
  printf("Select one alternative by entering one integer: ");
  answer = scanSingleInt();
  while (answer<0 || answer>8) {
    printf("Invalid entry.\n");
    printf("Select one alternative by entering one integer: ");
    answer = scanSingleInt();
  }
  switch (answer) {
    case 1: addWare(&wares); break;
    case 2: removeWare(); break;
    case 8: *quit=true; return;
    default: printf("Critical error.\n"); break;
  }
  return;
}

void addWare(Ware **wares) {
  printf("add ware initiated.\n");
  int numElm =  length(*wares);
  printf("The array is %d long. \n", numElm);
  Ware *newArray=malloc(sizeof(Ware)*(numElm+1));
  for (int i = 0; i<(numElm); ++i) {
    newArray[i]=*wares[i];
  }
  Ware newWare;
  newWare.price=2;
  strcpy(newWare.name,"notnull");
  newArray[numElm]=newWare;
  *wares = newArray;
}

void removeWare() {
  
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
