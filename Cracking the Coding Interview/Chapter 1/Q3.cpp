#include <iostream>
#include <string>
using namespace std;

bool arePalindromes(string s1, string s2)
{
  int len1 = s1.length();
  int len2 = s2.length() ;
  if(len1 != len2) return false;
  int flag = 1;
  for (int i=0; i<len1 ; i++)
  {
    if (flag == 0) return false;

    for(int j=0; j<len1 ; j++)
    {
      if (s1[i] != s2[j])
      {
        flag = 0;
      }
      else
      {
        flag = 1;
        break;
      }
    }
  }

  if (len1 == 1)
  {
    if (s1 != s2) return false;
  }

  return true;

}


int main()
{
  string s1,s2 ;
  cout << "enter string 1" << endl;
  cin >> s1;
  cout << "enter string 2" << endl;
  cin >> s2;
  bool result = arePalindromes(s1,s2);
  if (result == 1 ) cout << "true" << endl;
  else cout << "false" << endl;
  return 0;
}
