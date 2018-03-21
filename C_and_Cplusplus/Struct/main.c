#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define BIT_COUNT (8)

typedef struct _eight_bit_reg
{
  bool bits[BIT_COUNT];
}REG;

typedef enum {FALSE = 0, TRUE = 1} Boolean;

#define BYTE_COUNT (8)
struct _size
{
  double a;//8
  int *b;//4 or 8 depending on 32 or 64 bit machine
  char values[BYTE_COUNT];//8*1
};

struct _book {
  // char* name;
  uint8_t current_page;
  uint8_t page_count;
};

#define BOOK_PTR struct _book * //Not recommended because if we did BOOK_PTR a,b only a is a pointer b is a struct
typedef struct _book *book_ptr; //recommended

void sizing_test_c(void)
{
  char a1[4] = {'a','b','c','\0'};
  char a2[9] = {'a','b','c','d','e','f','g','h','\0'};
  char b1[]  = "abc";
  char b2[]  = "abcdefgh";
  const char* c1   = "abc";
  const char* c2   = "abcdefgh";

   printf("a1:%s is size: %lu\n",a1,sizeof(a1));//3
   printf("a2:%s is size: %lu\n",a2,sizeof(a2));//8
   printf("b1:%s is size: %lu\n",b1,sizeof(b1));//3
   printf("b2:%s is size: %lu\n",b2,sizeof(b2));//8
   printf("c1:%s is size: %lu\n",c1,sizeof(c1));//8
   printf("c2:%s is size: %lu\n",c2,sizeof(c2));//8
}

void print_struct_fields(void *test_struct)
{
  struct _size *input = (struct _size*)test_struct;

  printf("a: %0.2f\n", input->a);
  printf("b: %d\n", *input->b);

}

int main(int argc, char const *argv[]) {

  // struct _book notebook = {.page_count = 5, .current_page = 0};
  // printf("page count: %d | current page: %d\n", notebook.page_count, notebook.current_page);
  //
  // book_ptr current_book = &notebook;
  // printf("page count: %d | current page: %d\n", current_book->page_count, current_book->current_page);
  //
  // notebook.page_count = 123;
  // notebook.current_page = 100;
  //
  // printf("page count: %d | current page: %d\n", current_book->page_count, current_book->current_page);
  //
  // BOOK_PTR current_book_v2 = current_book;
  //
  // printf("page count: %d | current page: %d\n", current_book_v2->page_count, current_book_v2->current_page);
  //
  // // REG status = {{false, false, false, false, false, false, false, false}};

  struct _size mystruct;
  mystruct.a = 0.345;
  int m = 21;
  mystruct.values[0] = 'x';
  struct _size *ptr = &mystruct;
  ptr->b = &m;
  print_struct_fields(ptr);

  int test_arr[4] = {1,2,3,4};
  int *test_ptr = test_arr;
  for (int i = 0; i < 4; i++)
  {
    printf("a: %d\n", *test_arr + i);
    printf("ptr++: %d\n", *test_ptr++);
  }

  // printf("size: %lu\n", sizeof(mystruct));
  // printf("values: %d\n", *ptr->b);
  // printf("values: %f\n", mystruct.a);
  // printf("values: %c\n", mystruct.values[0]);
  // Boolean statusFlag = TRUE;
  // printf("%d\n", statusFlag);

  // sizing_test_c();

  return 0;
}
