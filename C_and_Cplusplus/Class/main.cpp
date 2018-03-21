#include "lib.h"

int main(int argc, char const *argv[]) {
  NumberList mylist;
  int len = 4;
  mylist.init(len);
  mylist.addSample(3);
  mylist.addSample(4);
  mylist.addSample(5);
  mylist.addSample(6);

  uint16_t *ptrList = mylist.getSamples();
  mylist.printList();
  // mylist.destroy();
  free(ptrList);

  return 0;
}
