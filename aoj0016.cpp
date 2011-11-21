#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	double x = 0.0, y = 0.0;
	int deg = 90;
	while (1) {
		int r, t;
		scanf("%d,%d", &r, &t);
		if (!r&&!t)
			break;
		x += r * cos(deg*M_PI/180.0);
		y += r * sin(deg*M_PI/180.0);
		deg -= t;
	}
	printf("%d\n%d\n", (int)x, (int)y);
	return 0;
}

