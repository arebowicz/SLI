#ifndef LIST_OF_LISTS_H
#define LIST_OF_LISTS_H

#include <time.h>     /* time() function for random generator */
#include "list.h"

typedef struct listOfLists {
  list *list;
  struct listOfLists *nextList;
} listOfLists;

void newList(int, int);
void deleteAllCreatedLists();
void printAllLists();


#endif