
/**
 File: mmstack.c
Enter a description for this file.
*/

#include <assert.h>
#include "mmstack.h"
#include <stdlib.h>
#include <stdio.h>

struct llnode
{
  
  int item;
  struct llnode *next;
  int minc;
  int maxc;
};

struct mmstack
{
  int len ;
  struct llnode *topnode;
 
};



 MMStack create_MMStack(void)
{
    struct mmstack *new = malloc(sizeof(struct mmstack));
    new->topnode = NULL;
     new->len =0;
     return new ;
}

void destroy_MMStack(MMStack mms)
{
   while(mms->len !=0)
   {
       mms_pop(mms);
   }
    free(mms);
}
int mms_length(MMStack mms)
{
    assert(mms);
    return mms->len;
}

void mms_push(MMStack mms, int i) {

 struct llnode *new = malloc(sizeof(struct llnode));
  new->item = i;
  if(mms->len!=0)
{
  new->next = mms->topnode;
  mms->topnode = new;
}
else 
{
  new->next = NULL;
  mms->topnode = new;
}

  if (mms->len == 0)
  {
    mms->topnode->minc = i;
    mms->topnode->maxc = i;
    
    
  }
  else
{
  mms->topnode->maxc = mms->topnode->next->maxc;
  mms->topnode->minc = mms->topnode->next->minc;

  if(mms->topnode->maxc < i)
  {
      mms->topnode->maxc = i;
  }

  if(i<mms->topnode->minc)
  {
      mms->topnode->minc = i;
  }
}
mms->len++;

}


int mms_pop(MMStack mms) {
  assert(mms);
  int ret = mms->topnode->item;
  struct llnode *backup = mms->topnode;
  mms->topnode = mms->topnode->next;
  mms->len--;
    
    
  free(backup);
  return ret;
}

int mms_min(MMStack mms)
{
  assert(mms->len > 0);
  return mms->topnode->minc ;

}

int mms_max(MMStack mms)
{
  assert(mms->len > 0);
  return mms->topnode->maxc ;

}







