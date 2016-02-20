/*
 Problem: Given a string, find all the permutations of the string.
 For example:
 Input String: abc
 Output: {bca, acb, abc, cba, bac, cab}
*/

#include <iostream>
#include <string>
using namespace std;

void swap(char *c1, char *c2){
  char *temp = c1;
  c1 = c2;
  c2 = temp;
}

void all_permutations(string str, int startIndex, int EndIndex){
  if(startIndex == EndIndex){
    cout << str << endl;
  }
  else{
    for(int i=startIndex ; i<EndIndex ; i++){
      swap(str[startIndex],str[i]);
      all_permutations(str,startIndex+1,EndIndex);
      swap(str[startIndex],str[i]);
    }
  }
}

int main(){
  string input = "abc";
  all_permutations(input,0, input.length());
  return 0;
}
