#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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





