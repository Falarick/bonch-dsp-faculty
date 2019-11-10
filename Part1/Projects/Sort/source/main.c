#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>



void Merge(int* a, size_t p, size_t q, size_t r, int* L, int* R)
{
	size_t n1 = q - p;
	size_t n2 = r - q;
	for (size_t i = 0; i < n1; ++i)
	{
		L[i] = a[p + i];
	}
	for (size_t i = 0; i < n2; ++i)
	{
		R[i] = a[q + i];
	}
	L[n1] = 1000000;
	R[n2] = 1000000;
	size_t i = 0;
	size_t j = 0;
	for (size_t k = p; k < r; ++k)
	{
		if (L[i] < R[j])
		{
			a[k] = L[i];
			++i;
		}
		else
		{
			a[k] = R[j];
			++j;
		}
	}
}

void MergeSort(int* a, size_t begin, size_t end, int* L, int* R)
{
	if ((end - begin) != 1)
	{
		size_t mid = (begin + end) / 2;
		MergeSort(a, begin, mid, L, R);
		MergeSort(a, mid, end, L, R);
		Merge(a, begin, mid, end, L, R);
	}
}

int main( )
{
	int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int L[6];
	int R[6];
	
	MergeSort(a, 0, 10, L, R);
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

    return 0;
}