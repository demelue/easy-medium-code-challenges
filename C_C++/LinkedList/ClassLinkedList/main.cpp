#include <stdlib.h>
#include <stdio.h>



class Node
{
private:
  int data;
  Node *next;
public:
  Node(int indata) //constructor
  {
    data = indata;
    next = NULL;
  }

  void append_to_tail(int indata)
  {
    Node *end = new Node(indata);
    Node *n = this;
    while(n->next != NULL)//iterate to end
    {
      n = n->next;
    }
    n->next = end;
  }

  Node* delete_node(int data)
  {
    Node *n = this; //head

    if (n->data == data)//remove from head
    {
      printf("chop off the head\n");
      return n->next;//new head
    }
    else
    {
      while(n->next != NULL)
      {
        if (n->next->data == data) //head didn't change
        {
          n->next = n->next->next;
          return n;
        }
        n = n->next;
      }
    }
    return n;
  }

  void print_list(Node* head)
  {
    Node *t = head;
    int count = 0;
    while (t->next != NULL)
    {
      printf("data: %d | count: %d\n", t->data, ++count);
      t = t->next;
    }
    printf("data: %d | count: %d\n", t->data, ++count);
  }

};

int main(int argc, char const *argv[]) {

  Node *linkedList = new Node(6);
  linkedList->append_to_tail(7);
  linkedList->append_to_tail(8);
  linkedList->print_list(linkedList);
  printf("\n");
  Node* newhead = linkedList->delete_node(6);
  linkedList->print_list(newhead);
  return 0;
}
