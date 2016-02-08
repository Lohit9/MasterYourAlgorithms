/*
Problem Statement:
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Source: LeetCode
ProblemTags: Math
*/

#include <iostream>
#include <algorithm>
using namespace std;

//Naive solution, this solution works but fails for large numbers such as: 824883294 :(

int NumberOfOnes(int number){
  int counter =0;
  if(number == 0) return 0;
  if(number == 1) return 1;

  do{
    if(number%10 == 1){
      counter++;
    }
    number = number/10;
  }
  while(number);
  return counter;

}

int countDigitOne(int n) {
    int count=0;
    for(int i=0; i<=n ;i++){
        count+= NumberOfOnes(i);
    }
    return count;
}

// This can be solved by observing some sort of patter and then using dynamic programming-this method might be a bit of overkill

// Method: Calculate the occurence of one on each bit

int countDigitOne(int n){
  if (n <= 0) return 0;
      int q = n, x = 1, ans = 0;
      do {
          int digit = q % 10;
          q /= 10;
          ans += q * x;
          if (digit == 1) ans += n % x + 1;
          if (digit >  1) ans += x;
          x *= 10;
      } while (q > 0);
      return ans;
}
