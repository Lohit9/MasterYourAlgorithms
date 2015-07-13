#include <stdbool.h>
#include <limits.h>
// a module for storing a BST in an array

extern const int EMPTY;
// in your atree.c, define:
// const int EMPTY = INT_MIN;

struct atree {
   int *data;
   int maxheight;
};
// data must be an array of size 2^maxheight


// create_atree(maxheight) returns a new atree structure
//     that can support a BST with maximum height maxheight
//     initially, all nodes will be EMPTY
//   requires:  maxheight >= 1
//   effects :  return value points to a dynamically allocated structure,
//              caller must eventually call destroy_atree() to free
//   time: O(2^n), where n = maxheight
struct atree *create_atree(int maxheight);

// destroy_atree(atr) will free the nodes
//     and then free the structure at itself
//   requires:  atr was previously returned from create_atree
//   effects :  atr is freed (and no longer valid)
//   time: O(1)
void destroy_atree(struct atree *atr);

// atree_add(atr, i) adds the integer i to atr
//     increasing the maxheight of the tree by 1 if necessary
//     if i already exists in atr, this function does nothing
//   requires:  atr is valid
//         i != EMPTY
//   effects: may increase the size of the tree in atr
//            i will be in the tree
//   time: [amortized] O(h), where h = at->maxheight
void atree_add(struct atree *atr, int i);

// atree_search(atr, i) will return true if i is in atr
//     and false otherwise
//   requires: atr is valid
//             i != EMPTY
//   time: O(h), where h = at->maxheight
bool atree_search(struct atree *atr, int i);
