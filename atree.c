#include "atree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
 [Your Name] (########)
 CS136 Spring 2015
 Assignment 8, Problem 5
 File: atree.c
**/
const int EMPTY = INT_MIN;
int exponent(int exp)
{
   int value=1;
  
  while (exp!=0)
  {
      value*=2;  
      --exp;
  }
  return value;
}

struct atree *create_atree(int maxheight) {
    assert(maxheight>0);
    int size= exponent(maxheight);
    int bytes1= sizeof (struct atree);
    int bytes2= sizeof(int *) * size;
   
    struct atree *new = malloc(bytes1);
    int *a = malloc(bytes2);
    new->maxheight= maxheight;
    new->data = a;
    for(int i=0;i<size; i++)
    {
        new->data[i] = EMPTY;
    }
    return new;

}

void destroy_atree(struct atree *atr) {
    assert(atr);
    free(atr->data);
    free(atr);

}
 int temp_l =0;
    int temp_r =0;  
void atree_add(struct atree *atr, int i) {
    assert(atr);
    
    if (atr->data[0] == EMPTY)
    {
       
        atr->data[0] = i;
    }
 
    else if (atr->data[temp_l] > i )
    {
        temp_l = 2*temp_l+1;
        atr->data[temp_l] = i;
    }
    
    else if (atr->data[temp_r] <i)
    {
       temp_r = 2*temp_r+2;
       atr->data[temp_r] = i;
       
    }
}

bool atree_search(struct atree *atr, int i) {
    int x = exponent(atr->maxheight);
    int flag=0;
   for (int j=0 ; j<x ;j++)
   {
       if (atr->data[j] == i) flag=1;
   }
    
    return flag;

}

/*int main()
{
    struct atree *tree = create_atree(4);
    atree_add(tree, 5); 
    atree_add(tree,10);
    atree_add(tree,3);
    atree_add(tree, -6); 
    atree_add(tree,8);
    printf("temp_r %d\n", temp_r);
    printf("temp_l %d\n", temp_l);
    atree_add(tree,12);
    atree_add(tree,42);
    printf("%d\n", tree->data[0]);
    printf("%d\n", tree->data[1]);
    printf("%d\n", tree->data[2]);
    printf("%d\n", tree->data[3]);
    printf("%d\n", tree->data[5]);
    printf("%d\n", tree->data[6]);
    printf("%d\n", tree->data[14]);
    
    printf("%d\n", atree_search(tree, 5)) ;
    printf("%d\n", atree_search(tree, 7) ) ;
    printf("%d\n", atree_search(tree, 42) ) ;
    destroy_atree(tree);
}
*/