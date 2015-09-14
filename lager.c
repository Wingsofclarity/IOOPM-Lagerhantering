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

void menu(db_t *db, bool *quit, int *numElm, db_t *oldDB) {

  char *answerPtr = 0;
  int answer=0;
  puts("Select one of following operations.");
  puts("1. Add a ware to the warehouse.");
  puts("2. Remove a ware from the warehouse.");
  puts("3. Edit a detail about a ware.");
  puts("4. Show all the wares at once.");
  puts("5. Undo last operation.");
  puts("7. Quickly add a test item to the warehouse for testing.");
  puts("8. Quit.");
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
  case 1: 
    *oldDB = *db;
    addWare(db); 
    break;

  case 2:
    *oldDB = *db;
    removeWare(db);
    break;

  case 3: 
    *oldDB = *db;
    editWare(db); 
    break;

  case 4: 
    printAll(db);
    break;

  case 5: 
    undo(db,oldDB); 
    break;

  case 7:
    *oldDB = *db;
    quickAdd(db);
    break;

  case 8:
    *quit=true;
    return;

  default: 
    printf("Critical error.\n");
    break;
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
  int price = stringToInt(answerPtr);
  setPrice(&newWare, price);
  free(answerPtr);
  
  answerPtr = inputString();
  int index =  findWareAt(db,answerPtr);
  while (index!=-1 && strcmp(answerPtr,"---")!=0) {
    printf("Location already occupied by %s.\n", getName(getWare(db,index)));
    printf("Please enter another location: ");
    answerPtr = inputString();
    index =  findWareAt(db,answerPtr);
  }
  setLoc(&newWare, answerPtr);
  free(answerPtr);

  db->wares[db->numElm] = newWare;
  ++db->numElm;
  puts("Ware added.");
}

void removeWare(db_t *db) {
  if (db->numElm<=0) {
    printf("Warehouse already empty.\n");
    return;
  }
  char *answerPtr = inputString();
  int a = findWare(db,answerPtr);
  free(answerPtr);
  for (int i = a; i<(db->numElm)-1; ++i) {
    db->wares[i]=db->wares[i+1];
    
  }
  --db->numElm;
  if ((db->size)-(db->numElm)>=db->chunk) {
    db->size=db->size-db->chunk;
    db->wares = realloc(db->wares, sizeof(Ware)*(db->size)); 
  }
  puts("Ware removed.");
}

void editWare(db_t *db) {
  puts("Edit initiated.");
  puts("What ware do you wnat to edit?");
  char *answerPtr = inputString();
  int index = findWare(db,answerPtr);
  if (index==-1) {
    printf("Can't find ware %s.", answerPtr);
    puts("Returning to menu");
    free(answerPtr);
    return;
  }
  free(answerPtr);
  puts("What do you want to edit?");
  puts("1. Edit name.");
  puts("2. Edit price.");
  puts("3. Edit location");
  puts("8. Never mind...");
  answerPtr = inputString();
  int answer = getFirstNum(answerPtr);
  free(answerPtr);
  switch (answer) {
  case 1:
    printf("Enter the new name:");
    answerPtr = inputString();
    setName(getWare(db,index),answerPtr);
    free(answerPtr);
    break;

  case 2:
    printf("The old price is %d. Enter the new price:",getPrice(getWare(db,index)));
    answerPtr = inputString();
    int price = getFirstNum(answerPtr);
    setPrice(getWare(db,index),price);
    free(answerPtr);
    break;

  case 3:
    printf("The old location is %s. Enter the new price:",getLoc(getWare(db,index)));
    break;

  case 4:
    printf("The old price is %d. Enter the new price:",getPrice(getWare(db,index)));
    break;
    
  case 8: 
    puts("Edit canceled");
    return;
    }
  puts("Ware edited.");
}

void undo (db_t *db, db_t *oldDB) {
  db_t  temp = *db;
  *db = *oldDB;
  *oldDB = temp;
  puts("Last operation undone.");
}


void printAll(db_t *db) {//(Currently won't print more than 20 wares.
  if (db->numElm<=0) { //If warehous is empty
    printf("There are no wares in the warehouse. :(\n");
    return;
  }
  for (int i = 0; i<db->numElm && i<20 ; ++i) {
    printf("Ware '%s' costs '%d' and is at '%s'.\n",
	   getName(&db->wares[i]),
	   getPrice(&db->wares[i]),
	   getLoc(&db->wares[i]));
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
    if (c=='\n') {
      a[i]='\0';
      return a;
    }
    else if (i>=19) {
      a[i] = '\0';
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

int stringToInt(char *s){
  int a = 0;
  for (int i = 0; s[i]!='\0'; ++i) {
    if (s[i]>='0' && s[i]<= '9') {
      a*=10;
      a += (s[i] - (int) '0');
    }
  }
  return a;
}

void clearInput() {
  fflush(stdout);
  while (getchar()!='\n'){  fflush(stdout);}
  return;
  //TODO If only '\n' is sent in this function is no good.
}


void quickAdd(db_t *db) {
   if (db->numElm>=db->size) {
    printf("Reallocating space!\n");
    db->size+=db->chunk;
    db->wares = realloc(db->wares, sizeof(Ware)*(db->size));
  }
  
  Ware newWare;

  char a = db->numElm + '0';
  char answerPtr[6] = {'W','a','r','e',a,'\0'};
  setName(&newWare, answerPtr);
  
  int price = 0;
  setPrice(&newWare, price);

  char location[4] = {'A','0','0','\0'};
  setLoc(&newWare,location);

  db->wares[db->numElm] = newWare;
  ++db->numElm;
}
