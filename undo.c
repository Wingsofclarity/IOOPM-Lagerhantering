#include "undo.h"

int getType(action_t* a) {
  return a->type;
}

Ware* getMerch(action_t *a){
  return a->merch;
}

Ware getCopy(action_t *a){
  return a->copy;
}

void setType(action_t *a, int i) {
  a->type=i;
}

void setMerch(action_t *a, Ware *w) {
  a->merch=w; 
}

void setCopy(action_t *a, Ware *w) {
  a->copy=*w;
}
