/**
 File: tree2list.h
Enter a description for this file.
*/

// The node type from which both the tree and list are built 
struct node {
    int val;
    struct node* left;
    struct node* right;
};



// tree2list(root) takes a binary search tree - root-  and 
// rearranges the internal pointers to make a circular doubly linked list
// out of the tree nodes. The list should be arranged so that the nodes
// are in increasing order. The function returns a pointer to the
// beginning of new list (pointer to the node which includes the minimum value).
// if root==NULL the furnction returns NULL 
// time: O(n), where n is the number of nodes in root.
struct node *tree2list(struct node *root);
