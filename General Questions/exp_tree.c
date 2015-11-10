// texp.h

#include <stdlib.h>
#include <stdbool.h>
((3-(4*2))/2)

struct enode {
  char op;  // one of '+', '-', '/', '*' [invalid if leaf node]
  int arg;  // one of 0..9 [invalid if non-leaf node]
  struct enode *left;  // NULL if leaf node
  struct enode *right; // NULL if leaf node
};


// newnode() returns a new enode
//   effects: allocate a new enode,
//         where left and right are NULL, and op & arg are not initialized
//   time: O(1)
struct enode *newnode(void)
{
  struct enode *t=malloc(sizeof(struct enode));
  t->left=NULL;
  t->right=NULL;
  return t;
}


// destroy_tree(t) destroys t and all subtrees
//   requires: t is not NULL
//   effects: frees all the memory allocated for t and all subtrees.
//   time: O(n) where n in the number of nodes in tree t.
void destroy_tree(struct enode *t)
{
  if (NULL == t) {return;}
  destroy_tree(t->left);
  destroy_tree(t->right);
  free(t);
}


// eval(t) evaluates the arithmetic expression stored in t
//   requires: t is a valid arithmetic expression
//   time: O(n) where n in the number of nodes in t.
int eval(struct enode *t)
{

	if (t->left == NULL) return t->arg;
	else
	{
		if (t->op=='+')return eval(left) + eval(right);
        if (t->op=='-')return eval(left) - eval(right);
        if (t->op=='*')return eval(left) * eval(right);
        if (t->op=='/')return eval(left) / eval(right);
    }

    return 0;
}



}


// build_tree(c) produces an expression tree for the expression in c
//   requires: c is a valid fully parenthesized expression, null terminated
//   effects:  a new tree representing the expression c is allocated
//   time: O(n) where n is the length of c
struct enode *build_tree(char c[])
{

	int len = strlen(t);
	assert(len>0);
	struct enode *new = newnode();
	struct enode *current = new;
	for(int i=0; i<len ;i++)
	{
		if (a[i]=='(')
		{
			if (current!=NULL)
			{ 
			current->left = newnode();
			current = new->left;
		    }
		    

		 }
		 if (a[i] == '+')
		 {
		 	if (current == NULL) current->op = a[i];
		 	else
		 	{
		 		current->op = a[i];
		 		current->right = newnode();
		 		current = current->right;
		 	}
		 }
		 if (a[i] == '-')
		 {
		 	if (current == NULL) current->op = a[i];
		 	else
		 	{
		 		current->op = a[i];
		 		current->right = newnode();
		 		current = current->right;
		 	}
		 }
		 if (a[i] == '*')
		 {
		 	if (current == NULL) current->op = a[i];
		 	else
		 	{
		 		current->op = a[i];
		 		current->right = newnode();
		 		current = current->right;
		 	}
		 }
		 if (a[i] == '/')
		 {
		 	if (current == NULL) current->op = a[i];
		 	else
		 	{
		 		current->op = a[i];
		 		current->right = newnode();
		 		current = current->right;
		 	}
		 }

		 if (0<=a[i]<=9)
		 {
		 	current->arg = a[i];

		 }



		}
	}


}



