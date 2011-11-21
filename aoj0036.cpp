#include <iostream>
#include <cstdio>
using namespace std;

char field[8][9];
struct P { int x, y; };
P pat[7][3] = {
	{{1,0}, {0,1}, {1,1}},
	{{0,1}, {0,2}, {0,3}},
	{{1,0}, {2,0}, {3,0}},
	{{-1,1}, {0,1}, {-1,2}},
	{{1,0}, {1,1}, {2,1}},
	{{0,1}, {1,1}, {1,2}},
	{{1,0}, {-1,1}, {0,1}},
};

bool ok(int x, int y) {
	if (x<0 || x>=8 || y<0 || y>=8) return false;
	return (field[y][x] == '1');
}

int main() {
	while (scanf("%s", &field[0]) == 1) {
		for (int i = 1; i < 8; i++)
			scanf("%s", &field[i]);

		int x0, y0;
		for (int i = 0; i < 8*8; i++) {
			int x = i%8, y = i/8;
			if (ok(x, y)) {
				x0 = x, y0 = y;
				break;
			}
		}

		char kind;
		for (int i = 0; i < 7; i++) {
			if (!ok(x0+pat[i][0].x, y0+pat[i][0].y)) continue;
			if (!ok(x0+pat[i][1].x, y0+pat[i][1].y)) continue;
			if (!ok(x0+pat[i][2].x, y0+pat[i][2].y)) continue;
			kind = 'A' + i;
			break;
		}

		cout << kind << endl;
	}
	return 0;
}

