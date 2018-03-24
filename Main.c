#include <stdio.h>

int find(int p);

int list[11][2] = {
	{4, 3},
	{3, 8},
	{6, 5},
	{9, 4},
	{2, 1},
	{8, 9},
	{5, 0},
	{7, 2},
	{6, 1},
	{1, 0},
	{6, 7},
};
int intialcount;
int cnt = 10;
int id[10];

int count() {
	return cnt;
}

void union_(int p, int q) {
	int i = find(p);
	int j = find(q);

	if(i == j) return;

	id[i] = j;

	cnt--;
};

int connected(p, q) {
	return find(p) == find(q);
}

int find(int p) {
	while (p != id[p]) {
		p = id[p];
	}

	return p;
}

int main(int argc, char *argv[])
{
	intialcount = sizeof(list) / sizeof(list[0]);

	for (int i = 0; i < cnt; i++) {
			id[i] = i;
	}

	for (int i = 0; i < intialcount; i++) {
			int p = list[i][0];
			int q = list[i][1];
			if (connected(p, q)) {
				continue;
			}
			union_(p, q);
			printf("%d %d \n", p, q);
	}
	printf("%d components \n", count());
    return 0;
}
