/*
  Post-fix expression evaluation
  Problem: Given: An array of strings, every string being either an operand or an operator, in Reverse Polish Notation,
  find out the value of the expression.
  Input 1:
  20 30 +
  Output 1:
  50
  ----------------
  Input 2:
  5 1 2 + 4 * + 3 -
  Output 2:
  14
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int eval(string *exp, int length){
   int result=0;
   stack<string>mystack;
   for(int i=0; i<length;i++){
     if(((exp[i] != "+")&&(exp[i] != "-"))&&((exp[i] != "*")&&(exp[i] != "/"))){
       mystack.push(exp[i]);
     }
     else{
       string op=exp[i];
      if(op == "+"){
        int a = stoi(mystack.top());
        mystack.pop();
        int b = stoi(mystack.top());
        mystack.pop();
        result = a + b;
        mystack.push(to_string(result));
      }
      if(op == "-"){
        int a = stoi(mystack.top());
        mystack.pop();
        int b = stoi(mystack.top());
        mystack.pop();
        result = b-a;
        mystack.push(to_string(result));
      }
      if(op == "*"){
        int a = stoi(mystack.top());
        mystack.pop();
        int b = stoi(mystack.top());
        mystack.pop();
        result = a * b;
        mystack.push(to_string(result));
      }
      if(op == "/"){
        int a = stoi(mystack.top());
        mystack.pop();
        int b = stoi(mystack.top());
        mystack.pop();
        result = a/b;
        mystack.push(to_string(result));
      }
     }
   }
   return result;
}

int main(){
  string input[] = {"5","1","2","+","4","*","+","3","-"};
  int length = sizeof(input)/sizeof(input[0]);
  int result = eval(input,length);
  cout << "The result of expression is: " << result << endl;
  return 0;
}
