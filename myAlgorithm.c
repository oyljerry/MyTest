/*
 * myAlgorithm.c
 *
 *  Created on: Jul 27, 2012
 *      Author: admin
 */

#include "common.h"

void myswap(int* x, int* y)
{
	int m;
	m = *y;
	*y = *x;
	*x = m;
}

void myqsort(int* a, int i, int j)
{
	if(i > j)
		return;

	int key = a[i];

	int x = i;
	int y = j;

	while(x < y)
	{
		while((y > x) && (a[y] > key)) y--;
		myswap(&a[x], &a[y]);

		while((x < y) && (a[x] < key)) x++;
		myswap(&a[y], &a[x]);

	}


	myqsort(a, i, y-1);
	myqsort(a, y+1, j);

}

void merge(int a[], int first, int mid, int last, int c[])
{
	int i = first;
	int m = mid;
	int j = mid + 1;
	int n = last;
	int k = 0;
	while (i < m && j < n)
	{
		if(a[i] < a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	}

	while(i < m)
		c[k++] = a[i++];

	while(j < n)
		c[k++] = a[j++];

	for(i = 0; i < k; i++ )
		a[first+i] = c[k];

}

void mergesort(int a[], int first, int last, int temp[])
{
	if(first < last)
	{
		int mid = (first + last)/2;
		mergesort(a, 0, mid, temp);
		mergesort(a, mid+1, last, temp);
		merge(a, first, mid, last, temp);
	}
}
