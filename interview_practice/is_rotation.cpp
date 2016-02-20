/*
  Given a method isSubstring find whether a string is a rotation of another using only one call to the isSubstring
  function
*/
#include <iostream>
#include <string>
using namespace std;

bool is_rotation(string str1, string str2){
  if(str1.length() =! str2.length()) return false;
  //also check if the length > 0 for both strings
  string s1s2 = str1+str2;
  return isSubstring(s1s2,s2);
}

int main(){
  string str1 = "waterbottLe";
  string str2 = "erbottLewat";
  is_rotation(str1, str2);
  return 0;
}
