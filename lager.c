#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lager.h"
#include "ware.h"
//gcc -Wall -std=c11 main.c lager.c ware.c -o main

void welcome() {
  printf("Welcome to my storage thingy...\n");
}

void menu(Ware **wares, bool *quit, int *numElm) {

  int answer = 8;
  printf("Select one alternative by entering one integer: ");
  answer = scanSingleInt();
  
  while (answer<=0 || answer>8) {//Checking if choice is avaible.
    printf("Invalid entry.\n");
    printf("Select one alternative by entering one integer: ");
    answer = scanSingleInt();
  }
  
  switch (answer) {
    case 1: addWare(wares, numElm); break;
    case 2: removeWare(); break;
    case 3: editWare(); break;
    case 4: printAll(*wares, numElm); break;
    case 8: *quit=true; return;
    default: printf("Critical error.\n"); break;
  }
  
  printf("Adress of interest in menu: %x \n", *wares);
  return;
}

void addWare(Ware **wares, int *numElm) {
  printf("add ware initiated.\n");
  Ware *newArray=(Ware *)  malloc(sizeof(Ware)*(*numElm+1)); //Allocating space for new array.
  for (int i = 0; i<*numElm; ++i) { //Copying data from old to new
     *(newArray+i)=*(*wares+i); 
  }
  Ware newWare;
  newWare.price=2; //TODO Cheat to test other functions.
  printf("Price: %d\n", newWare.price);
  strcpy(newWare.name,"notnull");
  *(newArray+*numElm)=newWare; //The new ware is copied into the new array
  printf("Price: %d\n",(*(newArray+*numElm)).price);
  free(*wares);
  *wares = newArray; //The pointer is set to point to the new array.
  printf("Price: %d\n",(*(*wares+*numElm)).price);
  printf("*wares=%x\n",*wares);
  printf("newArray=%x\n",newArray);

  *numElm = (*numElm)+1;
  printf("Adress of interest in add: %x \n", *wares);
  printf("Price: %d\n",(*(*wares+*numElm-1)).price);
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

void printAll(Ware *wares, int *numElm) {//(Currently won't print more than 20 wares.
  if (*numElm<=0) { //If warehous is empty
    printf("There are no wares in the warehouse. :(\n");
    return;
  }
  for (int i = 0; i<*numElm && i<20 ; ++i) {
    printf("Ware '%s' costs '%d' and is at '%s'.\n",
	   (*(wares+i)).name,
	   (*(wares+i)).price,
	   (*(wares+i)).loc);
  }
  return;
}

void maybeQuit() {

}

int scanSingleInt() {
  fflush(stdout); //Without this it crashesh on windows....
  char a = getchar();
  clearInput();
  return (a-(int)'0');
}

void clearInput() {
  fflush(stdout);
  while (getchar()!='\n'){  fflush(stdout);}
  return;
  //TODO If only '\n' is sent in this function is no good.
}
