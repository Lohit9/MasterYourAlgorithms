/*
Question: Find pairs in an integer array whose sum is equal to 10 (bonus: do it in linear time)
*/
//The below solution has a worst case runtime of O(n^2)

#include <iostream>
#include <algorithm>
using namespace std;

int pairs(int arr[], int len){
  int flag =0;
  for(int i=0; i<len ; i++){
    for (int j=i+1;j<len;j++){
      int sum = arr[i] + arr[j];
      if(sum == 10){
        cout<< "pair found" << arr[i]<< "&" << arr[j] << endl;
        flag = 1;
      }
    }
  }
  if (flag == 0){
    cout << "Pair not found" << endl;
  }
  return 0;
}

int pairsbonus(int arr[], int len){
  //needs to be added after I learn how to use hash maps
  return 0;
}

int main(){
  int arr[] = {5,4,3,5,6,1};
  pairs(arr, 6);
  return 0;
}
