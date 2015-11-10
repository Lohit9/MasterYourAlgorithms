// list.h
#include <stdbool.h>

struct llnode {
	int item;
	struct llnode *next;
};

struct llist {
	struct llnode *front;
	struct llnode *back;
	int length;
};

// create_list() creates an empty list;
//   effects: allocates and returns empty list
//   time: O(1)
struct llist *create_list(void);


// destroy_list(lst) destroys lst
//   requires: lst is a valid list
//   effects: lst is destroyed and all memory allocated for lst is freed.
//   time: O(n) where n is the length of lst
void destroy_list(struct llist *lst);


// list_length(lst) determines the number of nodes in lst
//   requires: lst is a valid list
//   time: O(1)
int list_length(struct llist *lst);


// print_list(lst) prints the items in the list lst from front to back
//   requires: lst is valid
//   effects: all elements in lst printed using "  %d", followed by "\n" at the end
//   time: O(n) where n the length of lst
void print_list(struct llist *lst);


// add_to_front(n, lst) adds n to the beginning of lst
//   requires: lst is a valid list
//   effects: list is modified to have a new node with n at the start
//   time: O(1)
void add_to_front(int n, struct llist *lst);


// add_to_back(n, lst) adds n to the end of lst
//   requires: lst is a valid list
//   effects: list is modified to have a new node with n at the end
//   time: O(1)
void add_to_back(int n, struct llist *lst);


// delete_from_front(lst) removes the first node from list
//    and returns the item that was in that node
//   requires: lst length is > 0 
//   effects: list is modified, with first node removed
//   time: O(1)
int delete_from_front(struct llist *lst);


// get_nth(lst, index) returns the item at the nth node in lst
//     (for example, get_nth(lst, 0) returns the first item
//   requires: index is a valid index (0 ... length-1) [assert this!]
//   time: O(n) where n = index
int get_nth(struct llist *lst, int index);


// insert_nth(lst, index, data) inserts a new node with item data
//     to lst at location index
//   requires: index is a valid new index (0 ... length) [assert this!]
//   effects: list is modified, with new node added
//   time: O(n) where n = index
void insert_nth(struct llist *lst, int index, int data);


// lst_append(lst1, lst2) appends contents of lst2 to the end of lst1 and
//     then empties lst2
//   requires: both lst1 and lst2 are different and valid lists
//   effects: lst1 modified to add nodes from lst2
//         lst2 is empty
//   time: O(1)
void lst_append(struct llist *lst1, struct llist *lst2);


// eq_list(lst1, lst2) determines if lst1 and lst2 are identical
//   requires: both lst1 and lst2 are valid lists
//   time: O(n) where n is the length of lst1
//         O(1) if length of lst1 != length of lst2
bool eq_list(struct llist *lst1, struct llist *lst2);


// maxminlist(lst, &min, &max) finds the maximum and minimum items in a list
// 			returns 1 if list is not empty
//          OR returns 0 if list is empty
//   requires: lst is valid
//   effects: modifies *min/*max to store minimum/maximum item in list
//            unless list is empty then it doesn't modify *min/*max
//   time: O(n) where n is the length of lst
int maxminlist(struct llist *lst, int *max, int *min);
