#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int mostOccuring(int a[], int plen)
{
    int max_count = 0;
    int popular = 0;
    for (int i=0;i<plen;i++)
    {
       int count=1;
       for (int j=i+1;j<5;j++)
           if (a[i]==a[j])
               count++;
       if (count>max_count)
          max_count = count;
    }

    for (int i=0;i<plen;i++)
    {
       int count=1;
       for (int j=i+1;j<5;j++)
           if (a[i]==a[j])
               count++;
       if (count==max_count)
          popular = a[i];
    }
     return popular;

}

int cipher(string P,string E)
{
    int count = 0;
    int width = abs(P[0] - E[0]);
    int plen = P.length();
    char El[plen];
    int prev = width;
    int test = 0;
    int positive = 0;
    int negative = 0;
    int widthArray[plen];
    for (int j=0 ; j<plen ; j++)
    {
        width = abs(P[j] - E[j]);
        widthArray[j] = width;
     }

    width = mostOccuring(widthArray,plen);

    for (int i=0; i<plen ; i++)
    {
        El[i] = P[i]+width;
        if (El[i] != E[i] )
        {
            count++;
        }

    }

    return count;

}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string P;
        string E;
        cin >> P >> E;
        cout << cipher(P,E) << endl;
    }
    return 0;
}
