// Given two arrays of integrs, find a pair of values (one from each array) that you can swap to give the two arrays the same sum.

// {4, 1, 2, 1, 1, 2} = 11 +3
// {3, 6, 3, 3} = 15 - 2        

// {1, 3}
// {4, 3, 2, 1, 1, 2} = 13
// {1, 6, 3, 3} = 13

/*

sum of arr1 and arr2

for(i)
  for(j)
      sum1 - arr1[i] + arr2[j] = sum2 - arr2[j] + arr1[i]
      sum1 - sum2 + 2*arr2[j] = 2*arr1[i]
     =>  arr1[i] - arr2[j] = (sum1-sum2)/2
*/

//Runtime O(n^2)

int* bruteFPairsSwap(int arr1[], int arr2[]){
  sum1 = arr1.Sum();
  sum2 = arr2.Sum();
  int pairArr[2];
  for(int i= 0; i<sum1; i++){
    for(int j=0; j<sum2; j++){
      if ((arr1[i] - arr2[j]) ==  (sum1-sum2)/2)){
        pairArr[0] = arr1[i];
        pairArr[1] = arr2[j];
        break;
      }
    }
  }
   return pairArr;
}

//  X = arr2[j] = (sum2  - sum1 + 2* arr1[i]) / 2
// {4, 1, 2, 1, 1, 2} = 11+ 3 - 1  {1,1,1,2,2,4}
// arr1[i] = 4
// X = (15 - 11 + 8) / 2 = 6

// X = {arr2[j]: j}
Y = arr[i];

// {3, 6, 3, 3} = 15 - 3 + 1       {3,3,3,6}

// {1, 3}
// {4, 3, 2, 1, 1, 2} = 13
// {1, 6, 3, 3} = 13

int* FPairsSwap(int arr1[], int arr2[]){
  sum1 = arr1.Sum();
  sum2 = arr2.Sum();
  int* pairArr = new int(2);

  hash = {arr2[j]: j};

  for(int i= 0; i<sum1; i++){
    int toSearch = (sum2  - sum1 + 2 * arr1[i]) / 2;
    if (hash.find(toSearch)) return (arr1[i], toSearch);
  }

  delete pairArr;
  return nullptr;
}
