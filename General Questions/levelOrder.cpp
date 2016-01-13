void levelOrder(struct btree* root){

  if(!root) return;
  Struct queue* Q = createQueue();
  push(Q,root->data);
  struct btree *currentRoot;
  while(Q != NULL){
    currentRoot = Q.first();
    cout << currentRoot->data << endl;
    if(currentRoot->left) push(Q,currentRoot->left);
    if(currentRoot->right) push(Q,currentRoot->right);
    pop(Q);
  }
  deleteQueue(Q);
}

/*
Time Complexity: O(n)

Space Complexity: O(n) -> worst case and O(1) -> best case
*/
