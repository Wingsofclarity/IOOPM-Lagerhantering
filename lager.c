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

void menu(db_t *db, bool *quit, int *numElm) {

  int answer = 8;
  printf("Select one alternative by entering one integer: ");
  answer = scanSingleInt();
  
  while (answer<=0 || answer>8) {//Checking if choice is avaible.
    printf("Invalid entry.\n");
    printf("Select one alternative by entering one integer: ");
    answer = scanSingleInt();
  }
  
  switch (answer) {
    case 1: addWare(db, numElm); break;
  case 2: removeWare(db, numElm); break;
    case 3: editWare(); break;
    case 4: printAll(db, numElm); break;
    case 8: *quit=true; return;
    default: printf("Critical error.\n"); break;
  }
  return;
}


void addWare(db_t *db) {
  if (db->numElm>=db->size) {
    printf("Reallocating space!\n");
    db->size+=db->chunk;
    db->wares = realloc(db->wares, sizeof(Ware)*(db->size));
  }
  
  Ware newWare;
  newWare.price=2; 
  strcpy(newWare.name,"notnull");
  strcpy(newWare.loc,"A31");

  db->wares[db->numElm] = newWare;
  ++db->numElm;
}

void removeWare(db_t *db) {
  if (db->numElm<=0) {
    printf("Warehouse already empty.\n");
    return;
  }
  --db->numElm;
  if ((db->size)-(db->numElm)>=db->chunk) {
    db->size=db->size-db->chunk;
    db->wares = realloc(db->wares, sizeof(Ware)*(db->size)); 
  }

}

void editWare() {
  puts("Editing your butt.");
  
}

void undo () {
  puts("Undone undo.");
}

void printAll(db_t *db) {//(Currently won't print more than 20 wares.
  if (db->numElm<=0) { //If warehous is empty
    printf("There are no wares in the warehouse. :(\n");
    return;
  }
  for (int i = 0; i<db->numElm && i<20 ; ++i) {
    printf("Ware '%s' costs '%d' and is at '%s'.\n",
	   db->wares[i].name,
	   db->wares[i].price,
	   db->wares[i].loc);
  }
  return;
}

void maybeQuit() {
  
}

char *inputString() {
 //Without this it crashesh on windows....
  char *a = malloc(20*sizeof(char));
  char c;
  int i = 0;
  do  {
    fflush(stdout);
    c = getchar();
    a[i]=c;
    ++i;
  } while (c!='\n' && i<18);
  a[i]='\n';
  clearInput();
  return a;
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
