#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int k = 1, zeronum = 0;
		while (n/5 >= k) {
			k *= 5;
			zeronum += n/k;
		}
		cout << zeronum << endl;
	}
	return 0;
}

