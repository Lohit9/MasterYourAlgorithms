/* Program to implement the preorder traversal of a binary tree */

/* 1: Recursive approach */

void preorderRecursive (struct Node *btree){
  if(!btree) return;
  preorderRecursive(btree->left);
  cout << btree->data << endl;
  preorderRecursive(btree->right);
}

/* 2: Iterative approach */

void preorderIterative (struct Node *root){
  struct Node *temp = root;
  struct Stack* s = NULL;

  while(1){
    while(temp){
      cout<< temp->data << endl;
      push(&s,temp);
      temp = temp->left;
    }
    if(!s) break;
    temp = pop(&s);
    temp = temp->right;
  }
}
