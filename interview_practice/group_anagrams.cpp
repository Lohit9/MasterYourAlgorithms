/*
Given an array of strings, sort the array in such a way that all anagrams are grouped together.
For example, if the given array input is {"abcd","abc","abce", "acd","abdc"} then output array
should be {"abc","abcd","abdc","abce","acd"}.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// Note: The program is not complete but the solution is implement a comperator function to first sort the chatacters of
// the string and then compare the strings.
// The sort method accepts a comperator parameter which can be used to get the desired result 

struct compare_chars {

  bool operator()(const std::string l, const std::string r) const {
    string s1 =l;
    string s2 =r;
    sort(s1.begin(),s1.end());
    sort(s1.begin(),s1.end());
    return s1==s2;
  }
};

void group_anagrams(string arr[], int len){

   //sort(arr,arr+len,compare_length());
   sort(arr,arr+len,compare_chars());
  for(int i=0 ;i<len ;i++) {
    cout << arr[i] << " " ;
  }
   cout << endl;
}


int main(){
  string input[] = {"abcd","abc","abce", "acd","abdc"};
  int length = sizeof(input)/sizeof(input[0]);
  group_anagrams(input,length);
  return 0;
}

/*Bonus program
Problem: Given 2 integers find the digit that is common
void does_appear(int a, int b){
  string str1 =to_string(a);
  string str2=to_string(b);
  for(int i=0 ;i<str1.length();i++){
    for(int j=0 ;j< str2.length() ;j++){
       if (str1[i] == str2[j]){
         cout << "Index: " << str1[i] << endl;
       }
    }
  }
}
*/
