#ifndef LIST_OF_LISTS_H
#define LIST_OF_LISTS_H

#include "list.h"

typedef struct listOfLists {
  list *list;
  struct listOfLists *nextList;
} listOfLists;

/* incomplete! */
list *newList();
void deleteAllCreatedLists();
void printAllLists(list *);


#endif