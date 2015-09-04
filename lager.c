//C hello world example
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void welcome();
void  menu();
void addWare();
void removeWare();
void extendArray();
int scanSingleInt();
void clearInput();
int countWares();

struct shelf {
  char c;
  int i;
};
struct ware
{
  char name[20];
  int price;
  struct shelf shelf;
};

struct ware wares[20]; //Array of all the wares.
bool quit=false;

int main()
{ 
  fflush(stdout);
  welcome();

  while (quit==false) {
    menu();
  }
  return 0;
}


void welcome() {
  printf("Welcome to my storage thingy...\n");
  fflush(stdout);
}

void menu() {
  int answer = 8;
  printf("Select one alternative by entering one integer: ");
  answer = scanSingleInt();
  while (answer<0 || answer>8) {
    printf("Invalid entry.\n");
    printf("Select one alternative by entering one integer: ");
    answer = scanSingleInt();
  }
  switch (answer) {
    case 1: addWare(); break;
    case 2: removeWare(); break;
    case 8: quit=true; return;
    default: printf("Critical error.\n"); break;
  }
  return;
}

void addWare() {
  printf("add ware initiated.\n");
  wares[countWares()].price = 2;
  strcpy(wares[countWares()].name, "notnull");
}

void removeWare() {
  
}

void extendArray(struct ware *a){
  
  //struct ware *b = a

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

int countWares(struct ware wares[]) {
  if (wares[0].name==NULL) return 0;
  int i = 0;
  for (i=0; wares[0].name==NULL; i++) {}
  return i;
}
//git config credential.helper "cache"

