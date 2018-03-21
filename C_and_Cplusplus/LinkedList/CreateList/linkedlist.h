
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

#define LINKED_LIST_SIZE 10

struct node
{
  int data;
  node *next;
};

//print linked List
void print_list (node *h)
{
  node *m = h;
  while (m->next != NULL)
  {
    printf("Node: %d\n", m->data);
    m = m->next;
  }
  printf("Node: %d\n", m->data);
}

bool detect_loop_v2(node *h)
{
  if (h == NULL) return false;
  node *slowPtr = h;
  node *fastPtr = h->next;
  while (fastPtr != NULL && fastPtr->next != NULL)
  {
    if (fastPtr == slowPtr) return true;
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
  }
  return false;
}

//reverse singly linked list
node* reverse_list(node *h)
{
  node *prev = h;
  node *t = prev;
  node *curr = NULL;

  if (h == NULL) return NULL;

  if (h->next)
  {
    curr = h->next;
  }
  else
  {
    return NULL;
  }

  while(curr->next != NULL)
  {
    prev = curr;
    curr = curr->next;
    prev->next = t;
    t = prev;
  }
  curr->next = prev;
  h->next = NULL;
  h = curr;
  return h;
}

void create_linked_list(node **h, int *inData, int size)
{
  node *n = new node;
  n->data = inData[0];
  node *temp = n;
  *h = n;
  int i;
  for (i = 1; i < size; i++)
  {
    n = new node;
    n->data = inData[i];
    temp->next = n; //link to next node
    temp = temp->next;
  }
  temp->next = NULL;
}

void make_intersection(node** listA, node** listB, int sizeA, int sizeB)
{
  node *short_list = NULL;
  node *long_list = NULL;
  if (sizeA < sizeB)
  {
    short_list = *listA;
    long_list = *listB;
  }
  else
  {
    short_list = *listB;
    long_list = *listA;
  }

  while(short_list->next != NULL)
  {
    short_list = short_list->next;
    long_list = long_list->next;
  }

  short_list->next = long_list;
}

node* find_intersection_in_list(node *headA, node* headB)
{
  node *currA = headA, *currB = headB;
  while(currA != currB)
  {
    currA = currA ? currA->next : headB;
    currB = currB ? currB->next : headA;
  }
  return currA;
}
