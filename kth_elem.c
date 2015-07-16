/*There are 3 ways to solve this question :

Method 1

Use sorting. Return first k elements of this array or kth element of sorted array whatever required.

Method 2 (Using temporary array of size K)--> I used tried to use this 

1) Store the first k elements in a temp array temp[0..k-1].
2) Find the smallest element in temp[].
3) For each element x in arr[k] to arr[n-1]
If x is greater than the minimum then remove minimum element and insert x.
4) Print final k elements of temp[]

Time Complexity: O((n-k)*k).

If we want the kth Largest only then sort the array and get kth largest then complexity O((n-k)*k + klogk)

Method 3 (Using quick sort)*/


//------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// This is not a working program, its just a tentative program. The code may result in memory leaks
int min_element(int a[] , int len)
{
	int temp[len];
	int min =0;
	for (int i=0 ; i<len ; i++)
	{
		if (a[i]< min)
		{
			min = a[i];
			times++;
			if (times == k) return min;
			a[] = delete(a[] , len, min);
		}
	}

}


void del_elem(int a[] , int len , int min)
{
	int index = 0;
	for (int i=0 ; i<len ; i++)
	{
		if (a[i] == min)
	   {
	   	  a[i] =a[i+1]
	   	  index = i+1;
	   }
	}

	for (int i = index ; i<len-1 ; i++)
	{
        a[i] = a[i+1]

	}

	return a[];



}





