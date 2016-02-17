/*
Problem: Given a string reverse it completely character by character
example:
"This is a string" -> "gnirts a si sihT"
IDeserve string problem-2
*/

#include <iostream>
#include <string>
using namespace std;

string reverseString(string str){
  string word;
  string revword;
  string result;
  str = str + " ";
  for(int i=0 ;i< str.length(); i++){
    if(str[i] != ' '){
    word += str[i];
  }
  else{
    for(int i =0 ;i<word.length() ; i++){
      revword = word[i]+revword;
    }
    revword += " ";
    result = revword + result;
    word = "";
    revword = "";
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
