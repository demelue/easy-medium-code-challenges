#include <stdlib.h>
#include <stdio.h>

#define M (4)
#define N (4)
int matrix[M][N] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
// int matrix[M][N] = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};

void print_full_matrix(int row, int col)
{
  int *rowptr = NULL;
  int i, j;
  for (i = 0; i < row; i++)
  {
    rowptr = matrix[i];
    printf("[");
    for (j = 0; j < col-1; j++)
    {
      printf("%d,", *(rowptr + j));
    }
    printf("%d]\n", *(rowptr + j));
  }
}

void print_diagonal()
{
  int *colptr = NULL;
  int i = 0;
  while (i < M)
  {
    colptr = matrix[i];
    printf("%d\n", *(colptr + i));
    i++;
  }
}

void change_diagonal()
{
  int *colptr = NULL;
  int i = 0;
  while (i < M)
  {
    colptr = matrix[i];
    *(colptr + i) += i;
    i++;
  }
}

void traverse_2d_matrix()
{
  print_full_matrix(M, N);
  print_diagonal();
  change_diagonal();
  print_full_matrix(M,N);
}

bool matrix_search(int matrix[M][N], int val)
{
  int row = 0;
  int col = N - 1;//(sizeof(matrix[0])/sizeof(int)) - 1;//matrix[0].length() - 1;

  while(row < N && col >= 0)
  {
    if (val == matrix[row][col])
    {
      return true;
    }
    if (val > matrix[row][col])
    {
      row++;
    }
    else
    {
      col--;
    }
  }
  return false;
}

bool can_jump(int* nums, int numsSize) {
    int reachable = 0;
    int i = 0;
    while (i < numsSize)
    {
        printf("reachable: %d, iterations: %d\n",reachable,i);
        if (i > reachable) return false;
        if (reachable == numsSize - 1) return true;
        reachable = (reachable > (i + nums[i]))? reachable : (i + nums[i]);
        i++;
    }
    printf("reachable: %d, iterations: %d\n",reachable,i);
    return true;
}

//Bad code but prints 0-4
void test_func()
{
  int a,b;
  for (a = 0, b = 0; a < 10, b < 5; a++, b++)
  {
    printf("%d, %d\n",a,b);
  }
}

int main(int argc, char const *argv[]) {
  // printf("%d\n", matrix_search(matrix, 202));

  // int data[] = {2,3,1,1,4};
  // int data[] = {3,2,1,0,4};
  // int data[] = {1};
  // int data[] = {0};
  // int size = sizeof(data)/sizeof(int);
  // printf("jump game status: %d\n", can_jump(data,size));

  // test_func();
  return 0;
}
