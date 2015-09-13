#include "ware.h"
#include <stdlib.h>
#include <string.h>


//TODO move struct definition in here'

//TODO move struct definition in here


char* getName(Ware *w) {
  return w->name;
};

int getPrice(Ware *w) {
  return w->price; 
};

char* getLoc(Ware *w) {
  return w->loc;
};

void setName(Ware *w, char *s) {
  strcpy(w->name,s);
}

void setPrice(Ware *w, int a) {
  if (a<0) a=0;
  w->price=a;
}

void setLoc(Ware *w, char *s) {
  char out[4];
  if (s[0]>='a' && s[0]<='z') {
    out[0]=(char) s[0]-32;
  }
  else if (s[0]<'A' || s[0]>'Z'){
    out[0]='A';
    puts("Not a valid input");
  }
  else out[0] = s[0];
  
  if (s[1]<'0' || s[1]>'9'){
    out[1]='0';
    puts("Not a valid input");
  }
  else out[1]=s[1];
  
  if (s[2]<'0' || s[2]>'9'){
    out[2]='0';
    puts("Not a valid input");
  }
  else out[2]=s[2];
  printf("Out is %s \n", out);
  strcpy(w->loc, out);
}

void setWare(Ware *w, char *n, int p, char *l) {
  strcpy(w->name, n);
  if (p<0) p=0;
  w->price=p;
  setLoc(w,l);
}

//TODO make set functions...
