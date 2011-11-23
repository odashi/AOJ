#include <iostream>
using namespace std;

char field[500][501];
int ax[26][2], ay[26][2];

bool ok(char a, int bx, int by, int ex, int ey) {
	if (bx == ex) {
		if (by > ey) by ^= ey, ey ^= by, by ^= ey;
		for (int y = by; y <= ey; y++)
			if (field[y][bx] != '.' && field[y][bx] != a) return false;
	} else /* if (by == ey) */ {
		if (bx > ex) bx ^= ex, ex ^= bx, bx ^= ex;
		for (int x = bx; x <= ex; x++)
			if (field[by][x] != '.' && field[by][x] != a) return false;
	}
	return true;
}

int main() {
	int h, w;
	int total = 0;
	cin >> h >> w;
	for (int i = 0; i < 26; i++)
		ax[i][0] = -1;
	for (int y = 0; y < h; y++) {
		cin >> field[y];
		for (int x = 0; x < w; x++) {
			if (field[y][x] != '.') {
				char a = field[y][x] - 'A';
				if (ax[a][0] == -1)
					ax[a][0] = x, ay[a][0] = y, total++;
				else
					ax[a][1] = x, ay[a][1] = y;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (ax[i][0] == ax[i][1] && (ay[i][0] == ay[i][1]+1 || ay[i][0]+1 == ay[i][1]))
			ax[i][0] = -1;
		else if (ay[i][0] == ay[i][1] && (ax[i][0] == ax[i][1]+1 || ax[i][0]+1 == ax[i][1]))
			ax[i][0] = -1;
	}

	int n = total, now;
	do {
		now = n;
		for (int i = 0; i < 26; i++) {
			if (ax[i][0] == -1) continue;
			char a = (char)('A'+i);
			if (
					ok(a, ax[i][0], ay[i][0], ax[i][1], ay[i][0]) &&
					ok(a, ax[i][1], ay[i][0], ax[i][1], ay[i][1])) {
				field[ay[i][0]][ax[i][0]] = field[ay[i][1]][ax[i][1]] = '.';
				ax[i][0] = -1;
				n--;
			} else if (
					ok(a, ax[i][0], ay[i][0], ax[i][0], ay[i][1]) &&
					ok(a, ax[i][0], ay[i][1], ax[i][1], ay[i][1])) {
				field[ay[i][0]][ax[i][0]] = field[ay[i][1]][ax[i][1]] = '.';
				ax[i][0] = -1;
				n--;
			}
		}
	} while (n < now);

	cout << (2*(total-now)) << endl;

	return 0;
}

