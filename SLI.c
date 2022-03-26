#include "list.h"

int main(int argc, char *argv[]) {
  if(listInit()) {
    printList();
    listBubbleSort();
    printList();
    findRandomNumber();
    findNumberAtRandomPosition();
    addRandomNumberToOrderedList();
    /* TODO
    deleteRandomNumberFromOrderedList();
    */
    printList();
    deleteList();
  }
  return 0;
}