#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

#define LIST_A_LEN (5)
#define LIST_B_LEN (2)

int main(int argc, char const *argv[]) {

  //Create 2 linked lists
  int list_a [LIST_A_LEN] = {97, 8, 1, 7, 29};
  int list_b [LIST_B_LEN] = {19, 68};

  node *headA = NULL;
  node *headB = NULL;

  create_linked_list(&headA, list_a, 5);
  create_linked_list(&headB, list_b, 2);

  make_intersection(&headA, &headB, LIST_A_LEN, LIST_B_LEN);

  printf("List A\n");
  print_list(headA);
  printf("List B\n");
  print_list(headB);

  node* output = find_intersection_in_list(headA, headB);
  printf("Intersecting Node: %d\n", output->data);

  printf("Sample Linked List code\n");

  node *n = new node;
  node *h = n;
  node *temp = n;
  n->data = 1;
  for (int i = 1; i < LINKED_LIST_SIZE; i++)
  {
    n = new node;
    n->data = i + 1;
    temp->next = n; //link to next node
    temp = temp->next;
  }
  n->next = NULL;

  print_list(h);


  if(detect_loop_v2(h))
  {
    printf("Linked List is connected\n");
  }
  else
  {
    printf("Linked List is not connected\n");
  }

  //reverse list
  node* newhead = reverse_list(h);

  print_list(newhead);

  return 0;
}
