#include <stdio.h>

int gcd(int a, int b) {
	int c = a%b;
	while (c) {
		a = b;
		b = c;
		c = a%b;
	}
	return b;
}

int lcm(int a, int b) {
	return (a/gcd(a, b)) * b;
}

int main(void) {
	int a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		printf("%d %d\n", gcd(a, b), lcm(a, b));
	}
	return 0;
}
