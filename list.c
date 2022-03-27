#include "list.h"

list *listConstructor(int listSize, int maxValue) {
  list *l = (list *) malloc(sizeof(list));
  if(l == NULL)
    return NULL;
  l->firstItem = NULL;
  l->listSize = listSize;
  l->maxValue = maxValue;
  return l;
}

static void addItem(list *l, listItem *item) {
  if(l->firstItem == NULL) {
    l->firstItem = item;
    return;
  }
  listItem *tmp = l->firstItem;
  while(tmp->nextItem != NULL)
    tmp = tmp->nextItem;
  tmp->nextItem = item;
}

void printList(list *l);

void listInit(list *l) {
  int i = 0;
  while(++i <= l->listSize)
    addItem(l, itemConstructor(rand()%(l->maxValue+1)));
  printf("list successfully initialised");
}

void printList(list *l) {
  if(l == NULL || l->firstItem == NULL)
    return;
  listItem *tmp = l->firstItem;
  printf("[");
  while(tmp->nextItem != NULL) {
    printf("%d, ", tmp->value);
    tmp = tmp->nextItem;
  }
  printf("%d]\n", tmp->value);
  return;
}

static void deleteStructList(list *l) {
  free(l);
  return;
}

void deleteList(list *l) {
  if(l == NULL || l->firstItem == NULL)
    return;
  listItem *tmp = l->firstItem;
  listItem *tmp2;
  while(tmp->nextItem != NULL) {
    tmp2 = tmp->nextItem;
    deleteItem(tmp);
    tmp = tmp2;
  }
  deleteItem(tmp);
  deleteStructList(l);
  printf("deleted successfully\n");
  return;
}