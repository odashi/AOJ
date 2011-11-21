#include <stdio.h>

int order(int n) {
	int ord = 0;
	while (n > 0) {
		n /= 10;
		ord++;
	}
	return ord;
}

int main(void) {
	int a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		printf("%d\n", order(a+b));
	}
	return 0;
}
