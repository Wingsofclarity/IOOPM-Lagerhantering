//C hello world example
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void welcome();
int menu();
void addWare();
void removeWare();
int scanInt();
void clearInput();

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

int main()
{
  welcome();
  struct ware wares[20];
  strcpy(wares[0].name, "fs");
  int svar=0;
  while (true) {
    svar = menu();
    switch (svar) {
    case 1: addWare(); break;
    case 8: return 1;
    default: printf("Critical error.\n"); break;
    }
  }
  return 0;
}


void welcome() {
  printf("Welcome to my storage thingy...\n");
}

int menu() {
  int a = 8;
  printf("Select one alternative by entering one integer: ");
  //a = scanInt();
  printf("%d\n", a);
  while (a<0 || a>8) {
    printf("Invalid entry.\n");
    printf("Select one alternative by entering one integer: ");
    a = scanInt();
  }
  return a;
}

void addWare() {
  printf("add ware initiated.\n");
}

void removeWare() {

}


int scanInt() {
  clearInput();
  return 1;
}

void clearInput() {
  //while (getchar!='\n'){}
  return;
}
//git config credential.helper "cache"
