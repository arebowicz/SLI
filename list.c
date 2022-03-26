#include <stdlib.h>   /* malloc, srand, rand */
#include <time.h>     /* time */
#include <stdio.h>    /* printf */
#include "list.h"

#define LIST_SIZE 25  /* used only once (!) in listInit() */
#define MAX_NUMBER 100  /* list item value is from 0 to MAX_NUMBER-1 */

typedef struct listItem {
  int number;
  struct listItem *nextItem;
} listItem;

static listItem *firstItem = NULL;

static listItem *mallocListItem() {
  return (listItem *) malloc(sizeof(listItem));
}

static void setNumber(listItem *item, int number) {
  item->number = number;
  return;
}

static void setNextItem(listItem *item, listItem *nextItem) {
  item->nextItem = nextItem;
  return;
}

static listItem *itemConstructor() {
  listItem *tmp = mallocListItem();
  if(tmp == NULL)
    return NULL;
  setNumber(tmp, rand()%MAX_NUMBER);
  setNextItem(tmp, NULL);
  return tmp;
}

static bool addNextItem(listItem *item) {
  if(item == NULL)
    return false;
  listItem *tmp = firstItem;
  while(tmp->nextItem != NULL)
    tmp = tmp->nextItem;
  tmp->nextItem = item;
  return true;
}

bool listInit() {
  srand(time(NULL));
  firstItem = itemConstructor();
  if(firstItem == NULL)
    return false;
  int i = 0;
  while(++i<LIST_SIZE)
    if(addNextItem(itemConstructor()) == false)
      return false;
  printf("list successfully initialised\n");
  return true;
}

void printList() {
  if(firstItem == NULL) {
    printf("there is no list...\n");
    return;
  }
  listItem *tmp = firstItem;
  printf("numbers:\n");
  while(tmp->nextItem != NULL) {
    printf("%d ", tmp->number);
    tmp = tmp->nextItem;
  }
  printf("%d\n", tmp->number);
  return;
}

void deleteList() {
  if(firstItem == NULL) {
    printf("there is no list...\n");
    return;
  }
  listItem *tmp = firstItem;
  listItem *tmp2;
  while(tmp->nextItem != NULL) {
    tmp2 = tmp->nextItem;
    free(tmp);
    tmp = tmp2;
  }
  free(tmp);
  firstItem = NULL;
  printf("list successfully deleted\n");
  return;
}

static void swap(listItem *item1, listItem *item2) {
  int tmp;
  if(item1->number > item2->number) {
    tmp = item1->number;
    item1->number = item2->number;
    item2->number = tmp;
  }
  return;
}

void listBubbleSort() {
  if(firstItem == NULL) {
    printf("there is no list...\n");
    return;
  }
  listItem *item1 = firstItem;
  listItem *item2 = NULL;
  while(item1->nextItem != NULL) {
    item2 = firstItem;
    while(item2->nextItem != NULL) {
      swap(item2, item2->nextItem);
      item2 = item2->nextItem;
    }
    item1 = item1->nextItem;
  }
  printf("list successfully sorted\n");
}

static void findNumber(int number) {
  if(firstItem == NULL) {
    printf("there is no list...\n");
    return;
  }
  listItem *tmp = firstItem;
  int i = 0;
  while(tmp != NULL) {
    ++i;
    if(tmp->number == number) {
      printf("number %d found at position %d\n", number, i);
      return;
    }
    tmp = tmp->nextItem;
  }
  printf("number %d not found in list\n", number);
  return;
}

void findRandomNumber() {
  findNumber(rand()%MAX_NUMBER);
}