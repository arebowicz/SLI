#include "listOfLists.h"

static listOfLists *lists = NULL;

static listOfLists *listsConstructor() {
  listOfLists *tmp = (listOfLists *) malloc(sizeof(listOfLists));
  if(tmp == NULL)
    return NULL;
  tmp->list = NULL;
  tmp->nextList = NULL;
  return tmp;
}

static void addToLists(list *l) {
  if(lists->list == NULL) {
    lists->list = l;
    return;
  }
  listOfLists *tmp = lists;
  while(tmp->nextList != NULL)
    tmp = tmp->nextList;
  tmp->nextList = listsConstructor();
  tmp->nextList->list = l;
}

void newList(int listSize, int maxValue) {
  list *l = listConstructor(listSize, maxValue);
  listInit(l);
  if(lists == NULL)
    lists = listsConstructor();
  addToLists(l);
}

static void deleteListOfListsItem(listOfLists *l) {
  free(l);
  return;
}

void deleteAllCreatedLists() {
  listOfLists *tmp = lists;
  listOfLists *tmp2;
  int i = 0;
  while(tmp->nextList != NULL) {
    tmp2 = tmp->nextList;
    printf("list no. %d ", ++i);
    deleteList(tmp->list);
    deleteListOfListsItem(tmp);
    tmp = tmp2;
  }
  printf("list no. %d ", ++i);
  deleteList(tmp->list);
  deleteListOfListsItem(tmp);
  return;
}

void printAllLists() {
  listOfLists *tmp = lists;
  int i = 0;
  while(tmp->nextList != NULL) {
    printf("list no. %d: ", ++i);
    printList(tmp->list);
    tmp = tmp->nextList;
  }
  printf("list no. %d: ", ++i);
  printList(tmp->list);
}