/*
Implement a method to perform basic string compression using the counts of repeated characters
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void compress_string(string str){
  int count = 1;
  char prev = str[0];
  string result;
  for(int i=1 ;i<= str.length() ;i++){
    if(prev == str[i]){
      count++;
    }
    else{
      result += prev+to_string(count);
      prev = str[i];
      count = 1;
    }
  }
  if(result.length() < str.length())  cout << result << endl;
  else{
    cout << str << endl;
  }
}

int main(){
  string input = "aabccdeeaa";
  compress_string(input);
  return 0;
}
