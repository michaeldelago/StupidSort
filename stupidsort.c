#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrayswap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int isSort(int *array, int n) // 1 if sorted
{
	int i = 0;
	if ( n == 1)
		return 1;
	for (i = 0; i < n-1; i++)
		if (array[i] > array[i+1])
			return 0;
	return 1;
}

void stupidsort(int *array, int n)
{
	int i = 0, k;
	long int iterations = 0;
	while (!isSort(array, n))
	{
		k = rand() % n;
		arrayswap(array, k, i);
		iterations++;
		i = (i++) % n;
	}
	printf("\nCompleted in %d iterations\n", iterations);
}

void arrayprint(int *array, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n"); // I'm lazy, fight me.
}

int main(int argc, char **argv)
{
		int *array, n, i;
		srand(time(NULL));
		if (argc > 2 || argc == 0)
			printf("Proper Syntax './a.out [dataset size]'\n");
		n = atoi(argv[1]);
		// printf("How large is your dataset?\n");
		// scanf("%d", &n);
		array = calloc(n, sizeof(int));
		for (i = 0; i < n; i++)
			array[i] = rand() % 100;
		printf("array populated\n");
		arrayprint(array, n);
		stupidsort(array, n);
		arrayprint(array, n);
}