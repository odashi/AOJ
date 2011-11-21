#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int  right = 0, diamond = 0;
	int a, b, c;
	while (scanf("%d,%d,%d", &a, &b, &c) == 3) {
		if (a*a + b*b == c*c) right++;
		if (a == b) diamond++;
	}
	cout << right << endl << diamond << endl;
	return 0;
}

