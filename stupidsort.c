#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1

void arrayswap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

unsigned long long factorial(int n)
{
	if (n == 1)
		return n * 1;
	return (n * factorial(n-1));
}

int isSorted(int *array, int n) // 1 if sorted
{
	int i = 0;
	if ( n == 1)
		return 1;
	for (i = 0; i < n-1; i++)
		if (array[i] > array[i+1])
			return 0;
	return 1;
}

unsigned long long stupidsort(int *array, int n)
{
	int i = 0, k, divideBy = 0;
	unsigned long long int swaps = 0;
	while (!isSorted(array, n))
	{
		k = rand() % n;
		if ( i == k)
			continue;
		else
		{
			if (DEBUG) // Show Swaps
				printf("Swapped %d with %d.\n", array[k], array[i]);
			arrayswap(array, k, i);
			i = (i++) % n;
			swaps++;
		}
	}
	return swaps;
}

void arrayprint(int *array, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("_____");
	printf("\n\n");
	for (i = 0; i < n; i++)
		printf("%3d |", array[i]);
	printf("\n");
	for (i = 0; i < n; i++)
		printf("_____");
	printf("\n");
}

int main(int argc, char **argv)
{
		int *array, n, i;
		unsigned long long estimate = 0, swaps = 0;
		srand(time(NULL));
		if (argc != 2)
		{
			printf("Proper Syntax './a.out [dataset size]'\n");
			return 0;
		}
		n = atoi(argv[1]);
		estimate = factorial(n);
		array = calloc(n, sizeof(int));
		for (i = 0; i < n; i++)
			array[i] = rand() % 100;
		printf("Array populated, estimated max swaps is %llu\n", estimate);
		arrayprint(array, n);
		swaps = stupidsort(array, n);
		printf("\nSorted Array: \n" );
		arrayprint(array, n);
		printf("\nCompleted in %llu swaps.\n", swaps);
		free(array);
		return 0;
}
