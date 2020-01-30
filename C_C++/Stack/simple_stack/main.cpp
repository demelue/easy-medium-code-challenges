#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 10

class Stack
{
private:
  char* stack;
  int stack_position;
  int max_size;

public:
  Stack(int size)
  {
    stack = new char[size];
    stack_position = size - 1;
    max_size = size;
  }

  void push(char value)
  {
    printf("Stack position: %d\n", stack_position);
    if (stack_position < 0)
    {
      printf("stack is full\n");
      return;
    }
    stack[stack_position--] = value;
  }

  char pop()
  {
    printf("Stack position: %d\n", stack_position);
    if ((stack_position + 1) == max_size)
    {
      printf("stack is empty\n");
      return 0;
    }
    stack_position++;
    int ret = stack[stack_position];
    stack[stack_position] = 0;
    return ret;
  }

  bool isEmpty(void)
  {
    if ((stack_position + 1) == max_size) return true;
    return false;
  }

  void printStack()
  {
    printf("current %d\n", stack_position);
    // if (stack_position < 0) stack_position = 0;
    for(int i = stack_position; i < max_size; i++)
    {
      printf("%c\n", stack[i]);
    }
  }
};

int add_chars(char a, char b)
{
  return (a - '0') + (b - '0');
}

char* add_two_strings_v2(const char* num1, const char* num2)
{
  return NULL;
}

char* add_two_strings(const char* num1, const char* num2)
{
  Stack stack1 = Stack(SIZE);
  Stack stack2 = Stack(SIZE);
  Stack output = Stack(SIZE);
  //Update this to recursively call with smaller one on one side?

  int len1 = 0;
  int len2 = 0;

  while (len1 < strlen(num1))
  {
    stack1.push(*(num1 + len1));
    len1++;
  }

  while(len2 < strlen(num2))
  {
    stack2.push(*(num2 + len2));
    len2++;
  }

  int length = 0;
  if (len1 > len2)
  {
    length = len1;
  }
  else
  {
    length = len2;
  }

  int i = 0;
  int rem = 0;
  int tmp = 0;
  char *buf = (char*)malloc(sizeof(char));
  char a;
  char b;
  int outlen = 0;

  // stack1.printStack();
  // stack2.printStack();

  while (i < length)
  {
    if (stack1.isEmpty())
      a = '0';
    else
      a = stack1.pop();

    if (stack2.isEmpty())
      b = '0';
    else
      b = stack2.pop();

    tmp = rem + add_chars(a,b);
    if (tmp > 9)
    {
      rem = tmp/10;
      tmp %= 10;
    }
    else
    {
      rem = 0;
    }
    sprintf(buf,"%d",tmp);
    // printf("buf %c\n", *buf);
    output.push(*buf);
    outlen++;
    i++;
  }
  printf("rem: %d\n", rem);
  if (rem == 1)
  {
    sprintf(buf, "%d", rem);
    output.push(*buf);
    outlen++;
  }

  // output.printStack();

  char* str_out = (char*)malloc(outlen);
  while(!output.isEmpty())
  {
    *buf = output.pop();
    strcat(str_out, buf);
  }
  free(buf);
  return str_out;
}

class StackInteger
{
private:
  int* stack;
  int stack_position;
  int max_size;

public:
  StackInteger(int size)
  {
    stack = new int[size];
    stack_position = size - 1;
    max_size = size;
  }

  void push(int value)
  {
    // printf("Stack push position: %d\n", stack_position);
    if (stack_position < 0)
    {
      printf("stack is full\n");
      return;
    }
    stack[stack_position--] = value;
  }

  int pop()
  {
    if ((stack_position + 1) == max_size)
    {
      printf("stack is empty\n");
      return 0;
    }
    // printf("Stack pop position: %d\n", stack_position);
    int ret = stack[++stack_position];
    stack[stack_position] = 0;
    return ret;
  }

  bool isEmpty(void)
  {
    if ((stack_position + 1) == max_size) return true;
    return false;
  }

  void printStack()
  {
    // printf("current position %d\n", stack_position);
    // if (stack_position < 0) stack_position = 0;
    for(int i = stack_position + 1; i < max_size; i++)
    {
      printf("%d\n", stack[i]);
    }
  }
};

class Queue
{
private:
  int top;
  int current_size;
  int capacity;
  StackInteger stack1;
  StackInteger stack2;
public:
  Queue(int size):stack1(size),stack2(size)
  {
    top = 0;
    current_size = 0;
    capacity = size;
  }

  void push(int value)
  {
    if (current_size == capacity)
    {
      printf("Queue is full\n");
      return;
    }
    if (stack1.isEmpty() && stack2.isEmpty())
    {
      // printf("First value %d\n",value);
      stack1.push(value);
      top = value;
    }
    else if (!stack2.isEmpty())
    {
      // printf("added to second stack\n");
      stack2.push(value);
    }
    else if (!stack1.isEmpty())
    {
      // printf("added to first stack %d\n",value);
      stack1.push(value);
    }
    else
    {
      printf("Error\n");
    }
    current_size++;
  }

  int pop()
  {
    int result;
    int count = current_size - 1;
    printf("current size: %d\n",current_size);
    if(!stack1.isEmpty())
    {
      while(count > 0)
      {
        result = stack1.pop();
        stack2.push(result);
        count--;
      }
      top = result;
      result = stack1.pop();
      current_size--;

      while(count < current_size)
      {
        stack1.push(stack2.pop());
        count++;
      }
      return result;
    }
    else
    {
      printf("Queue is Empty\n");
      return 0;
    }
  }

  int peek()
  {
    return top;
  }

  bool isEmpty()
  {
    if (stack1.isEmpty() && stack2.isEmpty())
    {
      return true;
    }
    return false;
  }

  void print_queue()
  {
    printf("current queue:\n");
    if (stack1.isEmpty())
    {
      stack2.printStack();
    }
    else
    {
      stack1.printStack();
    }
  }
};

int main(int argc, char const *argv[]) {
  // StackInteger test = StackInteger(3);
  // test.push(1);
  // test.push(2);
  // test.push(3);
  // for (int i = 0; i < 3; i++)
  // {
  //   printf("popped values %d\n",test.pop());
  // }
  // printf("%s\n", add_two_strings("123", "456"));

  // Test Queue
  // Queue myqueue = Queue(3);
  // printf("Queue empty? %s\n", myqueue.isEmpty()? "yes":"no");
  // myqueue.push(1);
  // myqueue.push(2);
  // myqueue.push(3);
  // myqueue.print_queue();
  // printf("Peek: %d\n", myqueue.peek());
  // printf("Queue Pop: %d\n", myqueue.pop());
  // printf("Peek: %d\n", myqueue.peek());
  // printf("Queue Pop: %d\n", myqueue.pop());
  // printf("Peek: %d\n", myqueue.peek());
  // printf("Queue empty? %s\n", myqueue.isEmpty()? "yes":"no");
  return 0;
}
