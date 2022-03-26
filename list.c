#include <stdlib.h>   /* malloc, srand, rand */
#include <time.h>     /* time() function for random generator */
#include <stdio.h>    /* printf */
#include "list.h"

static int LIST_SIZE = 0;   /* used only twice (!): in listInit() and findByPosition() */
static int MAX_NUMBER = 0;  /* list item value is from 1 to MAX_NUMBER */

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
  setNumber(tmp, rand()%MAX_NUMBER+1);
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

static void incrementListSize() {
  ++LIST_SIZE;
  return;
}

static void decrementListSize() {
  --LIST_SIZE;
  return;
}

bool listInit(int listSize, int maxNumber) {
  LIST_SIZE = listSize;
  MAX_NUMBER = maxNumber;
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

static void findByNumber(int number) {
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
  findByNumber(rand()%MAX_NUMBER+1);
}

static void findByPosition(int position) {
  if(position < 0 && position > LIST_SIZE) {
    printf("wrong position...\n");
    return;
  }
  listItem *tmp = firstItem;
  int i = 0;
  while(++i<position)
    tmp = tmp->nextItem;
  printf("at position %d there is number %d\n", i, tmp->number);
}

void findNumberAtRandomPosition() {
  findByPosition(rand()%LIST_SIZE+1);
}

/*
  maybe that implementation is too complicated?
  I'll try again later...
*/
static void addItemToOrderedList(listItem *item) {
  if(firstItem == NULL) {
    printf("there is no list... but we're going to create one\n");
    firstItem = item;
    return;
  }
  listItem *tmp = firstItem;    /* tmp is one position too far */
  listItem *tmp2 = firstItem;   /* so tmp2 precedes tmp */
  int i = 1;                    /* i is for tmp2 position */
  while(item->number > tmp->number) {
    if(tmp->nextItem == NULL)
      break;
    tmp = tmp->nextItem;
    if(++i>2)
      tmp2 = tmp2->nextItem;
  }
  if(i == 1) {
    if(item->number <= firstItem->number) {
      item->nextItem = firstItem;
      firstItem = item;
    } else { /* list could have only 1 item... */
      item->nextItem = NULL;
      firstItem->nextItem = item;
      ++i;
    }
  } else if (tmp->nextItem == NULL && item->number > tmp->number) { /* we reached the end... */
    item->nextItem = NULL;
    tmp->nextItem = item;   /* item is now at the end of our list */
    ++i;
  } else {
  item->nextItem = tmp2->nextItem;
  tmp2->nextItem = item;
  }
  incrementListSize();
  printf("number %d added to list at position %d\n", item->number, i);
}

void addRandomNumberToOrderedList() {
  listItem *tmp = itemConstructor();
  if(tmp == NULL)
    return;
  addItemToOrderedList(tmp);
}

/* TODO
void deleteRandomNumberFromOrderedList() {
  if(firstItem == NULL) {
    printf("there is no list...\n");
    return;
  }
  int number = rand()%MAX_NUMBER;
  if(firstItem->nextItem)
}
*/