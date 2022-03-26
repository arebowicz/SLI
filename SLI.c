#include "list.h"

int stoi(char *);
bool listAction(int, int);

/* return -1 if some error ocurred */
/* return  0 if everything's fine  */
int main(int argc, char *argv[]) {
  if(argc == 3) {
    int listSize = stoi(argv[1]);
    int maxNumber = stoi(argv[2]);
    if(listSize == -1 || maxNumber == -1)
      return -1;
    return listAction(listSize, maxNumber) ? 0 : -1;
  }
  return -1;
}

int stoi(char *s) {
  int result = 0;
  while(*s != '\0') {
    if(*s >= '0' && *s <= '9')
      result = result * 10 + (*s - '0');
    else
      return -1;
    ++s;
  }
  return result;
}

bool listAction(int listSize, int maxNumber) {
  if(listInit(listSize, maxNumber) == true) {
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
    return true;
  }
  return false;
}