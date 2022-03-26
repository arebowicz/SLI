#ifndef LIST_H
#define LIST_H

#include "listItem.h"

typedef struct list {
  listItem *firstItem;
  int listSize;
  int maxValue;
} list;

/* incomplete! */
void listInit(int, int);
void printList(list *);
void deleteList(list *);
void listBubbleSort(list *);
void findRandomNumber();
void findNumberAtRandomPosition();
void addRandomNumberToOrderedList();
/* TODO
void deleteRandomNumberFromOrderedList();
*/
/*
  etc, etc...
*/

#endif