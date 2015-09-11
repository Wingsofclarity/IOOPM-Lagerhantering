#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lager.h"
#include "warehouse.h"
#include "ware.h"
//gcc -Wall -std=c11 main.c lager.c ware.c warehouse.c -o main


void welcome() {
  printf("Welcome to my storage thingy...\n");
}

void menu(db_t *db, bool *quit, int *numElm) {

  char *answerPtr = 0;
  int answer=0;
  printf("Select one alternative by entering one integer: ");
  
  answerPtr = inputString();
  answer = getFirstNum(answerPtr);
  free(answerPtr);
  
  while (answer<=0 || answer>8) {//Checking if choice is avaible.
    printf("Invalid entry.\n");
    printf("Select one alternative by entering one integer: ");
    answerPtr = inputString();
    answer = getFirstNum(answerPtr);
    free(answerPtr);
    
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

  
  char *answerPtr = inputString();
  setName(&newWare, answerPtr);
  free(answerPtr);

  answerPtr = inputString();
  int price = getFirstNum(answerPtr);
  setPrice(&newWare, price);
  free(answerPtr);
  
  answerPtr = inputString();
  setLoc(&newWare, answerPtr);
  free(answerPtr);

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

  char *a = malloc(20*sizeof(char));
  char c;
  int i = 0;
  while (true){
    fflush(stdout);
    c = getchar();
    //    printf("I read %c \n", c);
    if (c=='\n') {
      return a;
    }
    else if (i>=19) {
      a[i+1] = '\n';
      clearInput();
      return a;
    }
    a[i]=c;
    ++i;
  }
  return a;
}

int getFirstNum(char *s) {
  for (int i = 0; s[i]!='\n'; ++i) {
    if (s[i]>=(int)'0' && s[i]<=(int) '9') {
      return s[i] - (int) '0';
    }
  }
  printf("Critical error in getNum\n");
  return 0;
}

void clearInput() {
  fflush(stdout);
  while (getchar()!='\n'){  fflush(stdout);}
  return;
  //TODO If only '\n' is sent in this function is no good.
}
