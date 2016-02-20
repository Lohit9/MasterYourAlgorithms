/*
Write a method to replace all spaces in a string with '%20'.
*/

#include <iostream>
#include <string>
using namespace std;


void replace_spaces(string str){
  string strUntilNow;
  for(int i=0 ;i< str.length() ;i++){

    if(str[i] == ' '){
        strUntilNow = strUntilNow + "%20";
    }
    else {
      strUntilNow = strUntilNow + str[i];
    }

  }
  string input = strUntilNow;
  cout << input << endl;
}


int main(){
  string input = "lohit will crack the google interview ";
  replace_spaces(input);
  return 0;
}
