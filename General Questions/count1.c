/**
 File: count.c
Enter a description for this file.
*/
#include <assert.h>
#include "count.h"
#include <stdlib.h>
#include <stdio.h>

struct count
{
    int a[101];
    int call;
    int unq;
    int freq;
    
};

Count create_Count(void)
{
   struct count *new = malloc(sizeof(struct count));
   for(int i = 0; i<102 ; i++)
   {
     new->a[i]=0;
   }
    new->call =0;
    new->unq = 0;
    new->freq = 0;
    
  return new;
}
void destroy_Count (Count c)
{
  free(c);
}

void next(Count c, int i)
{
    if (i<101 && i>0)
    {
      c->a[i]++;
     
    }
    c->call++;
    
    if (c->a[i] == 1)
    {
        c->unq++;
    }
    if(c->a[i]>c->freq)
    {
        c->freq = i;
    }
    
}


int total(Count c)
{
    return c->call;
}

int count(Count c, int i)
{
    
   return c->a[i];
}

int unique(Count c)
{
    return c->unq;
}

int mostfreq(Count c)
{
    return c->freq;
}

void stats(Count c)
{
    for(int i=0; i<101 ;i++){ 
        if (c->a[i]>0)
        {
            printf("%d: %d\n", i, count(c,i));}}
}





