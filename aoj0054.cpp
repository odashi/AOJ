#include <iostream>
using namespace std;

int main() {
	int a, b, n;
	while (cin >> a >> b >> n) {
		if (a >= b) a %= b;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			a *= 10;
			sum += a/b;
			a %= b;
		}
		cout << sum << endl;
	}
	return 0;
}

