#include "warehouse.h"

int getNumElm(db_t *db) {
  return db->numElm;
}

int getSize(db_t *db) {
  return db->size;
}

int getChunk(db_t *db) {
  return  db->chunk;
}

Ware* getWare(db_t *db, int i) {
  return &(db->wares[i]);
}

Ware* getWares(db_t *db) {
  return getWare(db,0);
}

void setNumElm(db_t *db, int a) {
  db->numElm=a;
}

void plusElm(db_t *db) {
  ++db->numElm;
}

void setSize(db_t *db, int a) {
  db->size=a;
}

void setChunk(db_t *db, int a) {
  db->chunk=a;
}

int findWare(db_t *db, char *s) {
  for (int i = 0; i<db->numElm; ++i) {
    if (strcmp(s,getName(db->wares+i))==0) {
      return i;
    }
  }
  return (-1);
}

int findWareAt(db_t *db, char *loc) {
  for (int i = 0; i<getNumElm(db); ++i) {
    if (strcmp(loc,getLoc(db->wares+i))==0) {
      return i;
    }
  }
  return (-1);
}
