#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f;
	while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) == 6) {
		int det = a*e - b*d;
		int x = e*c - b*f;
		int y = -d*c + a*f;
		printf((x == 0 ? "0.000 " : "%.3f "), x/(double)det);
		printf((y == 0 ? "0.000\n" : "%.3f\n"), y/(double)det);
	}
	return 0;
}
