/* Program to check if given binary tree is balanced - i.e the difference between left and right is atmost 1*/

int isBalanced(struct node* root){
    if(!root) return;
    
    int ldepth, rdepth;
    
    ldepth = isBalanced(root->left);
    rdepth = isBalanced(root->right);
    
    if (ldepth == -1) return -1;
    if (rdepth == -1) return -1;

    if(abs(ldepth=rdepth) >0){
        return -1;
    }
    
    return 1;
}

/*
 Runtime complexity: O(n)
 
 
 Space Time Complexity: O(h) where h is the height of the input tree - due to the use of a tree.
 
 */