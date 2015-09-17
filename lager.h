#ifndef LAGER_C_   /* Include guard */
#define LAGER_C_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#include "warehouse.h"
#include "ware.h"
#include "undo.h"

void welcome();
void menu(db_t*, bool*, action_t*);
void addWare(db_t*, action_t*);
void removeWare(db_t*, action_t*);
void editWare(db_t*, action_t*);
void undo(db_t*, action_t*);
void undoAdd(db_t*);
void undoRemove(db_t*, action_t*);
void undoEdit(db_t*, action_t*);
void printAll(db_t*);
void printDetails(Ware*);
void maybeQuit(bool*);
char* inputString();
int getFirstNum(char*);
int stringToInt(char*);
void clearInput();
int countWares();
void quickAdd(db_t*);
bool validInput(char*);

#endif // LAGER_C_
