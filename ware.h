#ifndef WARE_H_  /* Include guard */
#define WARE_H_
#include <string.h>


typedef struct WareTag Ware;
typedef struct WareTag{
  char name[20];
  char description[20];
  int price;
  char loc[3];
}Ware;

char* getName(Ware const*);
int getPrice(Ware*);
char* getLoc(Ware*);
char* getDescription(Ware*);

void setName(Ware*, char*);
void setPrice(Ware*, int);
void setLoc(Ware*, char*);
void setWare(Ware*, char*, int, char*);
void setDescription(Ware*, char*);


#endif // WARE_C_
