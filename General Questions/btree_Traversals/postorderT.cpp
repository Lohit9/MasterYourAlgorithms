/* Program to implement the preorder traversal of a binary tree */

/* 1: Recursive approach */

void preorderRecursive (struct Node *btree){
  if(!btree) return;
  preorderRecursive(btree->left);
  cout << btree->data << endl;
  preorderRecursive(btree->right);
}

/* 2: Iterative approach */

void postorderIterative (struct Node *root){
  struct Node *temp =  root;
  struct Stack *s = createStack();

  while(1){
    while(temp){
      push(&s,temp);
      temp = temp->left;
    }
    temp = pop(&s);
    temp= temp->right;
    cout << temp->data << endl;
  }

}
