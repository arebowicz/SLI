#include "listItem.h"

listItem *itemConstructor(int value) {
  listItem *item = (listItem *) malloc(sizeof(listItem));
  item->value = value;
  item->nextItem = NULL;
  return item;
}

void deleteItem(listItem *item) {
  free(item);
  return;
}