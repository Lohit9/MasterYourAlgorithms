/* Program to implement the inorder traversal of a binary tree */

/* 1: Recursive approach */

void inorderRecursive (struct Node *btree){
  if(!btree) return;
  inorderRecursive(btree->left);
  cout << btree->data << endl;
  inorderRecursive(btree->right);
}

/* 2: Iterative approach */

void inorderIterative (struct Node* root){
  if (!root) return;
  struct Stack* s = createStack();
  struct Node * tempRoot;
  while(1){
    while(tempRoot){
      push(s,tempRoot->data);
      tempRoot = tempRoot->left;
    }
    if (s==NULL) break;
    tempRoot = pop(S);
    cout << tempRoot->data << endl;
    tempRoot = tempRoot->right;
  }

}
