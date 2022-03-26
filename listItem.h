#ifndef LIST_ITEM_H
#define LIST_ITEM_H
typedef struct listItem {
  int value;
  struct listItem *nextItem;
} listItem;

listItem *itemConstructor(int);
void deleteListItem();

#endif