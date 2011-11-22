#include <iostream>
using namespace std;

char horz[5][4+1];
char vert[4][5+1];
int x, y, vx, vy;

void turn_left() {
	int temp = vx;
	vx = vy;
	vy = -temp;
}

void turn_right() {
	int temp = vx;
	vx = -vy;
	vy = temp;
}

inline bool ok(char c) { return (c == '1'); }

bool avail() {
	if (vx == 1) return (x < 4 && ok(horz[y][x]));
	if (vx == -1) return (x > 0 && ok(horz[y][x-1]));
	if (vy == 1) return (y < 4 && ok(vert[y][x]));
	/* if (vy == -1) */ return (y > 0 && ok(vert[y-1][x]));
}

void print() {
	if (vx == 1) cout << "R";
	else if (vx == -1) cout << "L";
	else if (vy == 1) cout << "D";
	else /* if (vy == -1) */ cout << "U";
}

int main() {
	for (int i = 0; i < 4; i++)
		cin >> horz[i] >> vert[i];
	cin >> horz[4];

	x=0, y=0, vx=0, vy=-1;
	do {
		while (!avail()) turn_right();
		print();
		x += vx, y += vy;
		turn_left();
	} while (x != 0 || y != 0);
	cout << endl;
	return 0;
}

