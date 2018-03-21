#include <stdlib.h>
#include <stdio.h>


class max_binary_heap
{
protected:
  int *heap;
  int capacity;
  int size;
public:
  max_binary_heap(int max_length)
  {
    capacity = max_length;
    heap = new int[max_length];
    size = 0;
  }

  void swap(int *x, int *y)
  {
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
  }

  bool insert(int data)
  {
    if (size == capacity) return false;
    int pos = size;
    heap[pos] = data;
    int parent;
    while (pos > 0)
    {
      parent = ((pos + 1)/2) - 1;
      if (heap[pos] <= heap[parent]) break;
      swap(&heap[pos], &heap[parent]);
      pos = parent;
    }
    size++;
    return true;
  }

  int extract(void)
  {
    if (size == 0) return 0; //empty
    int result = heap[0];
    heap[0] = heap[size-1];
    size --;
    int pos = 0;
    int left, right;
    while (pos < (size/2))
    {
      left = (2*pos) + 1;
      right = left + 1;
      //validate right child
      if (right < size && heap[right] >= heap[left])
      {
        if (heap[pos] >= heap[right]) break;
        swap(&heap[pos], &heap[right]);
        pos = right;
      }
      else
      {
        if (heap[pos] >= heap[left]) break;
        swap(&heap[pos], &heap[left]);
        pos = left;
      }
    }
    return result;
  }

  int peek(void)
  {
    if (size == 0) return 0;
    return heap[0];
  }

  void print_heap(void)
  {
    for (int i = 0; i < size; i++)
    {
      printf("%d\n", heap[i]);
    }
  }
};

class min_binary_heap : public max_binary_heap
{
public:
  min_binary_heap(int max_length)
  : max_binary_heap(max_length)
  {
    capacity = max_length;
    heap = new int[max_length];
    size = 0;
  }

  //Override function in base class
  bool insert(int data)
  {
    if (size == capacity) return false;
    int pos = size;
    heap[pos] = data;
    int parent;
    while (pos > 0)
    {
      parent = ((pos + 1)/2) - 1;
      if (heap[pos] >= heap[parent]) break;
      swap(&heap[pos], &heap[parent]);
      pos = parent;
    }
    size++;
    return true;
  }

  //Override function in base class
  int extract(void)
  {
    if (size == 0) return -1; //empty
    int result = heap[0];
    heap[0] = heap[size-1];
    size --;
    int pos = 0;
    int left, right;
    while (pos < (size/2))
    {
      left = (2*pos) + 1;
      right = left + 1;
      //validate right child
      if (right < size && heap[right] <= heap[left])
      {
        if (heap[pos] <= heap[right]) break;
        swap(&heap[pos], &heap[right]);
        pos = right;
      }
      else
      {
        if (heap[pos] <= heap[left]) break;
        swap(&heap[pos], &heap[left]);
        pos = left;
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {


  // max_binary_heap h = max_binary_heap(10);
  // h.insert(1);
  // h.insert(2);
  // h.insert(9);
  // h.insert(4);
  // h.print_heap();
  // printf("extracted: %d\n",h.extract());
  // printf("extracted: %d\n" , h.extract());
  // printf("\n");
  // h.print_heap();
  //
  min_binary_heap hmin = min_binary_heap(10);
  hmin.insert(10);
  hmin.insert(20);
  hmin.insert(2);
  hmin.insert(0);
  hmin.insert(-10);
  hmin.insert(-20);
  hmin.print_heap();
  printf("extracted: %d\n",hmin.extract());
  printf("extracted: %d\n" , hmin.extract());
  printf("\n");
  hmin.print_heap();
  printf("peek: %d\n", hmin.peek());

  // int val = 0;
  // while(val != -1)
  // {
  //   val = hmin.extract();
  //   if (val > 0)
  //   {
  //     val --;
  //     break;
  //   }
  // }
  //
  // if (val == -1)
  // {
  //   printf("all values are negative\n");
  // }
  // else
  // {
  //   printf("Missing val: %d\n", val);
  // }

  // int data[] = {3,2,1,6,0,5};
  // max_binary_heap root = max_binary_heap(10);
  // for(int i = 0; i < sizeof(data)/sizeof(int); i++)
  // {
  //   root.insert(data[i]);
  // }
  // root.print_heap();
  return 0;
}
