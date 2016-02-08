//function to find the height or max depth of a binary tree, this is an funcition only submission
#include <algorithm>
#include <iostream>
using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

int maxDepth(node *root){
 if(!root) return 0;

 int ldepth = maxDepth(root->left);
 int rdepth = maxDepth(root->right);
 return max(ldepth,rdepth) + 1;

}


int main(){
  return 0;
}
