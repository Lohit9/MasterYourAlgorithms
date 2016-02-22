/*You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to
merge B into A in sorted order.*/

#include <iostream>
using namespace std;

int* merge( int *L, int *R){

  int leftLen = sizeof(L)/sizeof(L[0]) ;
  int rightLen = sizeof(R)/sizeof(R[0]) ;
  int i = 0;
  int j=0;
  int k=0;
  int newlen = leftLen+rightLen;
while(i<leftLen && j<rightLen){
    if(L[i] < R[j]){
      L[k]=L[i];
      i++;
      k++;
    }
    else{
      L[k] = R[i];
      j++;
      k++;
    }
}

while(i<leftLen){
  L[k] = L[i];
  i++;
  k++;
}
while(j<rightLen){
  L[k] = R[j];
  j++;
  k++;
}
return L;
}
