#include <stdlib.h>
#include <stdio.h>

void test(void)
{
  unsigned int a = 6;
  int b = -8;
  (a+b > 6) ? puts(">6") : puts("<= 6");
  printf("Promotion: %u\n", (a+b));
  printf("Promotion: %d\n", (a+b));
}


int main(int argc, char const *argv[]) {

  // test();
  unsigned int zero = 0;
  uint8_t compzero= 0xFFFF; //wrong on a 32 bit machine
  uint8_t val = 0xABCDEFDC; //what gets stored? depends on endianess. if little endian DC if big endian AB

  printf("%d\n", zero);
  printf("%X\n", val);
  return 0;
}
