#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int myAtoi(char *c)
{
  int sign = 1;
  int value = 0;
  if (c[0] == '-')
  {
    sign = -1;
    c++;
  }

  while (*c)
  {
    value = (value * 10) + (*c - '0'); //'0' = 48, '1' = 49
    c++;
  }
  return (sign * value);
}

//Whats the range?
//handle negative?
#define UNIQUE_NUMERALS (13)
void print_roman_numeral(int num)
{
  char* numerals [UNIQUE_NUMERALS] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int values [] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  // string roman_numeral;

  if (num > 3999 || num < 1)
  {
    printf("out of range\n");
    return;
  }

  int i = 0;
  int diff = 0;
  while (num > 0)
  {
    diff = num - values[i];
    if (diff >= 0)
    {
      printf("%s", numerals[i]);
      num -= values[i];
    }
    else
    {
      i++;
    }
  }
  printf("\n");
}

void clockAngle(const char *current_time)
{
  char* hr_str = (char *) malloc(sizeof(char));
  char* mins_str = (char *) malloc(sizeof(char));
  int index = 0;
  int i = 0;
  while (*(current_time + index) != ':')
  {
    hr_str[i++] = *(current_time + index);
    index++;
  }
  printf("%s\n", hr_str);
  index++; //skip quotes
  i = 0;
  while(*(current_time + index))
  {
    mins_str[i++] = *(current_time + index);
    index++;
  }
  printf("%s\n", mins_str);
  int hours = myAtoi(hr_str);
  int mins = myAtoi(mins_str);

  int thirty_deg_counts = (mins/5.0);
  double angle = abs(thirty_deg_counts - hours) * 30;
  printf("%0.1f\n", angle);
}

#define MIN(A,B) ((A) <= (B) ? (A) : (B))
#define MIN_WRONG(A,B) A <= B ? A : B
#define SECONDS_IN_A_YEAR (60 * 60 * 24 * 365)

#ifdef MIN_WRONG
// #error Wrong min is defined //NOTE mark a location of an error
#endif

int reverse_integer_v1(int value)
{
  int output = 0;
  int sign = 1;
  if (value < 0)
  {
    sign = -1;
    value *= sign;
  }

  while (value != 0)
  {
    // output *= 10;
    output = (output * 10) + (value % 10);
    value /= 10;
  }

  return (output * sign);
}

void swap(char* a, char*b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

int reverse_integer_v2(int value)
{
  char *buf = (char *)malloc(sizeof(char));
  sprintf(buf,"%d",value);//null terminating
  int start_index = 0;
  int stop_index = strlen(buf) - 1;
  if (value < 0)
  {
    start_index = 1;
  }
  while(start_index < stop_index)
  {
    swap(buf + start_index, buf + stop_index);
    start_index++;
    stop_index--;
  }

  return myAtoi(buf);
}

// N % 9 = N[0]*1 + N[0]*10 +..+ N[n]*10^k
// mod properties
// (a+b)%m = (a%m)+(b%m)
// (a*b)%m = ((a%m)*(b%m))%m
// (a%m)%m = (a%m)
int calc_sum_of_digits(int value)
{
  return (value-1)%9 + 1;//-1 and +1 to account for 9%9 == 0 therefore 8%9 = 8 + 1 = 9
}

void sizing_test_cpp(void)
{
  char a1[4] = {'a','b','c','\0'};
  char a2[9] = {'a','b','c','d','e','f','g','h','\0'};
  char b1[]  = "abc";
  char b2[]  = "abcdefgh";
  const char* c1   = "abc";
  const char* c2   = "abcdefgh";

   printf("a1:%s is size: %lu\n",a1,sizeof(a1));//4
   printf("a2:%s is size: %lu\n",a2,sizeof(a2));//9
   printf("b1:%s is size: %lu\n",b1,sizeof(b1));//4
   printf("b2:%s is size: %lu\n",b2,sizeof(b2));//9
   printf("c1:%s is size: %lu\n",c1,sizeof(c1));//8
   printf("c2:%s is size: %lu\n",c2,sizeof(c2));//8
}

int main(int argc, char const *argv[]) {
  int number = 1132;
  print_roman_numeral(number);
  // clockAngle("3:40");
  // int a = 7;
  // int b = 0;
  // int *ptr = &a;
  // b = MIN(*ptr++, 10); //errorneous
  // printf("seconds in a year: %d\n", SECONDS_IN_A_YEAR);
  // printf("min : %d\n", MIN(*ptr,5) * 5);
  // printf("min : %d\n", MIN_WRONG(*ptr,5) * a); //errorneous NOTE: importance of parenthesis
  // printf("b: %d\n", b);

  // int d = 8;
  // const int *e = &d;//the integer isn't modifiable, but the pointer is
  // printf("e: %d\n", *e);
  // // *e = a;//errorneous cannot change value via dereferencing
  // e = &a; //valid
  // printf("e: %d\n", *e);

  // int *const c = &a; //the integer pointed to by a is modifiable, but the pointer is not //int const == const int
  // printf("c: %d\n", *c);
  // *c = a; //valid
  // // c = &d; //errorneous
  // printf("c: %d\n", *c);

  // const int* const f  = &a; //Neither is modifiable
  // // f = &d; //errorneous
  // // *f = d; //errorneous
  // printf("f: %d\n", *f);

  // sizing_test_cpp();


  int test_value = -123;
  // printf("Reverse input v1: %d, output: %d\n",value,reverse_integer_v1(test_value));
  printf("Reverse input v2: %d, output: %d\n",test_value,reverse_integer_v2(test_value));
  // int value = 0;
  // printf("Enter value: \n");
  // scanf("%d", &value);
  // printf("sum of %d = %d\n",value, calc_sum_of_digits(value));
  return 0;
}
