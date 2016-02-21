/*
Given a string of letters, implement method that outputs string of 1's and 0's of the same size corresponding to if a
selected letter is in that position in the input string.
*/
#include <iostream>
#include <string>
using namespace std;

void rename_letter(string str, char c){
  if(str.length() == 0) {
    cout << 0 << endl;
    return;
  }

  for(int i=0; i<str.length();i++){
    if(str[i] == c){
      cout<< 1 ;
    }
    else cout << 0;
  }
  cout << endl;
}

int main(){
  string input = "abcbdsjkada";
  char c = 'a';
  rename_letter(input,c);
  return 0;
}
