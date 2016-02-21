/*
Asked in Google interview
Given a string remove unecessary spaces
*/

#include <iostream>
#include <string>
using namespace std;

void removeSpaces(string str){
  if(str.length() == 0) return;
  string result;
  int spaceCount;
  for(int i=0;i<str.length() ;i++){
    if(str[i] == ' '){
      spaceCount ++;
      if(spaceCount == 1){
        result += str[i];
      }
    }
    else{
      result += str[i];
      spaceCount = 0;
    }
  }
  cout << result << endl;
}

int main(){
  string input = "I   live   on     earth ";
  removeSpaces(input);
  return 0;
}
