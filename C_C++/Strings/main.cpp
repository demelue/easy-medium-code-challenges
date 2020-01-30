#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

int generic_atoi(const char *str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-');
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

//AtoI implementation
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


uint8_t xor_string(char* input)
{
  int index = 0;
  char xor_val = *(input + index);
  index++;
  // uint8_t temp = 0;
  while (index < strlen(input))
  {
    // temp = *(input + index);
    xor_val ^= *(input + index);
    index++;
  }
  return xor_val;
}

//NOTE: xor doesn't always WORK
void anagram_check(char* inputStr1, char* inputStr2)
{
  if (strlen(inputStr1) != strlen(inputStr2))
  {
    printf("Not Anagrams\n");
    return;
  }
  else
  {
    if (xor_string(inputStr1) ^ xor_string(inputStr2))
    {
      printf("Not Anagrams\n");
    }
    else
    {
      printf("Anagrams\n");
    }
  }
}

void palindrome_check(const char* inputStr)
{
  int len = strlen(inputStr);
  int i = 0;
  int j = len-1;

  while(inputStr[i] == inputStr[j])
  {
    if (i > j)
    {
      printf("Palindrome\n");
      return;
    }
    i++;
    j--;
  }
  printf("Not Palindrome\n");
}

char* decompress(const char *input)
{
  int length = strlen(input);
  int i;
  if (input[0] == '#')
  {
    return NULL;
  }

  char last_character;
  char *output = (char *) malloc(length * sizeof(char));

  for (i=0; i < length; i++)
  {

    printf("%c\n",input[i]);
    if (((input[i] > 'a') && (input[i] < 'z')) || (input[i] == '.') || (input[i] == '\n') || (input[i] == '#'))
    {
      output[i] = input[i];
       if (input[i] == '#')
       {
         if (input[i - 1] != '#')
         {
           last_character = input[i - 1];
         }
         output[i] = last_character;
       }
    }
    else
    {
      return NULL;
    }
  }
  output[length] = '\0';

  // for (int j=0; j < length; j++)
  // {
  //   printf("%c\n", output[j]);
  // }
  return output;
}

#define NO_OF_CHARS (256)
void find_duplicates_in_string(char* inputStr)
{
  int bin_hash[NO_OF_CHARS] = {0};
  int input_index = 0, res_index = 0;
  uint8_t temp = 0;

  while(*(inputStr + input_index))
  {
    temp = *(inputStr + input_index);
    // printf("current index %d\n", temp);

    if (bin_hash[temp] == 0)
    {
      bin_hash[temp] = 1;
      res_index++;
    }
    else
    {
      printf("duplicate %c at index %d\n", *(inputStr + input_index), input_index);
    }
    input_index++;
  }
}

char* insert_character(const char* input, char char_to_insert)
{
  char* output = (char*) malloc(sizeof(char) * strlen(input));
  int index = 0;

  while (index < strlen(input))
  {
    if (input[index] == ' ')
    {
      output[index] = char_to_insert;
    }
    else
    {
      output[index] = input[index];
    }
    index++;
  }
  output[strlen(input)] = '\0';
  return output;
}

//string compressor
//input: aabcccaaa
//output: a2b1c3a3
char* string_compressor(const char* input)
{
  char* output = (char*) malloc(sizeof(char));
  int index = 0, count = 1;
  char current_char = *(input + index);
  char temp_buf[3];
  index++;
  while(index < strlen(input))
  {
    if (current_char == *(input + index))
    {
      count++;
    }
    else
    {
      sprintf(temp_buf, "%c%d", current_char, count);
      strcat(output, temp_buf);
      count = 1;
      current_char = *(input + index);
    }
    index ++;
  }

  sprintf(temp_buf, "%c%d", current_char, count);
  strcat(output, temp_buf);
  return output;
}

//reverse a string
char* reverse_a_string(char* input)
{
  char* output = (char*) malloc(strlen(input));
  int index = strlen(input) - 1;
  int outdex = 0;

  while(index >= 0)
  {
    output[outdex++] = *(input + index);
    index --;
  }
  output[outdex] = '\0';
  return output;
}

void reverse_in_place(char** input, int size)
{
  int start = 0;
  int stop = size - 1;
  char temp = 0;
  while(start < stop)
  {
    temp = *(*input + start);
    *(*input + start) = *(*input + stop);
    *(*input + stop) = temp;
    start++;
    stop--;
  }
}

char* reverse_in_placeV2(char* input, int size)
{
  int start = 0;
  int stop = size - 1;
  char temp = 0;
  while(start < stop)
  {
    temp = *(input + start);
    *(input + start) = *(input + stop);
    *(input + stop) = temp;
    start++;
    stop--;
  }
  return input;
}

void print_array_of_strings(const char **input, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("word[%d]: %c\n", i, *input[i]);
  }
}

int main(int argc, char const *argv[]) {
  // anagram_check((char*)argv[1], (char*)argv[2]);
  // palindrome_check(argv[1]);
  find_duplicates_in_string((char*) argv[1]);

  // printf("%s\n", decompress("he##lo"));
  // char* comp_out = string_compressor("aabcccaaa");
  // printf("%s\n", comp_out);
  // free(comp_out);

  // char* insert_out = insert_character("Mr John Smith", '3');
  // printf("Char to insert: %s\n", output);
  // free(output);

  // char* rev_output = reverse_a_string((char *)"the quick brown fox");
  // printf("Reversed string: %s\n", rev_output);
  // free(rev_output);

  // char* input = (char *)"mouse";
  // int size = strlen(input);
  // char* rev_input_ptr = (char*)malloc(size);
  //
  // for (int i = 0; i < size; i++)
  //   rev_input_ptr[i] = input[i];
  // reverse_in_place(&rev_input_ptr, size);
  // printf("Reversed in place string: %s\n", rev_input_ptr);
  // free(rev_input_ptr);

  // printf("%s\n",reverse_in_placeV2(rev_input_ptr, size));
  // const char* word_list[3] = {"house", "mouse", "spouse"};
  // print_array_of_strings(word_list, 3);

  return 0;
}
