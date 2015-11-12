// Program to determine if a string has all unique characters
#include <iostream>
#include <string>
using namespace std;

string toLower(string& c)
{
  int length =  c.length();
  char lower;

  for (int i=0 ; i<length ; i++)
  {
    if ( 'A' <= c[i] && c[i] <= 'Z')
    {
    c[i] = c[i] - 'A' + 'a';
    }
  }

  return c ;
}


bool isUnique(string& str)
{
  int len = str.length();
  string s = toLower(str);
  cout<< "string is: " << s << endl;
  int arr[256] = {0};
  int j = 0;
  if (len>256) return false;
  for (int i=0 ; i<len ; i++)
  {
    j = s[i] - 'a' ;
    arr[j]++ ;
    if (arr[j] > 1)
    {
      cout << "The character that has been repeated is: " << s[i] << endl;
      return false ;
    }

  }
  return true ;
}


int main()
{
  string str ;
   cout << "Please enter a string you want to check" << endl;
   cin >> str ;
   cout << "The string you have entered for testing is: " << str << endl;
    bool result =  isUnique(str);
    cout << result << endl ;
    return 0;
}
