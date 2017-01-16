ababab

count of tuples

(x,y)

1. x = index of 'a'
2. y = index of 'b'
3. x < y

(0,1)

(0,3)

012345
ababab => (0,1) (0,3) (0,5) (2,3) (2,5) (4,5) => 6

find occ of a # O(n)
  find all occ's of b   #O(m)


a : [0,2,4]
b : [1,3,5]

(0,(for every y > x))

0,[1,3,5]  2,[3,5] 4,[5]

O(1), O(m)

a b a b a b
0 1 2 3 4 5


ababab
^
index of a : no.of occ of b's in rest of string
[3,2,1]

01234
aabbb  12



aab | bb
 6

abbba | ...
9

abbb | bbba
3

abbba = 3
3

ababab
3 5 6
