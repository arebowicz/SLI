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
  if(l->firstItem->nextItem == NULL)
    return;
  listItem *tmp = l->firstItem;   /* this one (tmp) will be "new last" */
  listItem *tmp2;
  while(tmp->nextItem != NULL) {
    tmp2 = tmp->nextItem;
    tmp->nextItem = tmp2->nextItem;
    tmp2->nextItem = l->firstItem;
    l->firstItem = tmp2;
  }
  return;
}