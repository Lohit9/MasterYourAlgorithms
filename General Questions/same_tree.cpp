//
//  same_tree.cpp
//  
//
//  Created by Lohit  on 2016-01-17.
//
//

#include <stdio.h>


/* Program to check if 2 binary trees are the same -  need to have teh same data values and structure */

bool isSame(struct Node* tree1, struct Node* tree2){
    if(tree1 == NULL && tree2 == NULL){
        return true;
    }
    
    if(tree1 == NULL || tree2 == NULL){
        return false;
    }
    
    return tree1.data == tree2.data && isSame(tree1->left, tree2->left) && isSame(tree2->left,tree2->right);
    
}