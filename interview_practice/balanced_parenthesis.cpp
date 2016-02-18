/*
Problem: Given a string with parentheses (round brackets) and letters, validate the parentheses
Note: This question deals with strings containing only one kind of parentheses,i.e round blackets
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void valid_par(string str){
  int countOpen = 0;
  int countClosed =0 ;
  for(int i=0;i<str.length() ;i++){
    if(str[i] == '('){
      countOpen++;
    }
    else if(str[i] == ')'){
      countClosed++;
    }
  }
  if(countOpen != countClosed){
    cout << "Not Balanced" << endl;
    return;
  }
  cout << "Balanced" << endl;
}

 int main(){
   string input1 = "((BCD)AE)"; //Balanced
   string input2 = ")(PH)N(X)"; // Not balanced
   valid_par(input2);
   return 0;
 }
