#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;
int fibonacci_memoization(int num, int* memo)
{
  if ((num == 1) || (num == 2))
  {
    return 1;
  }
  if (memo[num] == 0)
  {
    memo[num] = fibonacci_memoization((num - 1), memo) + fibonacci_memoization((num - 2), memo);
  }

  return memo[num];
}

int fibonnacci(int num)
{
  int* memo = (int*)calloc((num+1), sizeof(int));
  return fibonacci_memoization(num, memo);
  // if ((num == 1) || (num == 2))
  // {
  //   return 1;
  // }
  // return fibonnacci(num - 1) + fibonnacci(num - 2);
}

//factorial(n) => 4! = 3 x 2 x 1// 3x2x1 = 3! 2x1 = 2! therefore n! = n * (n-1)!
//iterative: start from value count down and multiply 0 and 1 fall through
int factorial(int value)
{
  if (value == 1 || value == 0) //base case
  {
    return 1;
  }
  else
  {
    return value * factorial(value-1); //recursive case
  }
}

int binary_search_iteration(int* data, int size, int value)
{
  int lower = 0;
  int upper = size - 1;
  int middle = 0;

  while (lower < upper)
  {
    middle = (upper - lower)/2;
    if (data[middle] == value) return value;
    else if (value < data[middle])
    {
      upper++;
    }
    else
    {
      lower++;
    }
  }
  return -1;
}

int binary_search(int* data, int lower, int upper, int value)
{
  int middle = ((upper - lower)/2) + lower;
  if (value == data[middle])//base case
  {
    return middle;
  }
  else if (value < data[middle])
  {
    return binary_search(data, lower, upper-1, value);
  }
  else
  {
    return binary_search(data, lower+1, upper, value);
  }
}

int binary_search(int* data, int lower, int upper, int value, int* results, int level)
{
  int middle = ((upper - lower)/2) + lower;
  if (value == data[middle])//base case
  {
    results[level] = middle;
    return middle;
  }
  else if (value < data[middle])
  {
    results[level] = middle;
    return binary_search(data, lower, upper-1, value, results, level + 1);
  }
  else
  {
    results[level] = middle;
    return binary_search(data, lower+1, upper, value, results, level + 1);
  }
}

//binary search on array
void binary_search_all_results(int* data, int lower, int upper, int value, int size)
{
  int *results = new int [size];
  binary_search(data, lower, upper, value, results, 0);
  for (int i = 0; i < size; i++)
  {
    printf("levels %d\n", results[i]);
  }
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;

}

void swap(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;

}

void print_permutation(int* data, int size)
{
  printf("[");
  for (int i = 0; i < size-1; i++)
  {
    printf("%d,", data[i]);
  }
  printf("%d]\n",data[size-1]);
}

void print_permutation(char* data, int size)
{
  printf("[");
  for (int i = 0; i < size-1; i++)
  {
    printf("%c,", data[i]);
  }
  printf("%c]\n",data[size-1]);
}

void string_permuation(int* input, int size)
{
  int j = 0;
  for (int i = 0; i < factorial(size); i++)
  {
    print_permutation(input, size);
    swap(&input[j], &input[j+1]);
    j++;

    if (j == size-1)
    {
      j = 0;
    }
  }
}

void string_permuation(char* input, int size)
{
  int j = 0;
  for (int i = 0; i < factorial(size); i++)
  {
    print_permutation(input, size);
    swap(&input[j], &input[j+1]);
    j++;

    if (j == size-1)
    {
      j = 0;
    }
  }
}

void string_permuation_recurse(char* input, int i, int size)
{
  if (i == size)
  {
    print_permutation(input,size);
    return;
  }
  else
  {
    for (int j = i; j < size; j++)
    {
      swap(input + i, input + j);
      string_permuation_recurse(input, i + 1, size);
      swap(input + i, input + j);
    }
  }
}

//Use map add each to map and check if exist in map before printing
void string_permuation_duplicates_recurse(char* input, int i, int size)
{
  return;
}

// curr_max = 3
// curr_action = 3
// curr_step = 3
// num_action = 2
// k_step = 2

int jumping_jack_util(int curr_max, int num_action, int curr_action, int k_step, int curr_step)
{
  if (curr_action > num_action)
  {
    // printf("curr_step: %d curr_max: %d curr_action: %d\n", curr_step, curr_max, curr_action);
    if (curr_step > curr_max)
      curr_max = curr_step;
  }
  else
  {
    if (curr_action == 1)
    {
      // printf("step 0 pause curr_action: %d\n", curr_action);
      curr_max = jumping_jack_util(curr_max, num_action, curr_action + 1, k_step, curr_step);
    }

    if ((curr_step + curr_action) != k_step)
    {
      // printf("curr_action: %d\n", curr_action);
      curr_max = jumping_jack_util(curr_max, num_action, curr_action + 1, k_step, curr_step + curr_action);
    }
    else
    {
      // printf("pause curr_action: %d\n", curr_action);
      curr_max = jumping_jack_util(curr_max, num_action, curr_action + 1, k_step, curr_step);
    }

  }
  return curr_max;
}

void jumping_jack(int k_step, int action)
{
  int max_step = jumping_jack_util(0, action, 1, k_step, 0);
  printf("Max Step: %d\n", max_step);
  // jumping_jack_util(action, 1, k_step, 0);
}

void get_factors_util(int start, int n, vector<vector<int> > &out, vector<int> &path)
{
  // printf("i: %d n: %d\n", start, n);
  for (int i = start; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      path.push_back(i);
      path.push_back(n/i);
      out.push_back(path);
      path.pop_back();//pop n/i out because we need to choose it for next recursion but still a factor
      get_factors_util(i, n/i, out, path);
      path.pop_back();
    }
  }
}

void get_factors(int n)
{
  vector<vector<int> > result;
  if (n <= 3)
  {
    printf("[[ ]]\n");
  }
  vector<int> path;
  get_factors_util(2, n, result, path);
  int i, j;
  printf("{\n");
  for (i = 0; i < result.size(); i++)
  {
    printf("[");
    for (j = 0; j < result[i].size()-1; j++)
    {
      printf("%d,", result[i][j]);
    }
    printf("%d]\n",result[i][j]);
  }
  printf("}\n");
}


class power_set
{
  vector<vector<int> > output;
  vector<int> input;
public:
  power_set(vector<int> &data)
  {
    input = data;
  }

  void print_power_set(void)
  {
    vector<int> tlist;
    print_power_set_util(tlist, 0);
  }
private:
  void print_list(vector<int> &data)
  {
    printf("[");
    for (int i = 0; i < data.size(); i++)
    {
      printf("%d",data[i]);
    }
    printf("]\n");
  }

  void print_power_set_util(vector<int> &tlist, int start)
  {
    print_list(tlist);
    for (int i = start; i < input.size(); i++)
    {
      tlist.push_back(input[i]);
      print_power_set_util(tlist, i + 1);
      tlist.pop_back();
    }
  }
};


//Combination sum
void print_combination_list(vector<int> &list)
{
  printf("[");
  for (int i = 0; i < list.size(); i++)
  {
    printf("%d", list[i]);
  }
  printf("]\n");
}

void combination_sum_util(int *data, int size, int target, vector<int> &tlist, int start)
{
  if (target < 0)
  {
    return;
  }
  else if (target == 0)
  {
    print_combination_list(tlist);
  }
  else
  {
    int i = start;
    while (i < size)
    {
      tlist.push_back(data[i]);
      //+1 means for each time the same number cannot be used several times to find target
      combination_sum_util(data, size, target - data[i], tlist, i + 1);
      tlist.pop_back();
      i++;
    }
  }
}

void combination_sum(int* data, int size, int target)
{
  vector<int> tlist;
  combination_sum_util(data, size, target, tlist, 0);
}

//One dice roll
void print_dice_roll(vector<int> &list)
{
  printf("[");
  for (int i = 0; i < list.size(); i++)
  {
    printf("%d", list[i]);
  }
  printf("]\n");
}

void dice_roll_util(int dice, vector<int> &tlist)
{
  if (dice == 0)
  {
    print_dice_roll(tlist);
  }
  else
  {
    int i = 1;
    while (i < 6)
    {
      tlist.push_back(i);
      dice_roll_util(dice - 1, tlist);
      tlist.pop_back();
      i++;
    }
  }
}

void dice_roll(int dice)
{
  vector <int> tlist;
  dice_roll_util(dice, tlist);
}

bool is_palindrome(vector<char> &list)
{
  return false;
}

void print_list(vector<char> &data, int start)
{
  for (int i = start; i < data.size(); i++)
  {
    printf("%c",data[i]);
  }
  printf("\n");
}

void substring_util(vector<char> &list, int start)
{
  if (start == list.size())
  {
    return;
  }
  print_list(list, 0);
  substring_util(list, tlist, start + 1);
}

void substring(vector<char> &list)
{
  int start = 0;
  vector<char> tlist;
  substring_util(list, start);
}

// int count = 0;
// 
//   public int countSubstrings(String s) {
//       if (s == null || s.length() == 0) return 0;
//
//       for (int i = 0; i < s.length(); i++) { // i is the mid point
//           extendPalindrome(s, i, i); // odd length;
//           extendPalindrome(s, i, i + 1); // even length
//       }
//
//       return count;
//   }
//
//   private void extendPalindrome(String s, int left, int right) {
//       while (left >=0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
//           count++; left--; right++;
//       }
//   }

int main(int argc, char const *argv[]) {
  // int a = 4;
  // printf("%d\n", factorial(a));
  // printf("fibonnacci: %d\n",fibonnacci(a));
  // int data [] = {0,1,2,4,5,6,7};
  // printf("value %d value: %d\n", data[binary_search(data,0,7,4)], binary_search_iteration(data,7,4));
  // binary_search_all_results(data, 0, 5, 1, 5);

  // int input[] = {1,2,3};
  // int size = sizeof(input)/sizeof(int);
  // string_permuation(input,size);

  // int size = 3;
  // char* input = (char*)malloc(sizeof(size + 1));
  // for (int i = 0; i < size; i++)
  // {
  //   input[i] = 97 + i;
  // }
  // input[size] = '\0';
  // printf("input %s\n", input);
  //
  // string_permuation(input, size);
  // char input[3] = {'a','a','b'};
  // string_permuation_recurse(input, 0, 3);

  // jumping_jack(2,2);
  // jumping_jack(1,2);
  // jumping_jack(3,3);
  // jumping_jack(4,4);
  // jumping_jack(3,4);
  // int m = 3;
  // int n = 3;
  // printf("%d\n", factorial(m-1 + n-1)/(factorial(m-1) * factorial(n-1)));

  // get_factors(78);
  // vector<int> values;
  // values.push_back(1);
  // values.push_back(2);
  // values.push_back(3);
  // power_set test_obj = power_set(values);
  // test_obj.print_power_set();

  // int data[6] = {1,3,9,5,4,2};
  // combination_sum(data, 6, 8);

  // dice_roll(2);

  // char* in_str = "abc";
  vector<char> in_list;
  in_list.push_back('a');
  in_list.push_back('a');
  in_list.push_back('a');
  substring(in_list);

  return 0;
}
