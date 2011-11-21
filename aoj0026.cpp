#include <cstdio>
#include <iostream>
using namespace std;

int d[10][10];

inline void drop2(int x, int y) {
	if (x>=0 && x<10 && y>=0 && y<10)
		d[y][x]++;
}

void drop(int x, int y, int size) {
	if (size == 1) {
		drop2(x-1, y);
		drop2(x, y-1);
		drop2(x, y);
		drop2(x, y+1);
		drop2(x+1, y);
	} else if (size == 2) {
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				drop2(x+i, y+j);
	} else /* if (size == 3 */ {
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				drop2(x+i, y+j);
		drop2(x-2, y);
		drop2(x, y-2);
		drop2(x, y+2);
		drop2(x+2, y);
	}
}

int main() {
	int x, y, size;
	for (int y = 0; y < 10; y++)
		for (int x = 0; x < 10; x++)
			d[y][x] = 0;
	
	while (scanf("%d,%d,%d", &x, &y, &size) == 3) {
		drop(x, y, size);
	}

	int zeronum = 0;
	int maxnum = 0;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (d[y][x] == 0)
				zeronum++;
			if (d[y][x] > maxnum)
				maxnum = d[y][x];
		}
	}
	cout << zeronum << endl;
	cout << maxnum << endl;
	return 0;
}

