#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int l[10], v1, v2;
	while (scanf("%d,", &l[0]) == 1) {
		for (int i = 1; i < 10; i++)
			scanf("%d,", &l[i]);
		scanf("%d,%d", &v1, &v2);
		int x = 0;
		for (int i = 0; i < 10; i++) {
			x += l[i];
			l[i] *= v1+v2;
		}
		x *= v1;
		for (int i = 0; i < 10; i++) {
			x -= l[i];
			if (x <= 0) {
				cout << i+1 << endl;
				break;
			}
		}
	}
	return 0;
}

