#include "ware.h"
#include "warehouse.h"
#include <stdlib.h>
#include <string.h>


int getNumElm(db_t *db) {
  return db->numElm;
}

int getSize(db_t *db) {
  return db->size;
}

int getChunk(db_t *db) {
  return  db->chunk;
}

Ware getWare(db_t *db, int i) {
  return db->wares[i];
}

void setNumElm(db_t *db, int a) {
  db->numElm=a;
}

void setSize(db_t *db, int a) {
  db->size=a;
}

void setChunk(db_t *db, int a) {
  db->chunk=a;
}

int findWare(db_t *db, char *s) {
  for (int i = 0; i<db->numElm; ++i) {
    if (strcmp(getName(db->wares+i),s)==-1) {
      printf("%d", strcmp(getName(db->wares+i),s));
      printf("Found %s", getName(db->wares+i));
      printf("Found it at %d\n",i);
      return i;
    }
  }
  return (-1);
}
