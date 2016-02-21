/*
  Algorithm to implement insertion sort
*/
#include <iostream>
#include <string>
using namespace std;

//Insertion sort algorithm
/*
Complexity:
  best case - O(n)
  worst case - O(n^2)
*/

#include <iostream>
#include <string>
using namespace std;

void insertion_sort(int *A, int len){
    int hole, value;
   for(int i=0; i<len ;i++){
    value = A[i];
    hole = i;
    while((hole >0) && (A[hole-1]>value)){
         A[hole] = A[hole-1];
         hole = hole -1;
    }
    A[hole] = value;
  }
}

int main(){
  int arr[] = {7,2,4,1,5,3};
  int len = sizeof(arr)/sizeof(arr[0]);
  insertion_sort(arr,len);
  for(int i=0 ;i<len;i++){
    cout << arr[i] << " " ;
  }
  cout<< endl;
  return 0;
}
