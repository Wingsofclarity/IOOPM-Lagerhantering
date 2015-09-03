//C hello world example
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void welcome() {
  printf("Welcome to my storage thingy...\n");
}

int menu() {
  int a = 0;
  printf("Select one alternative by entering one integer: ");
  a = scanInt();
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

int scanInt() {
  int a=0;
  char s[11];
  fgets(s, 10, stdin);
//char c = getc(stdin);
//a = c - (int)'0';
  a = atoi(s);
  return a;
}

int main()
{
 
  welcome();
  int svar=0;

//while (true) {
    svar = menu();
    switch (svar) {
    case 1: addWare(); break;
    case 8: return 1;
    default: printf("Critical error.\n"); break;
   }
// }
  return 0;
}

//git config credential.helper "cache"
