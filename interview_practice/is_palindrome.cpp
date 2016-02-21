/*
Verify if string is palindrome
*/

#include <iostream>
#include <string>
using namespace std;

void is_palindrome(string str){
  int len;
   if(str.length() % 2 == 0 ) len = str.length()/2;
   else len = (str.length() -1)/2;
   for(int i=0 ;i <len ;i++){
     if(str[i] != str[str.length()-i-1]){
       cout << "not a palindrome" << endl;
       return;
     }
   }
   cout << "Is a palindrome" << endl;
}

int main(){
  string input = "kayak";
  is_palindrome(input);
  return 0;
}
