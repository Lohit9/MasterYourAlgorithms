#include <cmath>
#include <string>
#include <cstdio>
#include <limits>
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

//Naive solution, complexity O(n^2)
void minimumDistance(int *A, int n){
    int minValue = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
           if(i != j){
            if(A[j] == A[i]){
                if (minValue > abs(j-i)) minValue =  abs(j-i);
            }
          }
        }
    }

    if (minValue == INT_MAX) cout << -1 << endl;
    else cout << minValue << endl;

    return;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0;i < n;i++){
       cin >> A[i];
    }
    minimumDistance(A, n);
    return 0;
}
