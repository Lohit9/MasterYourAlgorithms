// strqueue.h: an ADT for storing a Queue of Strings

struct strqueue;
typedef struct strqueue *StrQueue;

// create_StrQueue(): creates a new StrQueue
//   effects: allocates a struct strqueue on the heap,
//            caller must call destroy_StrQueue
//   time: O(1)
StrQueue create_StrQueue(void);


// destroy_StrQueue(sq): frees the memory occupied by sq
//     and frees every string still in the queue
//   requires:  sq is a valid StrQueue (not NULL)
//   effects: frees the memory occupied by sq and frees every string in sq,
//            sq is no longer valid
//   time: O(n), where n is sq_length(sq)
void destroy_StrQueue(StrQueue sq);


// sq_add_back(sq, str): makes a copy of str and places it at the
//     end of the queue
//   requires:  sq is a valid StrQueue (not NULL)
//         str is not NULL.
//   effects: sq length increased by 1
//         a copy of str is now at the end of sq
//   time: O(n), where n is strlen(str)
void sq_add_back(StrQueue sq, const char *str);


// sq_remove_front(sq): returns the string that was first in the queue 
//     or NULL if empty
//   requires:  sq is a valid StrQueue (not NULL)
//   effects: if sq is empty, returns NULL 
//         otherwise, returns the first string (caller must free)
//         and sq length decreased by 1
//   time: O(1)
char *sq_remove_front(StrQueue sq);


// sq_length(sq) returns the number of items in the queue.
//   requires:  sq is a valid StrQueue (not NULL)
//   time: O(1)
int sq_length(StrQueue sq);

