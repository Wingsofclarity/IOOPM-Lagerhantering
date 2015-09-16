#include "lager.h"
//gcc -Wall -std=c11 main.c lager.c ware.c warehouse.c -o main

void welcome() {
  printf("Welcome to my storage thingy...\n");
}

void menu(db_t *db, bool *quit, db_t *oldDB) {

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
    //*oldDB = *db;
    addWare(db); 
    break;

  case 2:
    //*oldDB = *db;
    removeWare(db);
    break;

  case 3: 
    //*oldDB = *db;
    editWare(db); 
    break;

  case 4: 
    printAll(db);
    break;

  case 5: 
    undo(db,oldDB); 
    break;

  case 7:
    //*oldDB = *db;
    quickAdd(db);
    break;

  case 8:
    maybeQuit(quit);
    return;

  default: 
    printf("Critical error.\n");
    break;
  }
  return;
}


void addWare(db_t *db) { 
  if (getNumElm(db)>=getSize(db)) {
    printf("Reallocating space!\n");
    setSize(db,(getSize(db)+getChunk(db)));
    setWares(db, realloc(getWares(db), sizeof(Ware)*(getSize(db))));
  }
  
  Ware newWare;

  //Choose name
  printf("Enter ware name: ");
  char *answerPtr = inputString();
  setName(&newWare, answerPtr);
  free(answerPtr);

  //Choose price
  printf("Enter the price: ");
  answerPtr = inputString();
  int price = stringToInt(answerPtr);
  setPrice(&newWare, price);
  free(answerPtr);

  //Choose location
  printf("Enter %s's location: ", getName(&newWare));
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

  //Choose description
  printf("Enter ware description (or skip by pressing enter): ");
  answerPtr = inputString();
  setDescription(&newWare,answerPtr);
  free(answerPtr);
  
  getWares(db)[getNumElm(db)] = newWare;
  plusElm(db);
  puts("Ware added.");
}

void removeWare(db_t *db) {
  if (getNumElm(db)<=0) {
    printf("Warehouse already empty.\n");
    return;
  }
  char *answerPtr = inputString();
  int a = findWare(db,answerPtr);
  free(answerPtr);
  for (int i = a; i<(getNumElm(db))-1; ++i) {
    getWares(db)[i]=getWares(db)[i+1]; 
  }
  setNumElm(db,getNumElm(db)-1);
  if ((getSize(db))-(getNumElm(db))>=getChunk(db)) {
    printf("Reallocating space!\n");
    setSize(db, getSize(db)-getChunk(db));
    setWares(db,realloc(getWares(db), sizeof(Ware)*(getSize(db)))); 
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
  puts("4. Edit description");
  puts("8. Never mind...");
  printf("Select one alternative by entering one integer: ");
  answerPtr = inputString();
  int answer = getFirstNum(answerPtr);
  free(answerPtr);
  switch (answer) {
  case 1:
    printf("Enter the new name: ");
    answerPtr = inputString();
    setName(getWare(db,index),answerPtr);
    free(answerPtr);
    break;

  case 2:
    printf("The old price is %d. Enter the new price: ",getPrice(getWare(db,index)));
    answerPtr = inputString();
    int price = getFirstNum(answerPtr);
    setPrice(getWare(db,index),price);
    free(answerPtr);
    break;

  case 3:
    printf("The old location is %s. Enter the new location: ",getLoc(getWare(db,index)));
    answerPtr = inputString();
    int index2 =  findWareAt(db,answerPtr);
    while (index2!=-1 && strcmp(answerPtr,"---")!=0) {
      printf("Location already occupied by %s.\n", getName(getWare(db,index2)));
      printf("Please enter another location: ");
      answerPtr = inputString();
      index2 =  findWareAt(db,answerPtr);
    }
    setLoc(getWare(db,index), answerPtr);
    free(answerPtr);
    break;

  case 4:
    printf("The current description is '%s'. \n",getDescription(getWare(db,index)));
    printf("Enter the new description here: ");
    answerPtr=inputString();
    setDescription(getWare(db,index),answerPtr);
    free(answerPtr);

  case 8: 
    puts("Edit canceled");
    return;

  default:
    puts("Critical error.");
    return;
  }

  puts("Ware edited.");
}

void undo (db_t *db, db_t *oldDB) {
  /*
  db_t  temp = *db;
  *db = *oldDB;
  *oldDB = temp;
  puts("Last operation undone.");*/
}


void printAll(db_t *db) {//(Currently won't print more than 20 wares.
  if (getNumElm(db)<=0) { //If warehous is empty
    printf("There are no wares in the warehouse. :(\n");
    return;
  }
  for (int i = 0; i<getNumElm(db) && i<20 ; ++i) {
    printf("Ware '%s' costs '%d' and is at '%s'.\n",
	   getName(&getWares(db)[i]),
	   getPrice(&getWares(db)[i]),
	   getLoc(&getWares(db)[i]));
  }
  return;
}

void maybeQuit(bool *quit) {
  printf("Are you sure you want to quit? Enter [y]es or [n]o: ");
  char *answer=inputString();
  if (answer[0]=='y'){
    *quit=true;
  }
  
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
  if (s[0]=='-') a*=-1;
  return a;
}

void clearInput() {
  fflush(stdout);
  while (getchar()!='\n'){  fflush(stdout);}
  return;
}


void quickAdd(db_t *db) {
   if (getNumElm(db)>=getSize(db)) {
    printf("Reallocating space!\n");
    setSize(db, getSize(db)+getChunk(db));
    setWares(db, realloc(getWares(db), sizeof(Ware)*(getSize(db))));
    db->wares = realloc(db->wares, sizeof(Ware)*(db->size));
  }
  
  Ware newWare;

  char a = getNumElm(db) + '0';
  char answerPtr[6] = {'W','a','r','e',a,'\0'};
  setName(&newWare, answerPtr);
  
  int price = 0;
  setPrice(&newWare, price);

  char location[4] = {'A','0','0','\0'};
  setLoc(&newWare,location);

  char description[4] = {'E','E','D','\0'};
  setDescription(&newWare,description);

  db->wares[db->numElm] = newWare;
  plusElm(db);
}
