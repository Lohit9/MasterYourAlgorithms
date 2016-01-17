/* Program to find the maximum element in a binary tree */

int maxElem(struct Node* root){
    int  maxleft, maxright;
    
    if(!root){
        data = root->data;
        maxleft = maxElem(root->left);
        maxright = maxElem(root->right);
        maximum = max(maxleft,maxright)
        return max(maximum, data);
    }
    
    else return 0;
}

/* Maximum element without using recursion */

int maxElem (struct Node* root){
    int maxElement = 0;
    struct Queue* q = createQueue();
    push(&q,root);
    struct Node* temp;
    
    while(!q){
        temp = pop(&q);
        max = max(temp, maxElement);
        if (temp->left) push(&q, temp->left);
        if (temp->right) push(&q, temp->right);
    }
    
    return max;
}

/* Time complexity: O(n)
 
   Space complexity: O(n) due to the use of a queue
 
   For the non recursive version we employ a queue to perform an level order traversal also known as BFT
 
 */