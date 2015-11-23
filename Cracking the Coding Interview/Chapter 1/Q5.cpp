#include <iostream>
#include <string>
using namespace std;

void CompressString(string str)
{
   int count = 0;
   int len = str.length();
   char c = str[0];
   char s[] = "AAAAAAA";
   int lent = 0;
   for (int i = 0; i<len ; i++)
   {
      cout<< "value of c is: " << c << "  "<< str[i]<< endl;
      if (c == str[i])
      {
        count++;
        continue;
      }
      s[lent]=count;
      lent++;
      s[lent]=count;
      c = str[i];
      count = 1;
   }
   cout << s << endl ;
   /*int lenafter = compress.length();
   if (len < lenafter) return str;
   return compress;*/
}

int main()
{
  string str;
  cout << "Please enter the string" << endl;
  cin >> str ;
  CompressString(str);
  cout << "The compressed string has been printed" << endl;
  return 0;
}
