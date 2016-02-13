/*
Problem:

Find the minimum number of character deletions required for two given strings to be anagrams

Input:
cde
abc

Output:
4

difficulity: easy
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void minDeletions(string str1, string str2){
  if(str1 == str2){
    cout << 0 << endl;
    return;
  }

  int arr1[26] = {0};
  int diff,diff1;
  for(int i =0; i<str1.length() ;i++){
    arr1[str1[i]-'a']++;
  }

int arr2[26] = {0};
  for(int j=0; j<str2.length() ; j++){
    arr2[str2[j]-'a']++;
  }
    int count = 0;
  for(int k=0; k<26 ; k++){
    if(arr1[k]!=arr2[k]){
      count += abs(arr1[k]-arr2[k]);
    }
  }

  cout << count << endl;
}


int main(){
  string str1,str2;
  cin >> str1;
  cin >> str2;
  minDeletions(str1,str2);
  return 0;
}
