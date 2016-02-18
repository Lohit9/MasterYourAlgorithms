/*
Problem: Given a string find the first non repeating character in the string
Input: ABCDEFGHIJKLADTVDERFSWVGHQWCNOPENSMSJWIERTFB
Output: K
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

void non_repeating(string str){
   int arr[26] ={0}; // Assuming we only want to deal with the english alphabet
   for(int i=0 ;i< str.length() ;i++){
     int diff = str[i] -'A';
     arr[diff]++;
   }
   for(int j = 0; j<26 ; j++){
     if(arr[j] == 1){
       char ch = 'A'+j;
       cout << "The first non repeating character is: " << ch << endl;
       return;
     }
   }
}

void all_repeating(string str){
  map<char,int>hash;
  for(int i=0 ;i<str.length();i++){
    hash[str[i]]++;
  }
  cout << "the string of repeated characters is: " ;
  for(auto j=hash.begin() ;j!=hash.end();j++){
    if(j->second > 1){
      cout << j->first ;
    }
  }
  cout << endl;

}

int main(){
  string input = "ABCDEFGHIJKLADTVDERFSWVGHQWCNOPENSMSJWIERTFB";
  non_repeating(input);
  //all_repeating(input);
  return 0;
}
