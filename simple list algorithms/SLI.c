#include "list.h"

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
  printList(l1);
  printMinimumAndItsPosition(l1);
  reverseList(l1);
  removeDuplicates(l1);
  printList(l1);
  deleteList(l1);
  printList(l2);
  printMinimumAndItsPosition(l2);
  reverseList(l2);
  removeDuplicates(l2);
  printList(l2);
  deleteList(l2);
  printList(l3);
  printMinimumAndItsPosition(l3);
  reverseList(l3);
  removeDuplicates(l3);
  printList(l3);
  deleteList(l3);
  printList(l4);
  printMinimumAndItsPosition(l4);
  reverseList(l4);
  removeDuplicates(l4);
  printList(l4);
  deleteList(l4);
  printList(l5);
  printMinimumAndItsPosition(l5);
  reverseList(l5);
  removeDuplicates(l5);
  printList(l5);
  deleteList(l5);
  return 0;
}