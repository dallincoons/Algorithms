#include <stdio.h>

int list[] = {55, 34, 11, 2, 90, 87, 79, 72, 68, 59, 61, 65, 8, 93};
int size;

int min(int x, int y)
{
	return y ^ ((x ^ y) & -(x < y));
}

int less(int x, int y) {
	return x < y;
}

void exch(int *list, int indexA, int IndexB) {
	int swap = list[indexA];
	list[indexA] = list[IndexB];
	list[IndexB] = swap;
}

int partition(int *list, int lo, int hi) 
{
	int i = lo;
	int j = hi+1;
	int partitionItem = list[lo];

	while (1) {
		while (less(list[++i], partitionItem)) if (i == hi) break;
		while (less(partitionItem, list[--j])) if (j == lo) break;
		if (i >= j) break;
		exch(list, i, j);
	} 
	exch(list, lo, j);
	return j;
}

void sort(int *list, int lo, int hi) 
{
	if ( hi <= lo) return;
	int j = partition(list, lo, hi);
	sort(list, lo, j-1);
	sort(list, j+1, hi);
	return;
}

int main(int argc, char *argv[])
{
	size = sizeof(list) / sizeof(list[0]);

	sort(list, 0, size - 1);

	for(int i = 0; i < size; i++) {
		printf("%d \n", list[i]);
	}
}