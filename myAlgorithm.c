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
