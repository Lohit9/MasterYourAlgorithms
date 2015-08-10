// a Count is an ADT for storing the count (number of occurrences)
// of an integer within a sequence.

// There is a part A (integers are in the range 1..100)
// and a part B (no restrictions on integers -- any valid C integer)

// for part A, many functions are O(1), but remember that O(100) is O(1)

// for part B, unique integers will be encountered in an order that ensures
// that the resulting BST inserting the integers will be automatically "balanced"
// to guarantee O(log n) behaviour (e.g., for next())

struct count;

typedef struct count *Count;

// create_Count() creates a new empty Count ADT
//   effects: allocates a struct count on the heap, 
//     client must eventually call destroy_Count
//   time: O(1)
Count create_Count(void);

// destroy_Count(c) frees all memory in the Count ADT
//   requires:  c is a valid Count
//   effects: all memory for c is freed, and c is no longer valid
//   time: [part A] O(1)
//         [part B] O(n), where n = unique(c)
void destroy_Count(Count c);

// next(c, i) add an occurrence of i to the Count ADT 
//   requires:  c is a valid Count
//              [part A] 1 <= i <= 100
//   effects: value of count(c,i) is incremented by 1
//   time: [part A] O(1)
//         [part B] O(log n), where n = unique(c)
void next(Count c, int i);

// total(c) returns the total number of times next() has been called
//   requires:  c is a valid Count
//   time: O(1)
int total(Count c);

// unique(c) returns the number of unique integers seen by next()
//   requires:  c is a valid Count
//   time: O(1)
int unique(Count c);

// count(c, i) returns the total number of times next(c,i) has been called
//   requires:  c is a valid Count
//              [part A] 1 <= i <= 100
//   time: [part A] O(1)
//         [part B] O(log n), where n = unique(c)
int count(Count c, int i);

// mostfreq(c) returns the number i with the largest count(c,i)
//     NOTE: if there is a tie, it should return the first number that
//           reached count(c,i) 
//   requires:  c is a valid Count
//              total(c) > 0
//   time: O(1)
int mostfreq(Count c);

// stats(c) does a printf("%d: %d\n", i, count(c,i))
//     for each unique i in c in ascending order
//     [see the example below]
//   requires:  c is a valid Count
//   effects: prints unique(c) lines of output
//   time: [part A] O(1)
//         [part B] O(n), where n = unique(c)
void stats(Count c);

/* 
EXAMPLE:
For the sequence: 1 2 1 3 7 1 2 3 1 1
you would call next(c,1); next(c,2); next(c,1)...
total(c) = 10
unique(c) = 4
count(c,1) = 5
count(c,6) = 0
count(c,7) = 1
mostfreq(c) = 1

(TIP: you should not be storing the full sequence, let alone sorting it)

stats(c) would output:
1: 5
2: 2
3: 2
7: 1
*/
