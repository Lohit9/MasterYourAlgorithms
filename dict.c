/**
 File: dictionary.c
Enter a description for this file.
*/
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct bstnode {
  void *key;
  void *value;
  struct bstnode *left;
  struct bstnode *right;
};



struct dictionary {
  struct bstnode *root;
  CompareFunction key_compare;
  FreeFunction key_free_k;
  FreeFunction key_free_v;  
};


Dictionary create_Dictionary(CompareFunction comp_k, FreeFunction free_k, FreeFunction free_v)
{
  struct dictionary *new  = malloc(sizeof(struct dictionary));
  new->key_compare = comp_k;
  new->key_free_k = free_k;
  new->key_free_v = free_v;
  new->root = NULL;
  return new;

}
void deleteTree(struct bstnode *node,FreeFunction free_k, FreeFunction free_v) 
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left,free_k,free_v);
    deleteTree(node->right,free_k,free_v);
   
    /* then delete the node */
    free_k(node->key);
    free_v(node->value);
    
    free(node);
}

void destroy_Dictionary(Dictionary dict)
{
    deleteTree(dict->root,dict->key_free_k,dict->key_free_v);
    free(dict);
}

 void *lookup(Dictionary d, void *k) {
    struct bstnode *t = d->root;
    while (t) {
      int result = d->key_compare(k, t->key);
      if (result < 0) {
        t = t->left;
      } else if (result > 0) {
        t = t->right;
      } else { // key found!
        return t->value;
      }
}
    return NULL; // (no key found)
  }


 struct bstnode *createNode(void *word, void *meaning) {
        struct bstnode *newnode;
        newnode = malloc(sizeof(struct bstnode));
        newnode->key = word;
        newnode->value =  meaning;
        newnode->left = newnode->right = NULL;
        return newnode;
  }


void insert(Dictionary dict, void *k, void *v)
{
    struct bstnode *current = NULL, *newnode=NULL;
    int res=0;
    if (dict->root == NULL)
    {
        dict->root = createNode(k,v);
        return;
    }
    for (current = dict->root ; current != NULL ; current = (res>0)? current->right : current->left)
    {
        res = dict->key_compare(k,current->key);
        if (res == 0)
        {
            return;            //duplicate entry

        }
        dict->root = current;
    }
    newnode = createNode(k,v);
    res>0 ? (dict->root->right = newnode) : (dict->root->left=newnode);
    return;

}   



    


