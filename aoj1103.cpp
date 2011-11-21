#include <iostream>
using namespace std;

bool used[4][4];
int rel_x[4], rel_y[4];

int patnum(int depth, int x, int y) {
	if (depth == 0) return 1;

	while (used[y][x]) {
		x++;
		if (x == 4)
			x = 0, y++;
	}

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x+rel_x[i], yy = y+rel_y[i];
		if (xx < 0 || xx >= 4 || yy >= 4 || used[yy][xx])
			continue;
		used[yy][xx] = true;
		int x1 = x+1, y1 = y;
		if (x1 == 4)
			x1 = 0, y1++;
		ret += patnum(depth-1, x1, y1);
		used[yy][xx] = false;
	}
	return ret;
}

int main() {
	while (cin >> rel_x[0], rel_x[0] <= 4) {
		cin >> rel_y[0] >> rel_x[1] >> rel_y[1]
			>> rel_x[2] >> rel_y[2] >> rel_x[3] >> rel_y[3];
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				used[y][x] = false;
		cout << patnum(8, 0, 0) << endl;
	}
	return 0;
}

