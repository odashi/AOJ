#include <iostream>
using namespace std;

char floor[100][101];
bool visited[100][100];

int main() {
	int w, h;
	while (cin >> h >> w, h||w) {
		for (int j = 0; j < h; j++) {
			cin >> floor[j];
			for (int i = 0; i < w; i++)
				visited[j][i] = false;
		}

		int x = 0, y = 0;
		while (floor[y][x] != '.' && !visited[y][x]) {
			visited[y][x] = true;
			switch (floor[y][x]) {
				case '>': x++; break;
				case '<': x--; break;
				case 'v': y++; break;
				case '^': y--; break;
			}
		}

		if (visited[y][x])
			cout << "LOOP" << endl;
		else
			cout << x << " " << y << endl;
	}
	return 0;
}

