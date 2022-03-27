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

/* returns added list number */
static int addToLists(list *l) {
  if(lists->list == NULL) {
    lists->list = l;
    return 1;
  }
  int i = 1;
  listOfLists *tmp = lists;
  while(tmp->nextList != NULL) {
    tmp = tmp->nextList;
    ++i;
  }
  tmp->nextList = listsConstructor();
  tmp->nextList->list = l;
  return ++i;
}

void newList(int listSize, int maxValue) {
  list *l = listConstructor(listSize, maxValue);
  listInit(l);
  if(lists == NULL)
    lists = listsConstructor();
  printf("list no. %d succesfully created\n", addToLists(l));
  return;
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
  return;
}

void sortAllLists() {
  listOfLists *tmp = lists;
  int i = 0;
  while(tmp->nextList != NULL) {
    printf("list no. %d ", ++i);
    listBubbleSort(tmp->list);
    tmp = tmp->nextList;
  }
  printf("list no. %d ", ++i);
  listBubbleSort(tmp->list);
  return;
}

void addRandomNumberToEachOrderedList() {
  listOfLists *tmp = lists;
  int i = 0;
  while(tmp->nextList != NULL) {
    printf("list no. %d: ", ++i);
    addRandomNumberToOrderedList(tmp->list);
    tmp = tmp->nextList;
  }
  printf("list no. %d: ", ++i);
  addRandomNumberToOrderedList(tmp->list);
  return;
}

void sumAllValues() {
  listOfLists *tmp = lists;
  int i = 0;
  while(tmp->nextList != NULL) {
    printf("list no. %d: sum of all values = %d\n", ++i, sumValues(tmp->list));
    tmp = tmp->nextList;
  }
  printf("list no. %d: sum of all values = %d\n", ++i, sumValues(tmp->list));
  return;
}