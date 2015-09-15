#include "ware.h"

char* getName(Ware const *w) {
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
  if (s[0]>='a' && s[0]<='z') {//If lower case letter it changes to upper case.
    out[0]=(char) s[0]-32;
  }
  else if (s[0]<'A' || s[0]>'Z'){//If not a letter.
    out[0]='-';
  }
  else out[0] = s[0];
  
  if (s[1]<'0' || s[1]>'9' || s[2]<'0' || s[2]>'9'){//Char not a number.
    out[1]='-';
    out[2]='-';
  }
  else {
    out[1]=s[1];
    out[2]=s[2];
  }
  out[3] = '\0';
  strcpy(w->loc, out);
}

void setWare(Ware *w, char *n, int p, char *l) {
  strcpy(w->name, n);
  if (p<0) p=0;
  w->price=p;
  setLoc(w,l);
}
