#include <stdio.h>

int list[] = {55, 34, 11, 2, 90, 87, 79, 72, 68, 59, 61, 65, 8, 93};
int size;

int less(int x, int y) {
	return x < y;
}

int merge(int *list, int lo, int mid, int hi) {
	int i = lo;
	int j = mid + 1;
	int aux[size];

	for (int k = lo; k <= hi; k++) {
		aux[k] = list[k];
	}
	for (int k = lo; k <= hi; k++) {
		if (i > mid) {
			list[k] = aux[j++];
		} else if (j > hi) {
			list[k] = aux[i++];
		} else if (less(aux[j], aux[i])) {
			list[k] = aux[j++];
		} else {
			list[k] = aux[i++];
		}
	}
	return 0;
}

int * sortList(int *list, int lo, int hi) {
	if (hi <= lo) return 0;
	int mid = lo + (hi - lo)/2;
	sortList(list, lo, mid);
	sortList(list, mid+1, hi);
	merge(list, lo, mid, hi);
	return 0;
}

int sort(int *list) 
{
	int aux[size];
	sortList(list, 0, size - 1);
	return 0;
}

int main(int argc, char *argv[])
{
	size = sizeof(list) / sizeof(list[0]);

	sort(list);

	for(int i = 0; i < size; i++) {
		printf("%d \n", list[i]);
	}
}