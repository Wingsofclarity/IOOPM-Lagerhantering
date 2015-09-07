#include "ware.h"
#include <stdlib.h>
#include <string.h>

//TODO move struct definition in here'

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
