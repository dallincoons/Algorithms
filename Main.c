#include <stdio.h>

int whitelist[] = {1,11,14,16,20,24,31,37,40,56,78};
int inputs[] =  {1,2,11,14,16,20,21,24,31,37,40,56,78, 99};

int rank(int key, int list[])
{
	int lo = 0;
	int hi = ( sizeof(inputs) / sizeof(int) ) -1;

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (key < list[mid]) hi = mid - 1;
		else if (key > list[mid]) lo = mid + 1;
		else return mid;
	}

	return -1;
}

int main(int argc, char *argv[])
{
	for(int i=0; i < sizeof(inputs) / sizeof(int); i++)
	{
		if(rank(inputs[i], whitelist) == -1) {
			printf("%d \n", inputs[i]);
		}	
	}
}