#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct _data
{
  int area_code;
  int phone_number;
  char name;
}Buffer;

typedef struct _node
{
  Buffer *info;
  struct _node *next;
}ListNode;

Buffer* create_entry(int area_code, int number, char name)
{
  Buffer* temp_person = (Buffer*) malloc(sizeof(Buffer));
  temp_person->area_code = area_code;
  temp_person->phone_number = number;
  temp_person->name = name;
  return temp_person;
}

ListNode* create_node(Buffer* new_info)
{
  ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
  temp->info = new_info;
  temp->next = NULL;
  return temp;
}

void print_contacts(ListNode* head)
{
  ListNode* temp = head;
  while (temp->next != NULL)
  {
    printf("Name: %c Number: %d%d\n", temp->info->name, temp->info->area_code, temp->info->phone_number);
    temp = temp->next;
  }
  printf("Name: %c Number: %d%d\n", temp->info->name, temp->info->area_code, temp->info->phone_number);
}

ListNode* add_to_head(ListNode* head, Buffer *new_info)
{
  ListNode *temp = create_node(new_info);
  if (head == NULL)
  {
    return temp;
  }
  temp->next = head;
  head = temp;
  return head;
}

bool add_to_tail(ListNode* head, Buffer *new_info)
{
  ListNode* temp = create_node(new_info);
  if (head == NULL)
  {
    return false;
  }
  ListNode *iter = head;

  while(iter->next != NULL)
  {
    iter = iter->next;
  }
  iter->next = temp;
  return true;
}

ListNode* remove_from_head(ListNode* head)
{
  if (head == NULL)
  {
    return head;
  }
  if (head->next != NULL)
  {
    ListNode* new_head = head->next;
    free(head);
    return new_head;
  }
  else
  {
    return NULL;
  }
}

bool remove_node(ListNode* head, char name)
{
  return false;
}
