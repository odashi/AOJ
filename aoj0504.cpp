#include <iostream>

using namespace std;

int sum[20000], temp[20000];

int inv(int n, int r, int *target) {
	int m = 1;
	for (int i = 0; i < 2*r; i++) {
		target[i] = m/n;
		m = (m%n)*10;
	}
}

int add(int r) {
	int carry = 0;
	for (int i = 2*r-1; i >= 0; i--) {
		sum[i] += temp[i] + carry;
		carry = sum[i]/10;
		sum[i] %= 10;
	}
}

int main() {
	int n, k, m, r;
	while (cin >> n >> k >> m >> r, n) {
		inv(n, r, sum);
		if (m) {
			for (int i = 1; i <= n-1; i++) {
				inv(n*i, r, temp);
				add(r);
			}
		}

		cout << sum[0] << ".";
		for (int i = 1; i <= r; i++)
			cout << sum[i];
		cout << endl;
	}

	return 0;
}

