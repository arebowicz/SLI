#include "list.h"

int main(int argc, char *argv[]) {
  if(listInit()) {
    printList();
    listBubbleSort();
    printList();
    findRandomNumber();
    deleteList();
  }
  return 0;
}