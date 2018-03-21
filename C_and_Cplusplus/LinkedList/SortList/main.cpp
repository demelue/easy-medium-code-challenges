
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

struct node
{
  int data;
  node *next;
};

void printlist(node *p)
{
  printf("List:\n");
  while (p->next != NULL)
  {
    printf("Node: %d\n", p->data);
    p = p->next;
  }
  if (p->next == NULL)
  {
    printf("Node: %d\n", p->data);
  }
}

void simpleLinkedList(node **h, int *inData, int size)
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

node *merge_list(node* l1, node*l2)
{

  printf("function call\n");
  // node *out = (l1->data < l2->data)? l1:l2;
  // node *t2 = (l1->data > l2->data)? l1:l2;
  // node *t1 = out;
  // node *t1prev = NULL;
  // node *t2prev = NULL;
  //
  // while (t1->next != NULL && t2->next != NULL)
  // {
  //   if (t1->data < t2->data)
  //   {
  //     t1prev = t1;
  //     t1 = t1->next;
  //   }
  //   else
  //   {
  //     t2prev = t2;
  //     t1prev->next = t2;
  //     t2 = t2->next;
  //     t1prev = t2prev;
  //   }
  // }
  //
  // if (t2->next == NULL && t2->data < t1->data)
  // {
  //   t2->next = t1;
  // }
  //
  // if (t1->next == NULL && t1->data < t2->data)
  // {
  //   t1->next = t2;
  // }

  return NULL;
}

int main(int argc, char **argv)
{

  // if (argc < 2)
  // {
  //   printf("No input\n");
  //   return -1;
  // }


  //create 2 ll
  node* l1 = NULL;
  node* l2 = NULL;
  int l1_data [] = {1,3,5,12,15};
  int l2_data [] = {6,9,10};
  simpleLinkedList(&l1, l1_data, 5);
  simpleLinkedList(&l2, l2_data, 3);
  printf("l1:\n");
  printlist(l1);
  printf("l2:\n");
  printlist(l2);

  node *ml = merge_list(l1, l2);
  // 
  // printf("ml:\n");
  // printlist(ml);

  return 0;
}
