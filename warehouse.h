#ifndef WAREHOUSE_H_
#define WAREHOUSE_H_
#include "ware.h"
#include <stdbool.h>


typedef struct databas {
  Ware *wares;
  int numElm;
  int size;
  int chunk;
}db_t;

int getNumElm(db_t*);
int getSize(db_t*);
int getChunk(db_t*);
void setNumElm(db_t*, int);
void setSize(db_t*, int);
void setChunk(db_t*, int);
int findWare(db_t*,char*);

#endif
