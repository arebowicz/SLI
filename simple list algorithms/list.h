#ifndef LIST_H
#define LIST_H

#include <stdio.h>    /* printf */
#include "listItem.h"

typedef struct list {
  listItem *firstItem;
} list;

list *listConstructor();
void strToList(char *, list *);
void printList(list *);
void deleteList(list *);
void reverseList(list *);
void printMinimumAndItsPosition(list *);
void removeDuplicates(list *);

#endif