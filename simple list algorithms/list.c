#include "list.h"

list *listConstructor() {
  list *l = (list *) malloc(sizeof(list));
  if(l == NULL)
    return NULL;
  l->firstItem = NULL;
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

/* str is a sequence of numbers */
/* characters: '0' to '9' and ' ' (spaces) */
void strToList(char *str, list *l) {
  int value;
  while(*str != '\0') {
    value = 0;
    while(*str != ' ' && *str != '\0') {
      value = value*10 + (*str-'0');
      ++str;
    }
    addItem(l, itemConstructor(value));
    if(*str == ' ')
      ++str;
  }
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
  printf("list successfully deleted\n");
  return;
}

void reverseList(list *l) {
  if(l == NULL || l->firstItem == NULL)
    return;
  if(l->firstItem->nextItem == NULL) {
    printf("list reversed!\n");
    return;
  }
  listItem *tmp = l->firstItem;   /* this one (tmp) will be "new last" */
  listItem *tmp2;
  while(tmp->nextItem != NULL) {
    tmp2 = tmp->nextItem;
    tmp->nextItem = tmp2->nextItem;
    tmp2->nextItem = l->firstItem;
    l->firstItem = tmp2;
  }
  printf("list reversed!\n");
  return;
}

void printMinimumAndItsPosition(list *l) {
  if(l == NULL || l->firstItem == NULL)
    return;
  if(l->firstItem->nextItem == NULL) {
    printf("found minimum %d at position %d\n", l->firstItem->value, 1);
    return;
  }
  int i, j, min;
  min = l->firstItem->value;
  i = j = 1;
  listItem *tmp = l->firstItem;
  while(tmp->nextItem != NULL) {
    if(tmp->value < min) {
      min = tmp->value;
      j = i;
    }
    tmp = tmp->nextItem;
    ++i;
  }
  printf("found minimum %d at position %d\n", min, j);
  return;
}

/*
  it looks soo complicate...
  maybe I'll fix it later
  (but it works well!)
*/
void removeDuplicates(list *l) {
  if(l == NULL || l->firstItem == NULL)
    return;
  listItem *tmp = l->firstItem;
  listItem *tmp2, *tmp3;
  tmp2 = tmp3 = NULL;
  while(tmp->nextItem != NULL) {
    tmp3 = tmp;
    tmp2 = tmp->nextItem;
    do {
      if(tmp->value == tmp2->value) {
        tmp3->nextItem = tmp2->nextItem;
        deleteItem(tmp2);
        tmp2 = tmp3;
      }
      tmp3 = tmp2; /* reduntant if above condition (tmp->value == tmp2->value) true, but necessary */
      tmp2 = tmp2->nextItem;
    } while (tmp2 != NULL);
    tmp = tmp->nextItem;
    if(tmp == NULL)
      break;
  }
  printf("duplicates removed!\n");
  return;
}