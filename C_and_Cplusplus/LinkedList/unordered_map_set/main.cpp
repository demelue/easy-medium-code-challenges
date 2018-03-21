#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;



int main(int argc, char const *argv[]) {

  map<char, int> char_map;
  map<char, int>::iterator it;
  char word[] = "poison";
  for (int j = 0; j < strlen(word); j++)
  {
    it = char_map.find(word[j]);
    if (it == char_map.end())
    {
      char_map[word[j]] = j;
      printf("%d\n", j);
    }
    else
    {
      printf("Found duplicate at index %d\n", j);
      break;
    }
  }

  return 0;
}
