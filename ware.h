#ifndef WARE_H_  /* Include guard */
#define WARE_H_
typedef struct WareTag
{
  char name[20];
  int price;
  char loc[3];
}Ware;

typedef struct databas {
  Ware *wares;
  int numElm;
  int size;
  int chunk;
}db_t;


//struct WareTag;

char* getName(Ware*);
int getPrice(Ware*);
char* getLoc(Ware*);


#endif // WARE_C_
