#include <iostream>
#include <string>
using namespace std;

string CompressString(string s){
	int n=s.size();int i=1,count=1;char prev=s[0];
	if(n==0)return NULL;
	string res="";
	while(i<n){

		if(s[i]==s[i-1])count++;
		else{
			res+=prev;
			res+=char(count+48);
			count=1;prev=s[i];
		}
		i++;
	}
	res+=prev;
	res+=char(count+48);
	if(res.size()>s.size())return s;
	return res;
}

int main()
{
  string str;
  cout << "Please enter the string" << endl;
  cin >> str ;
  string result = CompressString(str);
  cout << "The compressed string is: " << result << endl;
  return 0;
}
