#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


int main(int argc, char const *argv[]) {

  Buffer *personA = create_entry(678, 9108734, 'D');
  Buffer *personB = create_entry(503, 6961103, 'H');
  Buffer *personC = create_entry(404, 2701034, 'J');

  ListNode *head = create_node(personA);
  head = add_to_head(head, personC);
  add_to_tail(head, personB);

  print_contacts(head);
  head = remove_from_head(head);
  print_contacts(head);

  return 0;
}
