#include "list.h"

static void listAction(list *);

int main (int argc, char *argv[]) {
  list *l1 = listConstructor();
  list *l2 = listConstructor();
  list *l3 = listConstructor();
  list *l4 = listConstructor();
  list *l5 = listConstructor();
  strToList("1", l1);
  strToList("1 1", l2);
  strToList("1 2 3", l3);
  strToList("1 2 3 1 2 3 1 2 3", l4);
  strToList("1 2 3 3 3 3 33 3 3 3 3", l5);
  listAction(l1);
  listAction(l2);
  listAction(l3);
  listAction(l4);
  listAction(l5);
  return 0;
}

static void listAction(list *l) {
  printList(l);
  printMinimumAndItsPosition(l);
  reverseList(l);
  removeDuplicates(l);
  printList(l);
  deleteList(l);
  printf("\n");
}