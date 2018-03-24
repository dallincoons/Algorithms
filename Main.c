#include <stdio.h>

int list[] = {55, 34, 11, 2, 90, 87, 79, 72, 68, 59, 61, 65, 8, 93};
int size;

int min(int x, int y)
{
	return y ^ ((x ^ y) & -(x < y));
}

int * sort(int *list) {
	int minIndex = 0;
	int sorted[size];
	for(int i = 0; i < size; i++) {
		minIndex = i;
		for(int j = i+1; j < size; j++) {
			if (min(list[j], list[minIndex]) < list[minIndex]) {
				minIndex = j;
			}
		}
		int swap = list[i];
		list[i] = list[minIndex];
		list[minIndex] = swap;
	}

	return list;
}

int main(int argc, char *argv[])
{
	size = sizeof(list) / sizeof(list[0]);

	int *sorted = sort(list);

	for(int i = 0; i < size; i++) {
		printf("%d \n", list[i]);		
	}
}