#ifndef WARE_H_  /* Include guard */
#define WARE_H_
/*#include <stdbool.h>
  #include <stdlib.h>*/
#include <string.h>


typedef struct WareTag Ware;
typedef struct WareTag
{
  char name[20];
  int price;
  char loc[3];
}Ware;

char* getName(Ware const*);
int getPrice(Ware*);
char* getLoc(Ware*);

void setName(Ware*, char*);
void setPrice(Ware*, int);
void setLoc(Ware*, char*);
void setWare(Ware*, char*, int, char*);


#endif // WARE_C_
