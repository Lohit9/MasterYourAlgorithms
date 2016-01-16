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
    struct Stack* s1 = createStack();
    struct Stack* s2 = createStack();
    struct Node* temp;
    
    push(&s1,root);
    
    while(s1){
        temp = pop(s1);
        push(&s2,temp);
        if(root->left) push(&s1,root->left);
        if(root->right) push(&s2,root->right);
    }
    
    while(s2){
        temp= pop(s2);
        cout << temp->data << endl;
    }
}

/*
 
 Time Complexity: O(n) ->even for the recursive solution 
 Space Complexity: O(n) due to the use of stack

*/