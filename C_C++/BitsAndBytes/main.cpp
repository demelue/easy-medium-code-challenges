#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//AtoI implementation
int myAtoi(const char *c)
{
  //Validate character input is not null proceed
  int sign = 1;
  int value = 0;
  if (c[0] == '-')
  {
    sign = -1;
    c++;
  }
  //Validate each character
  while (*c)
  {
    value = (value * 10) + (*c - '0'); //'0' = 48, '1' = 49
    c++;
  }
  return (sign * value);
}

//Substring of bits
//1100101
// i = 2
// j = 4
// M = 111
uint32_t set_bits_in_range (uint32_t M, uint32_t N, uint32_t i, uint32_t j)
{
  uint32_t res = 0;
  if (i == 0 || j == 0)
  {
    res = M | N;
    return res;
  }

  if (i > j)
  {
    res = (M << j) | N;
  }
  else if (j > i)
  {
    res = (M << i) | N;
  }
  return res;
}

//Count set bits using brian kernighan's method (log(n))
//Can also count and set using while(n); count += n & 1; n >>= 1;
int bit_counter(unsigned int input)
{
  int count = 0;
  if (input == 0)
  {
    return 0;
  }
  else
  {
    while (input != 0)
    {
      input = input & (input - 1);
      count++;
    }
  }
  return count;
}

//print smallest and largest number with same number of set bits
void findNextLargeSameSetBits(int input)
{
  int curr_bit_count;
  int n_bit_val = 4;
  int num_set_bits_to_find = bit_counter(input);

  if ((log2(input) +1) > n_bit_val)
  {
    return;
  }
  else
  {
    do
    {
      curr_bit_count = bit_counter(input + 1);
      input++;
    } while(curr_bit_count != num_set_bits_to_find);
  }
  printf("Next largest with same number of set bits %d\n", input);
}

//Find the number of bits to be flipped to convert input a to input b
void num_bits_to_convert_a_to_b(int a, int b)
{
  printf("number of bits to convert a to b: %d\n", bit_counter(a ^ b));
}

//swap even and odd bit positions
void swap_even_odd_bit_pos(int input)
{
  int val = ((input & 0xAAAAAAAA) >> 1);
  val |= ((input & 0x55555555) << 1);
  printf("Swapped output: %d\n", val);
}

//find sum of 2 integers without using + or -
int getSum(int a, int b)
{
  if (b == 0)
  {
    return a;
  }
  else
  {
    return getSum(a^b, (a&b)<<1);
  }
}

#define BITS_IN_BYTE (8)
//reverse bits of an integer
int reverse_bits_v1(uint32_t n)
{
  uint32_t mask = 1;
  uint32_t ret = 0;
  printf("%08X\n", n);
  int i;
  int NO_OF_BITS = sizeof(n)*BITS_IN_BYTE;
  for (i = 0; i < NO_OF_BITS; ++i)
  {
    if (n & (1 << i))
    {
      ret |= (1 << ((NO_OF_BITS - 1) - i));
    }
    // printf("input bit[%d]: %d\n", i, (mask & n)? 1:0);
    // printf("output bit[%d]: %d\n", 31-i, (ret & 1)?1:0);
    ret <<= 1;
    mask <<= 1;
  }
  printf("%08X\n", ret);
  return ret;
}

//Brute Force approach O(n*sizeof(n))
int* count_bits(int num, int* returnSize)
{
  int i;
  int count = 0;
  int curr_val = 0;
  int* output = (int *)malloc(*returnSize * (sizeof(int)));
  for (i = 0; i <= num; i++)
  {
    while(curr_val != 0)
    {
      curr_val = curr_val & (curr_val - 1);
      count++;
    }
    output[i] = count;
    count = 0;
    curr_val = i + 1;
  }
  return output;
}

//Clear last set bit and use already counted value
//counts bits for values 0 - num including num
int* count_set_bits_in_range(int num, int* returnSize)
{
  printf("array size in bytes: %lu\n", *returnSize * sizeof(int));
  int* out = (int*)malloc(*returnSize * (sizeof(int)));
  int i = 0;
  out[i] = 0;
  for (i=1; i <= num; i++)
  {
    //+1 is the cleared bit and out[index] is how many counted for prev number which is 1 - curr num
    out[i] = out[i & (i - 1)] + 1;
  }
  return out;
}


//clockwise rotation
uint32_t clockwise_rotate_bits(uint32_t val, uint32_t rotation)
{
  uint32_t res = 0;
  printf("input: %X\n", val);
  uint32_t total_bits = sizeof(val) * BITS_IN_BYTE; //8 bits in a byte
  res = (val >> rotation) | (val << (total_bits - rotation));
  printf("output: %X\n", res);
  return res;
}

void check_endianessv1(void)
{
  int a = 0xABCDEFDC;
  printf("input: %X\n", a);
  char * byte = (char *)&a;
  printf("a-lsb: %X | byte[0]: %X\n", (a & 0x000000FF), (byte[0] & 0x000000FF));
  if ((byte[0] & 0x000000FF) == (a & 0x000000FF))
  {
    printf("Machine is little Endian\n");
  }
  else
  {
    printf("Machine is big Endian\n");
  }
}
// A union is a special data type available in C that allows to store different
// data types in the same memory location. You can define a union with
// many members, but only one member can contain a value at any given time.
union endianess{
    int val;
    char byte[4];
};

void check_endianessv2(void)
{
  endianess test;
  test.val = 0xABCDEFDC;
  printf("val: %X | byte[0]: %X\n", (test.val & 0x000000FF), (test.byte[0] & 0x000000FF));
  if ((test.byte[0] & 0x000000FF) == (test.val & 0x000000FF))
  {
    printf("Machine is little Endian\n");
  }
  else
  {
    printf("Machine is big Endian\n");
  }

}

typedef enum {GET,SET,CLEAR } STATE;

uint8_t get_set_and_clear_bits(uint8_t value, uint8_t pos, STATE flag)
{
  switch(flag)
  {
    case GET:
      value &= (1 << pos);
      break;
    case SET:
      value |= (1 << pos);
      break;
    case CLEAR:
      value &= ~(1 << pos);
      break;
    default:
      printf("Do nothing\n");
  }

  return value;
}

#define NO_POSSIBLE_CHARS_IN_BYTE (256)
//this technique works for duplicates only....cannot count frequency here
//could also use an array of boolean
void find_duplicates_bit_level_storage_all(const char *data, int size)
{
  // printf("size: %d\n", size);
  uint8_t flags[(NO_POSSIBLE_CHARS_IN_BYTE-1)/BITS_IN_BYTE + 1] = {0};//all characters between 0-255
  //-1 and + 1 ensures numbers divisible by 8 don't use an additional byte
  uint8_t byte_flag = 0;
  uint8_t bit_position = 0;
  for (int i = 0; i < size; i++)
  {
    byte_flag = int(data[i]/BITS_IN_BYTE);
    bit_position = (data[i]%BITS_IN_BYTE);
    // printf("byte flag: %d, bit_position: %d \n",byte_flag, bit_position);
    if (get_set_and_clear_bits(flags[byte_flag], bit_position, GET) == 0)
    {
      flags[byte_flag] = get_set_and_clear_bits(flags[byte_flag], bit_position, SET);
    }
    else
    {
      printf("Duplicate Found: %c\n", data[i]);
    }
  }

  // for (int j = 0; j < (NO_POSSIBLE_CHARS_IN_BYTE - 1)/BITS_IN_BYTE + 1; j++)
  // {
  //   printf("byte_flag: %d\n", flags[j]);
  // }
   return;
}

#define ALPHABET_SET (26) //lower or upper case only
void find_duplicates_bit_level_storage_alphabets(const char *data, int size)
{
  uint8_t flags[(ALPHABET_SET - 1)/BITS_IN_BYTE + 1] = {0}; //-1 and + 1 ensures numbers divisible by 8 don't use an additional byte
  uint8_t byte_flag = 0;
  uint8_t bit_position = 0;
  for (int i = 0; i < size; i++)
  {
    byte_flag = (data[i] - 'a') / BITS_IN_BYTE;
    bit_position = ((data[i] - 'a') % BITS_IN_BYTE);
    // printf("byte flag: %d, bit_position: %d \n",byte_flag, bit_position);
    if (get_set_and_clear_bits(flags[byte_flag], bit_position, GET) == 0)
    {
      flags[byte_flag] = get_set_and_clear_bits(flags[byte_flag], bit_position, SET);
    }
    else
    {
      printf("Duplicate Found: %c\n", data[i]);
    }

  }

  // for (int j = 0; j < (ALPHABET_SET - 1)/BITS_IN_BYTE + 1; j++)
  // {
  //   printf("byte_flag: %d\n", flags[j]);
  // }
   return;
}

char* integer_to_binary_str_padding(int num, int no_of_bits)
{
  int bit_count = no_of_bits;
  int n = num;
  char *out = (char*)malloc(bit_count + 1);//+1 for null terminator
  out[bit_count--] = '\0';
  char tmp;
  while (bit_count >= 0)
  {
    sprintf(&tmp, "%d", n%2);
    out[bit_count] = tmp;
    n /= 2;
    bit_count--;
  }
  printf("%d in binary: ", num);
  int br_count = 0;
  for (int i = 0; i < no_of_bits; i++)
  {
    if (br_count == 4)
    {
      br_count = 0;
      printf(" ");
    }
    printf("%c", out[i]);
    br_count++;
  }
  printf("\n");
  return out;
}

int main(int argc, char const *argv[]) {


  // check_endianessv1();
  // check_endianessv2();
  // traverse_2d_matrix();

  // const char *cdata = "abcdefghijklmnopqrstuvwxyz";
  // find_duplicates_bit_level_storage_all(cdata,strlen(cdata));
  // find_duplicates_bit_level_storage_alphabets(cdata,strlen(cdata));
  int value = 56;
  integer_to_binary_str_padding(value, 32);
  //
  // printf("%d\n", myAtoi("-123");
  // printf("Set bits: %d\n", bit_counter(42);
  // find_next_large_same_set_bits(5);
  // swap_even_odd_bit_pos(56);
  // printf("Sum: %d\n", getSum(5,4);

  // int *count_bits_out;
  // int num = 4;
  // int size = num + 1;
  // count_bits_out = count_set_bits_in_range(num, &size);
  // printf("[");
  // int i;
  // for (i = 0; i < size-1; i++)
  // {
  //   printf("%d,", count_bits_out[i]);
  // }
  // printf("%d]\n", count_bits_out[i]);
  //
  // free (count_bits_out);
  // clockwise_rotate_bits(0x13579BDF, 4);
  // reverse_bits_v1(0x0A);

  // printf("%X\n", change_register_value(0x3457, 0x55AA, false));

  return 0;
}
