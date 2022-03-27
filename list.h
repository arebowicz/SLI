#ifndef LIST_H
#define LIST_H

#include <stdio.h>    /* printf */
#include "listItem.h"

typedef struct list {
  listItem *firstItem;
  int listSize;
  int maxValue;
} list;

list *listConstructor(int, int);
void listInit(list *);
void printList(list *);
void deleteList(list *);

#endif