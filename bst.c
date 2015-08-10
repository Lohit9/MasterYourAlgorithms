// bst.c

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "bst.h"

// see bst.h documentation
struct btree *create_bst(void) {
	struct btree *tree = malloc(sizeof(struct btree));
	tree->root = NULL;
	return tree;
}


// destroy_tree(node) destroys node
// effects: node is deallocated along with all nodes linked to it.
// time: O(n) where n is the number of nodes linked to struct bstnode node.

void destroy_tree(struct bstnode *node) {
	if (NULL == node) {return;}
	destroy_tree(node->left);
	destroy_tree(node->right);
	free(node);
}


// see bst.h documentation
void destroy_bst(struct btree *t){
   assert(t);
   destroy_tree(t->root);
   free(t);
}


// see bst.h documentation
struct bstnode *make_bstnode(int val, struct bstnode *l, struct bstnode *r) {
	struct bstnode *new = malloc(sizeof(struct bstnode));
	new->item = val;
	new->left = l;
	new->right = r;
	return new;
}



// see bst.h documentation
bool is_bempty(struct btree *t){
	assert(t);
	return (NULL == t->root);
}


// inorder_node(node) prints all nodes of node in order
//  (left, root, right)
// effects: node's item is printed to the screen, 
//          along with all nodes' items linked to it
// time: O(n) where n is the number of printed nodes
void inorder_node(struct bstnode *node) {
	if (NULL == node) {return;}
	inorder_node(node->left);
	printf("  %d", node->item);
	inorder_node(node->right);
}

// see bst.h documentation
void traverse_inorder(struct btree *t){
	assert(t);
	inorder_node(t->root);
	printf("\n");
}


void insert(struct bstnode **tree, int val) {
 
 //struct bstnode *temp = NULL;
 if(!(*tree)) {
   struct bstnode *temp = malloc(sizeof(struct bstnode));
   temp->left = temp->right = NULL;
   temp->item = val;
   *tree = temp;
   return;
 }

 if(val < (*tree)->item) {
      insert(&(*tree)->left, val);
   } else if(val > (*tree)->item) {
     insert(&(*tree)->right, val);
   }
 }

 void bst_insert(int val, struct btree *t) {
   
  insert(&t->root,val);
     
  
}


int search(int key, struct bstnode *leaf)
{
   
  if( leaf != NULL )
  {
      
      if(key==leaf->item)
      {
          return 1;
      }
      else if(key<leaf->item)
      {
          return search(key, leaf->left);
      }
      else
      {
          return search(key, leaf->right);
      }
  }
  
  else return 0;
}

//see bst.h documentation
bool bst_search(struct btree *t, int val){

    //printf("%d",t->root->item);
    return search(val,t->root);
    
}


