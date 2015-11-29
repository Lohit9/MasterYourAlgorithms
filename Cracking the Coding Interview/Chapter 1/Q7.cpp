#include <iostream>
#include <string>
using namespace std;



void rotate(int n,int m)
{

   int a[n][m];
   int b[n][m];
   int c =1;
   for (int i =0; i<n ; i++){
     for (int j=0; j<m ; j++){
        a[i][j]=c;
        cout << a[i][j] << "  " ;
       }
      c++;
      cout<<endl;
    }
   cout << endl;

  int k = 0;
   for (int i=0; i<n; i++){
     for (int j=0; j<m ; j++){

       if (a[i][j]==0)
       {
         while(k<n)
         {
           a[k][j] = 0;
           k++;
         }
         k=0;
         while(k<m)
         {
           a[i][k]=0;
           k++;
         }
       }

       b[i][j]=a[i][j];

     }
   }
for (int i =0; i<n ; i++){
      for (int j=0; j<m ; j++){
        cout << b[i][j] << "  " ;
       }
      c++;
      cout<<endl;
    }

}


int main()
{
  int m = 0;
  int n = 0;
  cout << "please enter the value of N" << endl;
  cin >> n;
  cout << "enter the value of m" << endl;
  cin >> m;
  rotate(n,m);
  return 0;
}
