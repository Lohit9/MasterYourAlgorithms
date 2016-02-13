/*
Problem:
 Given an array arr of n unique non-negative integers, how can you most efficiently find a non-negative integer
 that is not in the array?

 Your solution should return such an integer or null if arr contains all possible integers.
 Analyze the runtime and space complexity of your solution.
*/

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <limits>
using namespace std;

int different_number(int arr[], int len){
  map<int,int> arrMap;

  if (len == INT_MAX){
    cout << "The array you entered is complete-you have covered all possible integers!" << endl;
    return 0;
  }

  for(int i=0; i<len ;i++){
    arrMap[i] = 0;
    arrMap[arr[i]] = 1;
  }

  for(auto iterator = arrMap.begin() ; iterator != arrMap.end() ; iterator++){
    if(iterator->second != 1){
      cout << "The non positive value that is not present in the array is: " << iterator->first << endl;
      break;
    }
  }

  return 0;

}

int main(){
  int arr[8] = {0,1,2,6};
  int len = sizeof(arr)/sizeof(arr[0]);
  different_number(arr,len);
  return 0;
}
