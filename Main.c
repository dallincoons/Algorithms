#include <stdio.h>

int list[] = {55, 34, 11, 2, 90, 87, 79, 72, 68, 59, 61, 65, 8, 93};
int size;

int less(int x, int y) {
	return x < y;
}

void exch(int *list, int indexA, int IndexB) {
	int swap = list[indexA];
	list[indexA] = list[IndexB];
	list[IndexB] = swap;
}

int * sort(int *list) {
	
	for(int i = 1; i < size; i++) {
		for(int j = i; j > 0 && less(list[j], list[j - 1]); j--) {
			exch(list, j, j - 1);
		}
	}	
	return 0;
}

int main(int argc, char *argv[])
{
	size = sizeof(list) / sizeof(list[0]);

	int *sorted = sort(list);

	for(int i = 0; i < size; i++) {
		printf("%d \n", list[i]);		
	}
}