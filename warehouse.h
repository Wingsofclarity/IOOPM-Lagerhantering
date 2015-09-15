#ifndef WAREHOUSE_H_
#define WAREHOUSE_H_
#include "ware.h"
//#include <stdlib.h>
//#include <string.h>


typedef struct databas {
  Ware *wares;
  int numElm;
  int size;
  int chunk;
}db_t;

int getNumElm(db_t*);
int getSize(db_t*);
int getChunk(db_t*);
Ware* getWare(db_t*, int);
Ware* getWares(db_t*);

void setNumElm(db_t*, int);
void plusElm(db_t*);
void setSize(db_t*, int);
void setChunk(db_t*, int);

int findWare(db_t*,char*);
int findWareAt(db_t*,char*);

#endif
