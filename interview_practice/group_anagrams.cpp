/*
Given an array of strings, sort the array in such a way that all anagrams are grouped together.
For example, if the given array input is {"abcd","abc","abce", "acd","abdc"} then output array
should be {"abc","abcd","abdc","abce","acd"}.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void group_anagrams(string arr[], int len){

}


int main(){
  string input[] = {"abcd","abc","abce", "acd","abdc"};
  int length = sizeof(input)/sizeof(input[0]);
  group_anagrams(input,length);
  return 0;
}
