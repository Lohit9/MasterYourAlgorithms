#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string remvSpaces(string str,int leng)
{
  int count = 0;
  int len = leng - 1 ;
  string newstr(len,'a');
  for (int i = 0; i<len ; i++)
   {
     if (isspace(str[i]))
     {
         newstr[i+count] = '%';
         newstr[i+count+1] = '2';
         newstr[i+count+2] = '0';
     }
     else
     {
       newstr[i] = str[i];
     }
   }
   return newstr;
}

int main()
{
  string str;
  int len = 13;
  cout << "Enter the string and character length" << endl;
  cin >> str  ;
  string result = remvSpaces(str,len);
  cout << "The string without spaces is: " << result << endl;
  return 0;
}
