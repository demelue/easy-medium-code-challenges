#include "linkedlist.h"

int main(int argc, const char* argv [])
{

  node *queue = NULL;
  int *data = NULL;

  push(&queue, 3);
  push(&queue, 8);
  push(&queue, 9);

  print_list(&queue);

  pop(&queue, &data);
  printf("Popped v1: %d\n", *data);
  printf("Popped v2: %d\n", pop(&queue));

  push(&queue, 1);
  push(&queue, 2);
  push(&queue, 3);

  print_list(&queue);

  return 0;
}
