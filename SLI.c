#include "list.h"

int main(int argc, char *argv[]) {
  if(listInit()) {
    printList();
    listBubbleSort();
    printList();
    deleteList();
  }
  return 0;
}