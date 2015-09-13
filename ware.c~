#include "ware.h"
#include <stdlib.h>
#include <string.h>


//TODO move struct definition in here'

//TODO move struct definition in here


char* getName(Ware *w) {
  return w->name; //TODO Gives warnging
};

int getPrice(Ware *w) {
  return w->price; 
};

char* getLoc(Ware *w) {
  return w->loc;//TODO Gives warning
};

void setName(Ware *w, char *s) {
  strcpy(w->name,s);
}

void setPrice(Ware *w, int a) {
  if (a<0) a=0;
  w->price=a;
}

void setLoc(Ware *w, char *s) {
  strcpy(w->loc, s);
}

void setWare(Ware *w, char *n, int p, char *l) {
  strcpy(w->name, n);
  if (p<0) p=0;
  w->price=p;
  strcpy(w->loc, l);
}

//TODO make set functions...
