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
using namespace std;

int counter( std::vector<int> s, int n )
{
  std::vector<int> table(n+1,0);

  table[0] = 1;
  for ( auto& k : s )
    for(int j=k; j<=n; ++j)
      table[j] += table[j-k];

  return table[n];
}


int main(){
    int N;
    cin >> N;
    cout <<  counter({1,2,5,10,20,50,100},N) << endl;
    return 0;
}
