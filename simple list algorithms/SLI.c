#include "list.h"

int main (int argc, char *argv[]) {
  list *l = listConstructor();
  strToList("1 2 3", l);
  printList(l);
  reverseList(l);
  printList(l);
  deleteList(l);
  return 0;
}