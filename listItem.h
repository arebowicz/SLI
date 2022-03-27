#ifndef LIST_ITEM_H
#define LIST_ITEM_H

#include <stdlib.h>   /* malloc, srand, rand */
typedef struct listItem {
  int value;
  struct listItem *nextItem;
} listItem;

listItem *itemConstructor(int);
void deleteItem(listItem *);

#endif