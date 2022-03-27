#include "listOfLists.h"

int stoi(char *);
void listAction(int, int, int);

/* arg vector is clearly described */
/* by variable names               */
int main(int argc, char *argv[]) {
  if(argc == 4) {
    int numberOfLists = stoi(argv[1]);    /* first argv  */
    int singleListSize = stoi(argv[2]);   /* second argv */
    int maxValue = stoi(argv[3]);         /* third argv  */
    if(numberOfLists != -1 && singleListSize != -1 && maxValue != -1)
      listAction(numberOfLists, singleListSize, maxValue);
  }
  return 0;
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

void listAction(int numberOfLists, int singleListSize, int maxValue) {
  if(numberOfLists == 0 || singleListSize == 0 || maxValue == 0)
    return;
  srand(time(NULL));
  while(--numberOfLists >= 0)
    newList(singleListSize, maxValue);
  printAllLists();
  sortAllLists();
  printAllLists();
  addRandomNumberToEachOrderedList();
  printAllLists();
  sumAllValues();
  deleteAllCreatedLists();
}