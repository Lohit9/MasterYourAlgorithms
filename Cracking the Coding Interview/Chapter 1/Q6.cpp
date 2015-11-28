#include <iostream>
#include <string>
using namespace std;

void rotate(int n)
{
   int a[n][n];
   int b[n][n];
   int c =0;
   for (int i =0; i<n ; i++){
     for (int j=0; j<n ; j++){
        a[i][j]=c;
        cout << a[i][j] << "  " ;
       }
      c++;
      cout<<endl;
    }
   cout << endl;
    for(int i =0; i<n ; i++)
    {
      for (int j =0; j<n ; j++)
      {
        b[j][n-i-1] = a[i][j];
      }
    }

    for (int i =0; i<n ; i++){
      for (int j=0; j<n ; j++){
        cout << b[i][j] << "  " ;
       }
      c++;
      cout<<endl;
    }

}

int main()
{
  int n = 0;
  cout << "please enter the value of N" << endl;
  cin >> n;
  rotate(n);
  return 0;
}
