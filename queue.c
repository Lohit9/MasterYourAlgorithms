#include "strqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>




struct strqueue
 {
    struct llnode *first;
    struct llnode *last;
    int len;
  };

struct llnode
{
  char *item;
  struct llnode *next;
};



StrQueue create_StrQueue(void)
{
    struct strqueue *new = malloc(sizeof(struct strqueue));
    new->first = NULL;
    new->last = NULL;
    new->len = 0;
    return new;
}

void freeList(struct llnode *head)
{
   struct llnode *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp->item);
       free(tmp);
    }

}




void destroy_StrQueue(StrQueue sq)
{
    freeList(sq->first);
    //freeList(sq->last);
    free(sq);
    
    
}


void sq_add_back(StrQueue sq, const char *str)
{

  struct llnode *temp = malloc(sizeof(struct llnode));
    char *string = malloc((strlen(str)+1)*sizeof(char));
    strcpy(string, str);  
    temp->item = string ;
  if (sq->first == NULL)
  {
    sq->first=temp ;
    sq->first->next = NULL;
    sq->last = sq->first;
  }
  else
  {
    sq->last->next = temp;
    sq->last=temp;
    sq->last->next = NULL;
      //free(string);

  }
    
    sq->len++;

  

}

char *sq_remove_front(StrQueue p)
{
    
    struct llnode *temp = p -> first ;
    char *item2=NULL;
    if ( temp == NULL )
    {
        return NULL ;
    }
    else
    {
        temp = p -> first ;
        item2 = temp -> item ;
         
        p -> first = temp -> next ;
        p->len = p->len-1;
        free(temp);
        if ( temp == NULL )
        p -> last = NULL ;
        
        
        return (item2 ) ;
    }
    
}
   




int sq_length(StrQueue sq)
{
    return sq->len;
}



/*int main(void) {
  StrQueue mms = create_StrQueue();
  assert(sq_length(mms) == 0);
  sq_add_back(mms, "cdddd");
  sq_add_back(mms,"cd"); 
  sq_add_back(mms,"cjojo"); 
  assert(sq_length(mms) == 3); 
  destroy_StrQueue(mms);
  
} */





