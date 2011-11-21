#include <iostream>
#include <cstdio>

using namespace std;

int cross(int ax, int ay, int bx, int by, int cx, int cy) {
	int x1 = bx-ax, x2 = cx-ax;
	int y1 = by-ay, y2 = cy-ay;
	return x1*y2 - x2*y1;
}

int main() {
	int n;
	int seq = 0;
	int ax, ay, bx, by, cx, cy;
	while (1) {
		cin >> n;
		if (!n)
			break;
		seq++;
		int area = 0;
		cin >> ax >> ay >> bx >> by;
		for (int i = 0; i < n-2; i++) {
			cin >> cx >> cy;
			area += cross(ax,ay,bx,by,cx,cy);
			bx = cx, by = cy;
		}
		printf("%d %.1f\n", seq, (double)(area>=0.0 ? area : -area) * 0.5);
	}
	return 0;
}

