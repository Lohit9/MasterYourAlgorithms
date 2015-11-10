// a MMStack (Min/Max Stack)
// is a Stack ADT for storing integers
// that can return the Min/Max items in the stack
// all operations (except destroy) are O(1)

struct mmstack;

typedef struct mmstack *MMStack;

// create_MMStack() creates a new empty stack
//   effects: allocates a struct mmstack on the heap,
//            client must eventually call destroy_MMStack
//   time: O(1)
MMStack create_MMStack(void);

// destroy_MMStack(mms) empties the stack and frees all memory
//   requires:  mms is a valid MMStack
//   effects: all memory for mms is freed, and mms is no longer valid
//   time: O(n), where n = mms_length(mms)
void destroy_MMStack(MMStack mms);

// mms_length(mms) returns the number of entries in mms
//   requires:  mms is a valid MMStack
//   time: O(1)
int mms_length(MMStack mms);

// mms_push(mms, i) puts i on the top of the mms
//   requires:  mms is a valid MMStack
//   effects: i is added to mms, length of mms is updated
//   time: O(1)
void mms_push(MMStack mms, int i);

// mms_pop(mms) removes and returns item from the top of the mms
//   requires:  mms is a valid MMStack
//              mms_length(mms) > 0
//   effects: mms is mutated, length of mms is updated
//   time: O(1)
int mms_pop(MMStack mms);

// mms_min(mms) returns the minimum item stored in the mms
//   requires:  mms is a valid MMStack
//         mms_length(mms) > 0
//   time: O(1)
int mms_min(MMStack mms);

// mms_max(mms) returns the maximum item stored in the mms
//   requires:  mms is a valid MMStack
//              mms_length(mms) > 0
//   time: O(1)
int mms_max(MMStack mms);
