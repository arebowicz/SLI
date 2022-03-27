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
  if(l == NULL)
    return;
  if(l->firstItem == NULL) {
    l->firstItem = item;
    return;
  }
  listItem *tmp = l->firstItem;
  while(tmp->nextItem != NULL)
    tmp = tmp->nextItem;
  tmp->nextItem = item;
  return;
}

void listInit(list *l) {
  if(l == NULL)
    return;
  int i = 0;
  while(++i <= l->listSize)
    addItem(l, itemConstructor(rand()%(l->maxValue+1)));
  return;
}

void printList(list *l) {
  if(l == NULL)
    return;
  if(l->firstItem == NULL) {
    printf("[]\n");
    return;
  }
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

static void swap(listItem *item1, listItem *item2) {
  if(item1 == NULL || item2 == NULL)
    return;
  int tmp;
  if(item1->value > item2->value) {
    tmp = item1->value;
    item1->value = item2->value;
    item2->value = tmp;
  }
  return;
}

/*
  ascending sorting
*/
void listBubbleSort(list *l) {
  if(l == NULL || l->firstItem == NULL)
    return;
  listItem *item1 = l->firstItem;
  listItem *item2 = NULL;
  while(item1->nextItem != NULL) {
    item2 = l->firstItem;
    while(item2->nextItem != NULL) {
      swap(item2, item2->nextItem);
      item2 = item2->nextItem;
    }
    item1 = item1->nextItem;
  }
  printf("successfully sorted\n");
  return;
}

/*
  maybe that implementation is too complicated?
  I'll try again later...
*/
static void addItemToOrderedList(list *l, listItem *item) {
  if(l->firstItem == NULL) {
    printf("there is no list... but we're going to create one\n");
    l->firstItem = item;
    return;
  } else if (item == NULL)
    return;
  listItem *tmp = l->firstItem;     /* tmp is one position too far */
  listItem *tmp2 = l->firstItem;    /* so tmp2 precedes tmp */
  int i = 1;                        /* i is for tmp2 position */
  while(item->value > tmp->value) { /* searching for position */
    if(tmp->nextItem == NULL)
      break;
    tmp = tmp->nextItem;
    if(++i>2)
      tmp2 = tmp2->nextItem;
  }
  if(i == 1) {
    if(item->value <= l->firstItem->value) {
      item->nextItem = l->firstItem;
      l->firstItem = item;
    } else { /* list could have only 1 item... */
      item->nextItem = NULL;
      l->firstItem->nextItem = item;
      ++i;
    }
  } else if (tmp->nextItem == NULL && item->value > tmp->value) { /* we reached the end... */
    item->nextItem = NULL;
    tmp->nextItem = item;   /* item is now at the end of our list */
    ++i;
  } else {
  item->nextItem = tmp2->nextItem;
  tmp2->nextItem = item;
  }
  ++l->listSize;
  printf("random value %d added at position %d\n", item->value, i);
  return;
}

void addRandomNumberToOrderedList(list *l) {
  if(l == NULL)
    return;
  listItem *tmp = itemConstructor(rand()%(l->maxValue+1));
  if(tmp == NULL)
    return;
  addItemToOrderedList(l, tmp);
  return;
}

int sumValues(list *l) {
  if(l == NULL)
    return 0;
  int sum = 0;
  listItem *tmp = l->firstItem;
  while(tmp->nextItem != NULL) {
    sum += tmp->value;
    tmp = tmp->nextItem;
  }
  sum += tmp->value;
  return sum;
}