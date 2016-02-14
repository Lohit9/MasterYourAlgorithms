/*
  Given a string with spaces output a string by removing the spaces from it.
  IDeserve string problem-1
*/

#include <iostream>
#include <string>

using namespace std;

string removeSpaces(string str){
  string result;
  for(int i=0; i<str.length() ;i++){
    if(str[i] != ' '){
      result += str[i];
    }
  }
  return result;
}

int main(){
  string test = "  Hi, How are you?  ";
  string result_string = removeSpaces(test);
  cout << "String without spaces is:" << result_string << endl;
  return 0;
}
