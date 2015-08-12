/**
 File: count.c
Enter a description for this file.
*/
#include <assert.h>
#include "count.h"
#include <stdlib.h>
#include <stdio.h>

struct bstnode {
  struct bstnode *left;
  struct bstnode *right;
    int counter;
    int key;
    int max; 
    
 
};

struct count
{
    struct bstnode *check;
    int call;
    int unq;
    int freq;
    int occ ;
    
};



Count create_Count(void)
{
  struct count *new = malloc(sizeof(struct count));
    new->check = NULL;
    new->call=0;
    new->unq = 0;
    new->occ = 0;
    new->check = malloc(sizeof(struct bstnode));
    new->check->left = NULL;
    new->check->right = NULL;
    new->check->counter = 0;
    new->freq = 0;
    new->check->key = 0;
    return new;
}
void destroy_tree(struct bstnode *node) {
	if (NULL == node) {return;}
	destroy_tree(node->left);
	destroy_tree(node->right);
    
	free(node);
}
void destroy_Count(Count c)
{
   destroy_tree(c->check);
    free(c);
}

int search(int key, struct bstnode *leaf)
{
   if( leaf != NULL )
  {
      
      if(key==leaf->key)
      {
         return 1;
      }
      else if(key<leaf->key)
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

void insert(struct bstnode **tree, int val) {
 

 if(!(*tree)) {
   struct bstnode *temp = malloc(sizeof(struct bstnode));
   temp->left = temp->right = NULL;
   temp->key = val;
   temp->counter = 0;
     
   *tree = temp;
        
 }

 if(val < (*tree)->key) {
      insert(&(*tree)->left, val);
   } 
    else if(val > (*tree)->key) {
     insert(&(*tree)->right, val);
   }
    
    else
    {   
       (*tree)->counter++;
       
    }
   
}

void next(Count c, int i)
{
    
    if(search(i,c->check)==0)
    {
         c->unq++;
    }
    insert(&c->check , i);
     
     c->call++;
    
    if (count(c,i) > c->occ)
    {
        c->occ  = count(c,i);
        c->freq = i;
    }
     
    
    
}
int total(Count c)
{
    return c->call ;
}

int unique(Count c)
{
    return c->unq ;
}

//int n ;
 int traverse2(struct bstnode **tree , int val,int *n)
{
  
  if(search(val,*tree)== 1)
  { 
  if(val == (*tree)->key)
  {
     n = &(*tree)->counter;
      
  }
 else if(val < (*tree)->key) {
      return traverse2(&(*tree)->left, val , n);
   } 
    else if(val > (*tree)->key) {
     return traverse2(&(*tree)->right, val , n);
   }

    
  }
     else if (search(val,*tree)== 0)
     {
        n = 0;
     }
     
     //printf("%d",*n);
     return *n;
     
     
}

  
    
int count(Count c, int i)
    
{
     if(search(i,c->check)==0) return 0;
    int n = 0;
    return traverse2((&c->check) , i, &n ) ;
    
      
 }




 
int mostfreq(Count c)
{
    
    return c->freq;
}


void intrav (struct bstnode *tree)
{
    
    if (tree !=NULL)
    {
       intrav(tree->left);
        if(tree->key >0)
       printf ("%d: %d\n", tree->key, tree->counter);
          
        intrav(tree->right);
    }
    
    
}

void stats(Count c)
{
    if (c->check != NULL)
    {
    intrav(c->check);
    }
}


