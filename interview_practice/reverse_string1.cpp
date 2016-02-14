/*
Problem: Given a string reverse it word by word
example:
"This is a string" -> "string a is This"
IDeserve string problem-2
*/
#include <iostream>
#include <string>
using namespace std;

string reverseString(string str){
  string word;
  string result;
  str = str + ' ';
  for(int i=0;i<str.length() ;i++){
    if(str[i] != ' '){
      word += str[i];
    }
    else{
      word += " ";
      result = word+result;
      word = "";
    }
  }
  return result;
}

int main(){
  string input = "This is a string";
  string result = reverseString(input);
  cout << "The reverse string is:" << result << endl;
  return 0;
}
