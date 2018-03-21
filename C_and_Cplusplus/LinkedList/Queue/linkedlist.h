
#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  node *next;
};

//print linked List
void print_list (node** h)
{
  node *m = *h;
  while (m->next != NULL)
  {
    printf("Node: %d\n", m->data);
    m = m->next;
  }
  printf("Node: %d\n", m->data);
}

void push(node **h, int data)
{
  if (*h == NULL)
  {
    *h = new node;
    (*h)->data = data;
    (*h)->next = NULL;
  }
  else
  {
    node *t = new node;
    t->data = data;
    t->next = *h;
    *h = t;
  }
}

int pop(node **h)
{
  int value = 0 ;

  if (*h == NULL)
  {
    printf("Queue is empty\n");
  }
  else
  {
    node *t = *h;
    node *tprev;
    while (t->next != NULL)
    {
      tprev = t;
      // printf("prev value: %d\n", tprev->data);
      t = t->next;
      // printf("current value: %d\n", t->data);
    }
    tprev->next = NULL;
    value = t->data;
    free (t);
  }
  return value;
}

void pop(node **h ,int **value)
{
  if (*h == NULL)
  {
    printf("Queue is empty\n");
  }
  else
  {
    node *t = *h;
    node *tprev;
    while (t->next != NULL)
    {
      tprev = t;
      // printf("prev value: %d\n", tprev->data);
      t = t->next;
      // printf("current value: %d\n", t->data);
    }
    *value = &t->data;
    tprev->next = NULL;
    free (t);
  }
}
