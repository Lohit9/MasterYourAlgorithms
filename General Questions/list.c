
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// see list.h for documentation
struct llist *create_list(void) {
  struct llist *lst = malloc(sizeof(struct llist));
  lst->front = NULL;
  lst->back = NULL;
  lst->length = 0;
  return lst;
}

// see list.h for documentation
void destroy_list(struct llist *lst) {
  assert(lst);
  struct llnode *current = lst->front;
  struct llnode *next;
  while (current != NULL) {
    next = current->next; // note the next pointer
    free(current); // delete the node
    current = next; // advance to the next node
  }
  free(lst);
}


// see list.h for documentation
int list_length(struct llist *lst) {
  return lst->length;
}


// see list.h for documentation
void print_list(struct llist *lst) {
  struct llnode *current;
  for (current = lst->front; current != NULL; current = current->next)
    printf("  %d", current->item);
  printf("\n");
}


// see list.h for documentation
void add_to_front(int n, struct llist *lst) {
    
  struct llnode *new = malloc(sizeof(struct llnode)); 
	new->item = n;
	new->next = NULL ;
	if (lst->length==0)
	{
		lst->front = new ;
		lst->back = new ;
	}
	else
	{
		new->next = lst->front ;
		lst->front = new;
		
	}

	lst->length++;
    
    
 }

// see list.h for documentation
void add_to_back(int n, struct llist *lst) {
    
    struct llnode *new = malloc(sizeof(struct llnode));
	new->item = n;
	new->next = NULL ;

	if (lst->length == 0)
	{
		lst->front = new;
		lst->back = new;
	}

	else
	{
		lst->back->next = new;
		lst->back = new;
    }

    lst->length++;
  
}

// see list.h for documentation
int delete_from_front(struct llist *lst) 
{
	assert(lst->length > 0);
    if (lst->length ==1)
    {
       return lst->front->item ;
       
    }
    
	struct llnode *temp = lst->front;
    
    lst->front = temp->next ;
    int hold = temp->item;
    free(temp);
    return hold;
    


}
// see list.h for documentation
int get_nth(struct llist *lst, int index)
{
    int length = lst->length;
    assert(index>0 && index<=length-1);
    struct llnode *new = lst->front ; 
    int count = 0;
    while(lst != NULL)
    {
       if(index == count)
       {
           return new->item;
       }
        new = new->next ;
        count++;
    }
    assert(0);
}
    
// see list.h for documentation
 void insert_nth(struct llist *lst, int index, int data)
 {
     struct llnode *cur = lst->front;
	struct llnode *prev = NULL ;
	int count = 0;
	while((cur != NULL) && index>count)
	{
		prev = cur ;
		cur = cur->next ;

	}

	struct llnode *new = malloc(sizeof(struct llnode));
	new->item = data ;
	new->next = cur ;
	if(prev == NULL)
	{
		lst->front = new;
	}
   
	else
	{
		prev->next = new ;
        if (cur == NULL)
	{
		lst->back = new ;
	}
	}
     
 }
// see list.h for documentation
void lst_append(struct llist *lst1, struct llist *lst2)
{
    assert (lst1);
    assert(lst2);
    lst1->back->next = lst2->front;
    lst1->back = lst2->back;
    lst1->length = lst1->length + lst2->length;
    lst2->front = NULL ;
    lst2->back = NULL ; 
    lst2->length = 0;
    
}


// see list.h for documentation
bool eq_list(struct llist *lst1, struct llist *lst2)
{
    
    struct llnode *a = lst1->front;
    struct llnode *b = lst2->front;
    while(1)
  {
    /* base case */
    if(a == NULL && b == NULL)     
    {  return 1; }
    if(a == NULL && b != NULL)  
    {  return 0; }
    if(a != NULL && b == NULL)  
    {  return 0; }
    if(a->item != b->item)
    {  return 0; }
    
    /* If we reach here, then a and b are not NULL and their 
       data is same, so move to next nodes in both lists */
    a = a->next;
    b = b->next; 
  }          
} 
// see list.h for documentation
int maxminlist(struct llist *lst, int *max, int *min)
{
    assert(lst);
	struct llnode *new = lst->front ; 
	
	*max = *min = new->item;

	while (new != NULL)
	{
		if (new->item < *min)
		{
			*min = new->item ;
		}
		if (new->item > *max)
		{
			*max = new->item ;
		}
        new = new->next ;


	}

	return 1;

}
// see list.h for documentation
void list_map( struct llist *lst, int (*function_ptr)(int) )
{
    assert(lst);
    struct llnode *new = lst->front;
    do
    {
        new->item = function_ptr(new->item) ; 
        new = new->next ;
    }
    while (new != NULL);
}



     
    



    
    


    
    






