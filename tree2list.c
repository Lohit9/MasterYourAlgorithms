#include "tree2list.h"
#include <stdlib.h>


struct node *bintree2listUtil(struct node *root)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Converting the left subtree and link to root
    if (root->left != NULL)
    {
        // Converting the left subtree
        struct node *left = bintree2listUtil(root->left);
 
        // Find predecessor and after this loop, left
        // will point to the predecessor(inorder)
        for (; left->right!=NULL; left=left->right);
 
        // Make root as next of the predecessor
        left->right = root;
 
        // Make predecssor as previous of root
        root->left = left;
    }
 
    // Convert the right subtree and link to root
    if (root->right!=NULL)
    {
        // Convert the right subtree
        struct node *right = bintree2listUtil(root->right);
 
        // Find inorder successor. After this loop, right
        // will point to the inorder successor
        for (; right->left!=NULL; right = right->left);
 
        // Make root as previous of successor
        right->left = root;
 
        // Make successor as next of root
        root->right = right;
    }
 
    return root;
}
 
 

struct node *tree2list(struct node *root)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Convert to Doubly Linked List using bintree2listUtil()
    root = bintree2listUtil(root);
 
    // bintree2listUtil() returns root node of the converted
    // Doubly Linked List.  We need pointer to the leftmost node which is
    // head of the constructed Doubly Linked List, so move to the leftmost node
    while (root->left != NULL)
        root = root->left;
 
    return (root);
}