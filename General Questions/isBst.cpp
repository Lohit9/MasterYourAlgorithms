//
//  same_tree.cpp
//  
//
//  Created by Lohit  on 2016-01-17.
//
//

#include <stdio.h>


/* Program to check if 2 binary trees are the same -  need to have teh same data values and structure */

bool isBst (struct node* root, min, max){
    if(!root) return true;
    
    if(root->left >max || root->left < min){
        return false;
    }
    
    if(root->right < right->data || root->right > max){
        return false;
    }
    
    return isBst(root->left, min, root->data) && isBst(root->right, root->data, max);
}