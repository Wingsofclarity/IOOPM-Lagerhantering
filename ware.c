#include "ware.h"
#include <stdlib.h>
#include <string.h>

//TODO move struct definition in here'
typedef struct WareTag
{
  char name[20];
  int price;
  char loc[3];
}Ware;

char* getName(Ware w) {
  return w.name; //TODO Gives warnging
};

int getPrice(Ware w) {
  return w.price; 
};

char* getLoc(Ware w) {
  return w.loc;//TODO Gives warning
};

//TODO make set functions...
