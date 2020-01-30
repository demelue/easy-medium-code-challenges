#include <stdlib.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define MAX(A,B) ((A) > (B) ? (A) : (B))

struct node
{
    int lower;
    int upper;
    node *left;
    node *right;
    int max;
};

struct BstNode
{
  int data;
  BstNode *left;
  BstNode *right;
};

BstNode * CreateNode(int data)
{
  BstNode* newNode = (BstNode *)malloc(sizeof(BstNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}
//log(n)
BstNode* InsertNode(BstNode* root, int data)
{
  if (root == NULL)
  {
    root = CreateNode(data);
  }
  else if (data < root->data)
  {
    root->left = InsertNode(root->left, data);
  }
  else
  {
    root->right = InsertNode(root->right, data);
  }
  return root;
}

//nlog(n)
int Search_v1(BstNode* root, int data)
{
  if (root == NULL || root->data == data)
  {
    if (root == NULL)
      return 0;
    else
      return 1;
  }
  else if (data <= root->data)
  {
    return Search_v1(root->left, data);
  }
  else
  {
    return Search_v1(root->right, data);
  }
}

//iterative
int Search_v2(BstNode* root, int data)
{
  while (root != NULL)
  {
    if (data < root->data)
    {
      root = root->left;
    }
    else if (data > root->data)
    {
      root = root->right;
    }
    else
    {
      return 1;
    }
  }
  return 0;
}

int findMax(BstNode* root)
{
  BstNode* current = root;
  if (root == NULL)
  {
    return 0;
  }
  while (current->right != NULL)
  {
    current = current->right;
  }
  return current->data;
}

int findMin(BstNode* root)
{
  BstNode* current = root;
  if (root == NULL)
  {
    return 0;
  }
  else
  {
    while (current->left != NULL)
    {
      current = current->left;
    }
    return current->data;
  }
}

//Path sum by recursion
bool find_path_sum(BstNode* root, int sum)
{
  if (root == NULL)
  {
    return false;
  }
  //base case
  if (root->right == NULL && root->left == NULL && sum - root->data == 0)//characteristic of a leaf left = right = null
  {
    return true;
  }
  //recursive case
  else
  {
    return find_path_sum(root->right, sum - root->data) || find_path_sum(root->left, sum - root->data);
  }
}

// bool is_node_valid(BstNode* root, int min, int max)
// {
//   if (root == NULL) return false;
//   if (min != -1 && min >= root->data) return false;
//   if (max != -1 && max <= root->data) return false;
//   return is_node_valid(root->left, min, root->data) && is_node_valid(root->right, root->data, max);
//   return false;
// }
//
// int count_node(BstNode *root)
// {
//   if (root == NULL) return 0;
//   if (root->left == NULL && root->right == NULL) return 1;
//   else  return (1 + count_node(root->left) + count_node(root->right));
// }
//
// int largest_subtree(BstNode* root)
// {
//     if (root == NULL) return 0;
//     if (root->right == NULL && root->left == NULL) return 1;
//     if (is_node_valid(root, -1, -1))
//     {
//       return count_node(root);
//     }
//     int max_left = largest_subtree(root->left);
//     int max_right = largest_subtree(root->right);
//
//     return (max_left >= max_right)? max_left : max_right;
// }

int max_path_sum(BstNode* root, int sum)
{
  if (root == NULL) return 0;
  int l = MAX(0, max_path_sum(root->left, sum + root->data));
  int r = MAX(0,max_path_sum(root->right, sum + root->data));
  sum = MAX(sum, l + r + root->data);
  return MAX(l,r) + root->data;
}

int sum_of_all_nodes(BstNode* root)
{
  if (root == NULL) return 0;

  if (root->left == NULL && root->right == NULL)
  {
    return root->data;
  }
  return (root->data + sum_of_all_nodes(root->left) + sum_of_all_nodes(root->right));
}

int count_node (BstNode* root)
{
  if (root == NULL) return 0;

  if (root->left == NULL && root->right == NULL)
  {
    return 1;
  }
  return (1 + count_node(root->left) + count_node(root->right));
}

//find root of the node
BstNode* in_order_successor_v1(BstNode* root, BstNode* input_node)
{
  BstNode* candidate = NULL;
  while (root != NULL)
  {
    if (input_node->data < root->data)
    {
      candidate = root;
      root = root->left;
    }
    else
    {
      root = root->right;
    }
  }
  return candidate;
}

int max_depth(BstNode* root)
{
  if (root == NULL)
  {
    return 0;
  }
  else
  {
    int l = max_depth(root->left);
    int r = max_depth(root->left);
    return MAX(l,r) + 1;
  }
}

//interval trees
bool check_overlap(int root_lower, int root_upper, int lower, int upper)
{
    if (root_lower <= lower && upper <= root_upper)
    {
        return true;
    }
    return false;
}

bool search (node *root, int lower, int upper)
{
    if (root == NULL || check_overlap(root->lower, root->upper, lower, upper))
    {
        if (root == NULL)
            return false;
        else
            return true;
    }

    else if (lower <= root->lower)
    {
        if (upper > root->max)
        {
            return false;
        }
        return search(root->left, lower, upper);
    }
    else
    {
        if (upper > root->max)
        {
            return false;
        }
        return search(root->right, lower, upper);
    }
}

int closest_binary_tree_value(BstNode* root, int target)
{
  int closest_value = root->data;
  while(root != NULL)
  {
    if (abs(root->data - target) < abs(closest_value - target))
    {
      closest_value = root->data;
    }

    if (closest_value == target)
    {
      return closest_value;
    }
    root = target < root->data? root->left : root->right;
  }
  return closest_value;
}

//Group anagrams using BST 
