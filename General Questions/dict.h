// dictionary.h: an ADT for storing a Dictionary of void *'s

struct dictionary;
typedef struct dictionary *Dictionary;

typedef int (*CompareFunction)(const void *, const void *);
typedef void (*FreeFunction)(void *);

// create_Dictionary(comp_k, free_k, free_v) creates a new Dictionary
//     that uses the comp_k function to compare keys
//     the free_k function to free keys and
//     the free_v function to free values
//   requires:  comp_k, free_k and free_v are valid (non-NULL) function pointers
//   effects: allocates a struct dictionary on the heap,
//            caller must call destroy_Dictionary
//   time: O(1)
//   NOTE: comp_k(a,b) follows the strcmp(a,b) return convention
Dictionary create_Dictionary(CompareFunction comp_k, FreeFunction free_k, FreeFunction free_v);


// destroy_Dictionary(dict): Frees all memory allocated for dict, 
//     and frees the memory for every key and every value
//   requires:  dict is a valid Dictionary (not NULL)
//   effects: dict is no longer valid
//   time: O(n * f), where n is the number of items in Dictionary, 
//         f is time to free key & value
void destroy_Dictionary(Dictionary dict);


// insert(dict, k, v): insert the key/value pair k/v into the dictionary.
//     the client should not modify or free k or v after insert.
//     if the key k already exists, the previous value will be freed
//     and the value for k will be replaced with v.
//   requires:  dict, k, and v are valid (not NULL)
//   effects: it will add the (k,v) pair into the dictionary
//            if k already existed, the previous value will be freed
//   time: O(h * c + f), where h is height of underlying BST, 
//         c is time to compare two keys,
//         and f is the time to free the previous value (if necessary)
void insert(Dictionary dict, void *k, void *v);


// lookup(dict, k): returns the value associated with key k, if such
//     a value exists.  Otherwise, returns NULL.
//   requires:  dict and k are valid (not NULL)
//   time: O(h * c), where h is height of underlying BST, 
//         c is time to compare two keys
void *lookup(Dictionary dict, void *k);

