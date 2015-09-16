#ifndef UNDO_H_   /* Include guard */
#define UNDO_H_

#include "ware.h"

typedef struct action
{
  int type; // NOTHING = 0, ADD = 1, REMOVE = 2, EDIT = 3
  Ware *merch;
  Ware copy;
}action_t;

int getType(action_t*);
Ware *getMerch(action_t*);
Ware getCopy(action_t*);

void setType(action_t*, int);
void setMerch(action_t*, Ware*);
void setCopy(action_t*, Ware*);

#endif 
