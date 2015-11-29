#include <iostream>
#include <string>
using namespace std;

//assuming that isSubstring is a given function(as given in the question)

void checkRotated(string s1, string s2){
  int len1 = s1.length();
  if (len1 != s2.length() | len1 != 0)
  {
    string xy = s1+s1;
    if isSubstring(slsl,s2)
    {
      cout << "yes"<< endl;
    }
  }
  cout << "no"<< endl;
}

int main()
{
  string str;
  cout<< "enter string"<< endl;
  cin >> str1
  cout >> "enter rotated string"<< endl;
  cin >> str2
  checkRotated(str1,str2);
  return 0;
}
