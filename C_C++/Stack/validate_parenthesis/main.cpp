// Write function that validates a bracket string
// Examples:
// isValidBracketPhrase(“[[][]]”) -> true
// isValidBracketPhrase(“[[]]]”) -> false
// isValidBracketPhrase(“[[]]]”) -> false
// [][]][
//
// stack =
// index = 4
// outputFlag = true;
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool isValidBracketPhrase(const char* input)
{
    bool outputFlag = false;
    int index = 0;
    int pseudo_stack = 0;

    if (*(input + index) == ']')
    {
        return false;
    }
    pseudo_stack++;
    index++;
    while (index < strlen(input))
    {

        if (*(input + index) == ']')
        {
            if (pseudo_stack == 0) return false;
            pseudo_stack--;
        }
        else
        {
            pseudo_stack++;
        }
        index++;
    }

    if (pseudo_stack == 0)
    {
        outputFlag = true;
    }
    return outputFlag;
}

int main(int argc, char const *argv[]) {
  const char* input = "[[[]]";
  if (isValidBracketPhrase(input))
    printf("Valid\n");
  else
    printf("Invalid\n");
  return 0;
}
