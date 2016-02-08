/*
Problem:
Shashank likes strings in which consecutive characters are different. For example, he likes ABABA, while he doesn't like ABAA. Given a string containing characters A and B only, he wants to change it into a string he likes. To do this, he is allowed to delete the characters in the string.
Your task is to find the minimum number of required deletions.

Sample Input:
5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB

Sample Output:
3
4
0
0
4
Difficulity level: easy
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void noOfDeletions(string str){
    int delCount =0;
    char prevChar = ' ';
   for(int i=0; i<str.length();i++){
       if(prevChar!=str[i]){
           prevChar = str[i];
       }
       else {
           delCount++;
       }
   }
    cout<<delCount<< endl;
}

int main() {
    int n;
    string str;
    cin>>n;
    while(n){
        cin>>str;
        noOfDeletions(str);
        n--;
    }

    return 0;
}
