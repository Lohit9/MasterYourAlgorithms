#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    string brandArr[n];
    string colourArr[n];
    char legArr[n];
    int sizeArr[n];
    for(int i = 0; i < n; i++){
        string brand;
        string colour;
        char leg;
        int size;
        cin >> brand >> size >> colour >> leg;
         brandArr[i] = brand;
         colourArr[i] = colour;
         legArr[i] = leg;
         sizeArr[i] = size;
    }

   for(int j =0 ; j<n ; j++)
   {

   }

    return 0;
}
