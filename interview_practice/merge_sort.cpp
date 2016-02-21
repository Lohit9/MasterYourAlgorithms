/*
 Program to implement merge sort
*/

#include <iostream>
using namespace std;

int fib(int n){
  if(n<2) return n;
  return fib(n-1)+fib(n-2);
}


void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
   int i=0;
   int j=0;
   int k=0;
   while((i<leftCount) && (j<rightCount)){
     if(L[i]<R[j]){
       A[k] = L[i];
       k++;
       i++;
     }
     else
     {
       A[k] = R[j];
       j++;
       k++;
     }
  }
  while(i<leftCount){
    A[k] = L[i];
    k++;
    i++;
  }
  while(j<rightCount){
    A[k] = R[j];
    k++;
    j++;
  }

}


void MergeSort(int *A,int n) {
    int mid, *L,*R;
    if(n<2) return;
    mid = n/2;
    L = new int[mid];
    R = new int[n-mid];
    for(int i=0; i<mid;i++){
      L[i] = A[i];
    }
    for(int i=mid; i<n;i++){
      R[i-mid] = A[i];
    }
    MergeSort(L,mid);
    MergeSort(R,n-mid);
    Merge(A,L,mid,R,n-mid);
    delete L;
    delete R;
}

int main(){
  int arr[] = {2,4,1,6,8,5,3,7};
  int len = sizeof(arr)/sizeof(arr[0]);
  MergeSort(arr,len);

  for(int i=0 ;i<len;i++){
    cout << arr[i] << " " ;
  }
  cout<< endl;
  return 0;
}
