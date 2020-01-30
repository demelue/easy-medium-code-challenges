#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_CHARS (26)
//use for prefix and suffix search
struct TrieNode
{
  TrieNode *children[ALPHABET_CHARS];
  bool end_of_word;
};

TrieNode* get_node(void) //creates a node
{
  TrieNode *pNode = (TrieNode *)malloc(sizeof(TrieNode));

  if (pNode)
  {
    for(int i = 0; i < ALPHABET_CHARS; i++)
    {
      pNode->children[i] = NULL;
    }
    pNode->end_of_word = false;
  }
  return pNode;
}

bool add_word(TrieNode* root, const char* word)
{
  TrieNode *temp = root;
  int char_index;
  for (int index = 0; index < strlen(word); index++)
  {
    char_index = word[index] - 'a';
    //to handle upper case check if word[index] in range 65 - 90 A - Z and add 32 to switch to lower case
    // printf("%d\n", char_index);
    if (temp->children[char_index] == NULL)
    {
      temp->children[char_index] = get_node();
    }
    temp = temp->children[char_index];
  }
  temp->end_of_word = true;
  return true;
}

bool search (TrieNode* root, const char* word)
{
  if (root == NULL)return false;

  TrieNode *temp = root;
  int char_index;
  for (int i = 0; i < strlen(word); i++)
  {
    char_index = word[i] - 'a';
    // printf("%d\n", char_index);
    if (temp->children[char_index] == NULL)
    {
      // printf("null at %c\n", word[i]);
      return false;
    }
    temp = temp->children[char_index];
  }

  if ((temp != NULL) && (temp->end_of_word))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int string_similarity(const char *word)
{
  // create root
  TrieNode *root = get_node();

  //add the word into the Trie
  add_word(root, word);
  //
  // if (search(root, word))
  // {
  //   printf("Found\n");
  // }

  TrieNode *tmp;

  int i,j;
  int similarity_count = 0;
  int total_similarity_count = strlen(word);
  int char_index = 0;
  j = 1;


// input = "ababaa" "babaa" "abaa" "baa" "aa" "a"
// i = 2
// j = 2
// sc = 0
// tsc = 0


  for (i = 1; i < strlen(word); i++)
  {
    similarity_count = 0;
    tmp = root;
    j = i;
    while (j < strlen(word))
    {
      // printf("%d\n", j);
      char_index = word[j] - 'a';
      if (tmp->children[char_index] != NULL)
      {
        similarity_count++;
        tmp = tmp->children[char_index];
      }
      else
      {
        // printf("Break: %c\n", *(word + j));
        break;
      }
      j++;
    }
    total_similarity_count += similarity_count;
  }
  free(root);
  return total_similarity_count;
}

int main(int argc, char const *argv[]) {

  // TrieNode *root = get_node();
  // printf("%d\n", add_word(root, "house"));
  // printf("%d\n", search(root, "house"));
  // printf("%d\n", search(root, "mouse"));
  //
  // free(root);

  printf("Total Suffix Similarity: %d\n", string_similarity("ababaa"));
  printf("Total Suffix Similarity: %d\n", string_similarity("aa"));
  printf("Total Suffix Similarity: %d\n", string_similarity("bbaba"));

  return 0;
}
