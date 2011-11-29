#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int m, n, k = 0, ben = 0, sum = 0;
	while (scanf("%d,%d", &m, &n) == 2) {
		k++;
		ben += m*n;
		sum += n;
	}
	cout << ben << endl;
	cout << (int)(sum / (double)k + 0.5) << endl;
	return 0;
}

