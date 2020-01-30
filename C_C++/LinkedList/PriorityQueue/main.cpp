#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    int priority;
    node *next;
};

void addToQueueHead(node **head, int data, int priority)
{
  node* t = new node;
  t->data = data;
  t->priority = priority;
  t->next = *head;
  *head = t;
}

void addToQueue(node **head,int data, int priority)
{
  if (*head == NULL)
  {
    addToQueueHead(head,data,priority);
    return;
  }
  else
  {
    node *t = *head;
    if (priority >= t->priority)//higher priority at the top of queue
    {
      addToQueueHead(head, data, priority);
      return;
    }
    else//middle case
    {
      while(t->next != NULL)
      {
        if (priority >= t->next->priority)
        {
          node *m = new node;
          m->data = data;
          m->priority = priority;
          m->next = t->next;
          t->next = m;
          return;
        }
        else
        {
          t = t->next;
        }
      }

      if (priority < t->priority)//smallest priority at the end of queue
      {
        node* endNode = new node;
        endNode->data = data;
        endNode->priority = priority;
        t->next = endNode;
        endNode->next = NULL;
      }
    }
  }
}

void printQueue(node **head)
{
  node* current = *head;
  int count = 0;
  while(current->next != NULL)
  {
    count ++;
    printf("Data: %d | priority: %d\n", current->data, current->priority);
    current = current->next;
  }
  printf("Data: %d | priority: %d\n", current->data, current->priority);
  printf("Count: %d\n", count + 1);
}

int main(int argc, char const *argv[])
{

  node* priorityQueue = NULL;
  addToQueue(&priorityQueue, 2, 29);
  addToQueue(&priorityQueue, 3, 51);
  addToQueue(&priorityQueue, 1, 3);
  addToQueue(&priorityQueue, 5, 45);

  printQueue(&priorityQueue);

  // printf("The Max weight: %d\n", knapSack(&priorityQueue, 5));

  return 0;
}
