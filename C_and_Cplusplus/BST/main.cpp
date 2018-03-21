#include "bst.h"

vector<int> output;
vector<std::vector<int> > results;

void pre_order_traversal(BstNode* root)
{
  if (root == NULL) return;

  output.push_back(root->data);
  pre_order_traversal(root->left);
  pre_order_traversal(root->right);
}

void post_order_traversal(BstNode* root)
{
  if (!root) return;
  post_order_traversal(root->left);
  post_order_traversal(root->right);
  output.push_back(root->data);
}

void in_order_traversal(BstNode* root)
{
  if (!root) return;
  in_order_traversal(root->left);
  output.push_back(root->data);
  in_order_traversal(root->right);
}

void level_order_traversal(BstNode* root)
{
  queue<BstNode*> q;
  if (root == NULL) return;
  q.push(root);
  q.push(NULL);
  BstNode *temp;
  vector<int> sub_list;
  while (!q.empty())
  {
    temp = q.front();
    q.pop();
    if (temp == NULL)
    {
      results.push_back(sub_list);
      sub_list.resize(0);
      if (q.size() > 0)
      {
        q.push(NULL);
      }
    }
    else
    {
      sub_list.push_back(temp->data);
      if (temp->left != NULL)
      {
        q.push(temp->left);
      }
      if (temp->right != NULL)
      {
        q.push(temp->right);
      }
    }
  }
}

int main(int argc, char const *argv[]) {

  BstNode* root;
  root = NULL;

  root = InsertNode(root, 12);
  root = InsertNode(root, 13);
  root = InsertNode(root, 5);
  root = InsertNode(root, 4);
  root = InsertNode(root, 3);
  root = InsertNode(root, 7);

  // struct BstNode *root = CreateNode(1);
  //
  // root->left = CreateNode(2);
  // root->right = CreateNode(3);
  // root->left->left = CreateNode(4);
  // root->left->right = CreateNode(5);

  // level_order_traversal(root);
  // for (int i = 0; i < results.size(); i++)
  // {
  //   for (int j = 0; j < results[i].size(); j++)
  //   {
  //     printf("%d\n", results[i][j]);
  //   }
  // }

  // in_order_traversal(root);
  // for (int i = 0; i < output.size(); i++)
  // {
  //   printf("%d\n", output[i]);
  // }

  // BstNode* test_node = CreateNode(15);
  // BstNode *output = in_order_successor_v1(root,test_node);
  // bool closest_value = false;
  //
  // if(output)
  // {
  //   printf("In order successor: %d\n", output->data);
  // }
  // else
  // {
  //   printf("There is no in order successor\n");
  // }

  // printf("Closest value: %d\n", closest_binary_tree_value(root, 9));

  // printf("%d\n", max_path_sum(root,0));
  // printf("Find path sum %d\n", find_path_sum(root,28));
  // printf("node count: %d\n", count_node(root));
  // printf("tree sum %d\n", sum_of_all_nodes(root));

  // printf("output version 1: %d\n", Search_v1(root, 9));
  // printf("output version 2: %d\n", Search_v2(root, 9));

  // printf("Maximum Value: %d\n", findMax(root));
  // printf("Minimum Value: %d\n", findMin(root));

  // print_in_order(root);

  printf("max depth: %d\n", max_depth(root));

  return 0;
}
