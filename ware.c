#include "ware.h"
#include <stdlib.h>
#include <string.h>



char* getName(Ware w) {
  return w.name;
};

int getPrice(Ware w) {
  return w.price;
};

char* getLoc(Ware w) {
  return w.loc;
};
