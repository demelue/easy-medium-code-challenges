#include <stdlib.h>
#include <stdio.h>

#define STACK_LEN (10)

class min_stack
{
private:
  int sp;
  int min_sp;
  uint8_t *stack;//[STACK_LEN];

public:
  min_stack(int size)
  {
    sp = STACK_LEN - 1;
    min_sp = sp;
    stack = new uint8_t[size];
  }

  void push(uint8_t data)
  {
    if (sp < 0)
    {
      printf("stack is full \n");
      return;
    }

    if (data < stack[min_sp])
    {
      min_sp = sp;
    }
    stack[sp--] = data;
  }

  uint8_t pop (void)
  {
    if (sp == (STACK_LEN - 1))
    {
      printf("stack is empty\n");
      return 0;
    }
    if ((sp + 1) == min_sp) //need to recalculate min NOTE: can be improved by keeping a min_sp stack as well
    {
      uint8_t t = stack[sp + 2];
      for (int j = sp + 2; j < STACK_LEN; j++)
      {
        if (stack[j] <= t)
        {
          t = stack[j];
          min_sp = j;
          printf("new min: %u | new min_sp: %d\n", t, min_sp);
        }
      }
    }
    sp++;
    stack[sp] = 0;
    return stack[sp];
  }

  uint8_t min(void)
  {
    if (sp == (STACK_LEN - 1))
    {
      printf("stack is empty\n");
      return 0;
    }
    return stack[min_sp];
  }

  void print_stack(void)
  {
    for (int i = 0; i < STACK_LEN; i++)
    {
      printf("%u\n", stack[i]);
    }
  }

};

int main(int argc, char const *argv[]) {

  min_stack mystack = min_stack(STACK_LEN);

  // mystack.pop();
  mystack.push(4);
  mystack.push(5);
  mystack.push(3);
  mystack.push(2);
  mystack.push(1);
  mystack.print_stack();
  mystack.pop();
  printf("current min %u\n", mystack.min());
  // mystack.pop();
  // mystack.pop();
  // mystack.pop();
  // mystack.pop();
  // mystack.pop();
  mystack.print_stack();

  return 0;
}
