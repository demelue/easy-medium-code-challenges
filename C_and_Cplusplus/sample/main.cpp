#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_BITS_HALFADDR (4)
#define NO_BITS_FULLADDR (8)

struct bin_value
{
  char* value;
  int carry_in;
};

int char_to_digit(char c)
{
  if (c == '1')
  {
    return 1;
  }
  else if (c == '0')
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

//4-bit Half adder
int half_adder(const char* a, const char* b, bin_value* output)
{
  if ((strlen(a) != strlen(b)) || (strlen(a) != NO_BITS_HALFADDR) || (strlen(b) != NO_BITS_HALFADDR))
  {
    printf("Unequal length or not a 4 bit string....try again\n");
    return -1;
  }

  int index = strlen(a)-1;
  int carry_out = 0;
  int bit_a = 0;
  int bit_b = 0;
  int carry_in = output->carry_in;
  char *sum = (char*)malloc(sizeof(char) * NO_BITS_HALFADDR);

  while (index >= 0)
  {
    bit_a = char_to_digit(a[index]);
    bit_b = char_to_digit(b[index]);

    if (bit_a == -1 || bit_b == -1)
    {
      printf("Binary strings only. input(a: %c, b: %c)..try again\n",a[index],b[index]);
      return -1;
    }

    //calculating the sum
    if ((bit_a ^ bit_b) == false)
    {
      if (carry_in == 1)
      {
        sum[index] = '1';
      }
      else
      {
        sum[index] = '0';
      }
    }
    else
    {
      if (carry_in == 1)
      {
        sum[index] = '0';
      }
      else
      {
        sum[index] = '1';
      }
    }

    //update carry_in for next digit
    if (carry_in == 0)
    {
      carry_out = bit_a & bit_b;
    }
    else
    {
      carry_out = bit_a | bit_b;
    }

    printf("The bits are %d and %d. The Carry in is %d. The sum is %c. The carry out is %d\n", bit_a, bit_b, carry_in, sum[index],carry_out);
    carry_in = carry_out;
    index --;
  }
  output->carry_in = carry_out;
  output->value = sum;
  return 0;
}

//8-bit full adder
void full_adder(const char* a, const char* b)
{
  if ((strlen(a) != strlen(b)) || (strlen(a) != NO_BITS_FULLADDR) || (strlen(b) != NO_BITS_FULLADDR))
  {
    printf("Unequal length or not an 8 bit string....try again\n");
    return;
  }

  char *four_bit_str_a = (char*) malloc(sizeof(char) * NO_BITS_HALFADDR);
  char *four_bit_str_b = (char*) malloc(sizeof(char) * NO_BITS_HALFADDR);

  int four_bit_index = NO_BITS_HALFADDR - 1;
  int eight_bit_index = NO_BITS_FULLADDR - 1;
  while (four_bit_index >= 0)
  {
    four_bit_str_a[four_bit_index] = a[eight_bit_index];
    four_bit_str_b[four_bit_index] = b[eight_bit_index];
    four_bit_index --;
    eight_bit_index --;
  }

  bin_value *half_adder_output = (bin_value *) malloc(sizeof(bin_value));
  half_adder_output->carry_in = 0;

  int status = half_adder(four_bit_str_a, four_bit_str_b, half_adder_output);
  if (status == 0)
  {
    printf("output: %s carry out %d\n", half_adder_output->value, half_adder_output->carry_in);
    char * adder_a = half_adder_output->value;
    //copy the second 4 bits
    four_bit_index = eight_bit_index;
    while(four_bit_index >= 0)
    {
      four_bit_str_a[four_bit_index] = a[eight_bit_index];
      four_bit_str_b[four_bit_index] = b[eight_bit_index];
      four_bit_index --;
      eight_bit_index --;
    }
    status = half_adder(four_bit_str_a, four_bit_str_b, half_adder_output);
    if (status == 0)
    {
      printf("output: %s carry out %d\n", half_adder_output->value, half_adder_output->carry_in);
      printf("answer is %s %s\n", half_adder_output->value, adder_a);
    }
    else
    {
      printf("There was an error\n");
      free(four_bit_str_a);
      free(four_bit_str_b);
      free(half_adder_output);
      return;
    }
  }
  else
  {
    printf("There was an error\n");
    free(four_bit_str_a);
    free(four_bit_str_b);
    free(half_adder_output);
    return;
  }
  free(four_bit_str_a);
  free(four_bit_str_b);
  free(half_adder_output);
}

int main(int argc, char const *argv[])
{

  if (argv[1] == NULL || argv[2] == NULL)
  {
    printf("NO INPUTS ENTERED\n");
    return -1;
  }

  full_adder(argv[1],argv[2]);
}
